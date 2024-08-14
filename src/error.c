/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:25 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/14 16:00:28 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	free_mem(t_cmdx *cmds)
{
	if (cmds->cmd)
		free_matrix(cmds->cmd);
	if (cmds->p_fds)
	{
		free(cmds->p_fds);
		cmds->p_fds = NULL;
	}
	if (cmds->pids)
		free(cmds->pids);
}

void	system_error2(t_cmdx *cmds, char *msg)
{
	free_mem(cmds);
	if (cmds->exec && cmds->exec->args)
		free_matrix(cmds->exec->args);
	if (cmds->exec && cmds->exec->dirs)
		free_matrix(cmds->exec->dirs);
	if (cmds->exec && cmds->exec->pathname)
		free(cmds->exec->pathname);
	perror(msg);
	exit(EXIT_FAILURE);
}

void	system_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
