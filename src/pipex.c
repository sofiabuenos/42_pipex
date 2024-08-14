/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:06 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/31 16:17:59 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	fix_vector(t_exec *exec)
{
	if (find_slash(exec->args[0]) == 1)
		exec->args[0] = exec->pathname;
}
/**
 * UTILS LEGIT: NO
 * if the command already starts with '/', pathname is complete. ex: /bin/ls
 * 
 * MALLOC AQUI! -> exec->pathname = ft_strdup(exec->args[0]);
 * MALLOC AQUI! -> exec->args = ft_split(cmdx, ' ');
 */
void	find_pathname(t_exec *exec, char *cmdx, char **envp)
{
	if (!exec || !cmdx)
		system_error2(exec, "Invalid arguments to find_pathname");
	exec->args = ft_split(cmdx, ' ');
	if (exec->args)
	{
		if (exec->args[0] && (find_slash(exec->args[0]) == 0))
			exec->pathname = ft_strdup(exec->args[0]);
		else
		get_right_path(exec, envp);
	}
	else
		system_error2(exec, "Error splitting cmdx");
}


void	run_cmdx(char *cmdx, char **envp)
{
	t_exec	exec;

	ft_bzero(&exec, sizeof(t_exec));
	find_pathname(&exec, cmdx, envp);
	//fix_vector(&exec);
	if(execve(exec.pathname, exec.args, envp)== -1)
		system_error2(&exec, "Error executing command");
}