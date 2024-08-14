/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:25 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/13 18:59:36 by sofiabueno       ###   ########.fr       */
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

void	system_error2(t_cmdx *cmds, char *msg)
{
	if (cmds->cmd)
		free_matrix(cmds->cmd);
	if (cmds->p_fds)
	{
		free(cmds->p_fds);
		cmds->p_fds = NULL;
	}
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
