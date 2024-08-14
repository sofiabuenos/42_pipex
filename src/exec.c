/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:45 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/13 18:59:01 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * UTILS LEGIT: NO
 * if the command already starts with '/', pathname is complete. ex: /bin/ls
 * MALLOC AQUI! -> exec->pathname = ft_strdup(exec->args[0]);
 * MALLOC AQUI! -> exec->args = ft_split(cmdx, ' ');
 */
void	find_pathname(t_cmdx *cmds, char *cmd_i, char **envp)
{
	if (!cmds->exec || !cmds->cmd)
		system_error2(cmds, "Invalid arguments to find_pathname");
	cmds->exec->args = ft_split(cmd_i, ' ');
	if (cmds->exec->args)
	{
		if (cmds->exec->args[0] && (find_slash(cmds->exec->args[0]) == 0))
			cmds->exec->pathname = ft_strdup(cmds->exec->args[0]);
		else
			get_right_path(cmds, envp);
	}
	else
		system_error2(cmds, "Error splitting cmdx");
}

void	run_cmdx(t_cmdx *cmds, char *cmd_i, char **envp)
{
	t_exec	exec;

	ft_bzero(&exec, sizeof(t_exec));
	cmds->exec = &exec;
	find_pathname(cmds, cmd_i, envp);
	if (execve(exec.pathname, exec.args, envp) == -1)
		system_error2(cmds, "Error executing command");
}
