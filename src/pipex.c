/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:06 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/14 20:35:17 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * Spawns as many child processes as the number of commands.
 * Each child process executes one command via run_cmdx().
 * Manages input/output redirection based on command position.
 */
void	fork_and_execute(t_cmdx *cmds, int ac, char **av, char *envp[])
{
	int	i;
	int	child_status;

	i = -1;
	while (++i < cmds->num_cmd)
	{
		cmds->pids[i] = fork();
		if (cmds->pids[i] == -1)
			system_error2(cmds, "Fork");
		if (cmds->pids[i] == 0)
		{
			if (i == 0)
				infile_redirect(cmds, av);
			else if (i == cmds->num_cmd -1)
				outfile_redirect(cmds, ac, av, i);
			else
				std_redirect(cmds, i);
			close_fds(cmds);
			run_cmdx(cmds, cmds->cmd[i], envp);
		}
	}
	close_fds(cmds);
	child_status = wait_for_child(cmds);
	free_mem(cmds);
	exit(child_status);
}

void	alloc_pids_arr(t_cmdx *cmds)
{
	cmds->pids = (pid_t *)malloc(sizeof(pid_t) * cmds->num_cmd);
	if (!cmds->pids)
		system_error2(cmds, "Memory allocation issue - pids array");
}

/**
 * Allocates memory to an array of t_pipe_fds structures.
 * Each t_pipe_fds contains an array of 2 integers (file descriptors).
 */
void	create_pipes(t_cmdx *cmds)
{
	int	i;

	cmds->p_fds = (t_pipe_fds *)malloc((cmds->num_cmd - 1) * \
			(sizeof(t_pipe_fds)));
	if (!cmds->p_fds)
		system_error2(cmds, "Memory allocation issue - pipe fds");
	i = -1;
	while (++i < cmds->num_cmd -1)
	{
		if (pipe(cmds->p_fds[i].fd) == -1)
			system_error2(cmds, "Error creating pipe");
	}
}

/**
 * saves a copy of each command passed as argument in cmds->cmd -
 * an array of strings.
 */
void	commands_init(t_cmdx *cmds, int ac, char **av)
{
	int		i;

	cmds->status = 1;
	cmds->num_cmd = ac - 3;
	cmds->cmd = (char **)malloc(sizeof(char *) * (cmds->num_cmd + 1));
	if (!cmds->cmd)
		system_error("Memory allocation issue");
	i = -1;
	while (++i < cmds->num_cmd)
	{
		cmds->cmd[i] = ft_strdup(av[i + 2]);
		if (!cmds->cmd[i])
		{
			free_matrix(cmds->cmd);
			system_error("Cmd malloc issue");
		}
	}
	cmds->cmd[cmds->num_cmd] = NULL;
}

void	run_pipex(int ac, char **av, char *envp[])
{
	t_cmdx	cmds;

	ft_bzero(&cmds, sizeof(t_cmdx));
	commands_init(&cmds, ac, av);
	create_pipes(&cmds);
	alloc_pids_arr(&cmds);
	fork_and_execute(&cmds, ac, av, envp);
}
