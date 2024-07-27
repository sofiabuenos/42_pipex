/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:06 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/26 20:07:48 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	fix_vector(t_exec *exec)
{
	if (exec->args[0][0] != '/')
		exec->args[0] = exec->pathname;
}
/**
 * UTILS LEGIT: NO
 * if the command already starts with '/', pathname is complete. ex: /bin/ls
 * 
 * MALLOC AQUI! -> exec->pathname = ft_strdup(exec->args[0]);
 */
void	find_pathname(t_exec *exec, char *cmdx, char **envp)
{
	if (!exec || !cmdx)
		system_error2(exec, "Invalid arguments to find_pathname\n");
	exec->args = ft_split(cmdx, ' ');
	if (exec->args)
	{
		if (exec->args[0] && exec->args[0][0] == '/')
			exec->pathname = ft_strdup(exec->args[0]);
		else
		get_right_path(exec, envp);
	}
	else
		system_error2(exec, "Error splitting cmdx\n");
}


void	run_cmdx(char *cmdx, char **envp)
{
	t_exec	exec;

	ft_bzero(&exec, sizeof(t_exec));
	find_pathname(&exec, cmdx, envp);
	fix_vector(&exec);
	execve(exec.pathname, exec.args, envp);
	// to be conitnued''
}