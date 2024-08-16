/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:06 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/16 17:39:54 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * Spawns as many child processes as the number of commands.
 * Each child process executes one command via run_cmdx().
 * Manages input/output redirection based on command position.
 */
void	fork_and_execute(t_pipex *pipex, int ac, char **av, char *envp[])
{
	int	i;
	int	child_status;

	i = -1;
	while (++i < pipex->num_cmd)
	{
		pipex->pids[i] = fork();
		if (pipex->pids[i] == -1)
			system_error(pipex, "Fork");
		if (pipex->pids[i] == 0)
		{
			if (i == 0)
				infile_redirect(pipex, av);
			else if (i == pipex->num_cmd -1)
				outfile_redirect(pipex, ac, av, i);
			else
				std_redirect(pipex, i);
			close_fds(pipex);
			run_cmdx(pipex, pipex->cmd[i], envp);
		}
	}
	close_fds(pipex);
	child_status = wait_for_child(pipex);
	free_mem(pipex);
	exit(child_status);
}

void	alloc_pids_arr(t_pipex *pipex)
{
	pipex->pids = (pid_t *)malloc(sizeof(pid_t) * pipex->num_cmd);
	if (!pipex->pids)
		system_error(pipex, "Memory allocation issue - pids array");
}

/**
 * Allocates memory to an array of t_fds structures.
 * Each t_fds contains an array of 2 integers (file descriptors).
 */
void	create_pipes(t_pipex *pipex)
{
	int	i;

	pipex->p_fds = (t_fds *)malloc((pipex->num_cmd - 1) * \
			(sizeof(t_fds)));
	if (!pipex->p_fds)
		system_error(pipex, "Memory allocation issue - pipe fds");
	i = -1;
	while (++i < pipex->num_cmd -1)
	{
		if (pipe(pipex->p_fds[i].fd) == -1)
			system_error(pipex, "Error creating pipe");
	}
}

/**
 * saves a copy of each command passed as argument in pipex->cmd -
 * an array of strings.
 */
void	commands_init(t_pipex *pipex, char **av)
{
	int		i;

	pipex->cmd = (char **)malloc(sizeof(char *) * (pipex->num_cmd + 1));
	if (!pipex->cmd)
		system_error(pipex, "Memory allocation issue");
	i = -1;
	while (++i < pipex->num_cmd)
	{
		pipex->cmd[i] = ft_strdup(av[i + 2]);
		if (!pipex->cmd[i])
		{
			free_matrix(pipex->cmd);
			system_error(pipex, "Cmd malloc issue");
		}
	}
	pipex->cmd[pipex->num_cmd] = NULL;
}

void	init_pipex(t_pipex *pipex, int ac)
{
	ft_bzero(pipex, sizeof(t_pipex));
	pipex->status = 1;
	pipex->num_cmd = ac - 3;
}
