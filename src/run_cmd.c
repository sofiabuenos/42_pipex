/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:45 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/17 16:25:21 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * concatenates the file name to its potential path
 * checks if it is an executable path, if so finally sets pathname.
 */
void	find_and_set_executable_path(t_pipex *pipex)
{
	int		i;
	char	*path_tmp;

	path_tmp = NULL;
	i = -1;
	while (pipex->exec->dirs[++i])
	{
		path_tmp = concatenate(pipex, pipex->exec->dirs[i]);
		if (access(path_tmp, X_OK) == 0)
		{
			pipex->exec->pathname = ft_strdup(path_tmp);
			free(path_tmp);
			return ;
		}
		free(path_tmp);
	}
	pipex->exec->pathname = ft_strdup(pipex->exec->args[0]);
}

/**
 * iterates over envp and finds path
 * splits path and save all directories in exec->dirs
 * calls find_and_set_executable_path
 */
void	get_absolute_path(t_pipex *pipex, char **envp)
{
	int	found;
	int	i;

	found = 0;
	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			found = 1;
			break ;
		}
	}
	if (found == 1)
	{
		pipex->exec->dirs = ft_split(envp[i] + 5, ':');
		find_and_set_executable_path(pipex);
	}
	else
		pipex->exec->pathname = ft_strdup(pipex->exec->args[0]);
}

/**
 * Splits the command and saves it in args
 * checks if the command is an absolute path and sets path-name
 * if it isnt an absolute path calls get_absolute_path
 */
void	find_pathname(t_pipex *pipex, char *cmd_i, char **envp)
{
	if (!pipex->exec || !pipex->cmd)
		system_error(pipex, "Invalid arguments to find_pathname");
	if (cmd_i[0] == '\0')
	{
		pipex->status = 127;
		system_error(pipex, "Command not found");
	}
	pipex->exec->args = ft_split(cmd_i, ' ');
	if (pipex->exec->args)
	{
		if (pipex->exec->args[0] && (find_slash(pipex->exec->args[0]) == 0))
			pipex->exec->pathname = ft_strdup(pipex->exec->args[0]);
		else
			get_absolute_path(pipex, envp);
	}
	else
		system_error(pipex, "Error splitting cmdx");
}

/**
 * initiates exec struct with all execve commands and runs it.
 */
void	run_cmdx(t_pipex *pipex, char *cmd_i, char **envp)
{
	t_exec	exec;

	ft_bzero(&exec, sizeof(t_exec));
	pipex->exec = &exec;
	find_pathname(pipex, cmd_i, envp);
	if (execve(exec.pathname, exec.args, envp) == -1)
	{
		pipex->status = 127;
		system_error(pipex, "Error executing command");
	}
}
