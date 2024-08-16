/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:45 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/15 18:42:48 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * UTILS LEGIT: YES
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
 * UTILS LEGIT: YES
 */
void	get_right_path(t_pipex *pipex, char **envp)
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
		pipex->exec->pathname = pipex->exec->args[0];
}

/**
 * UTILS LEGIT: NO
 * if the command already starts with '/', pathname is complete. ex: /bin/ls
 * MALLOC AQUI! -> exec->pathname = ft_strdup(exec->args[0]);
 * MALLOC AQUI! -> exec->args = ft_split(cmdx, ' ');
 */
void	find_pathname(t_pipex *pipex, char *cmd_i, char **envp)
{
	if (!pipex->exec || !pipex->cmd)
		system_error(pipex, "Invalid arguments to find_pathname");
	pipex->exec->args = ft_split(cmd_i, ' ');
	if (pipex->exec->args)
	{
		if (pipex->exec->args[0] && (find_slash(pipex->exec->args[0]) == 0))
			pipex->exec->pathname = ft_strdup(pipex->exec->args[0]);
		else
			get_right_path(pipex, envp);
	}
	else
		system_error(pipex, "Error splitting cmdx");
}

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
