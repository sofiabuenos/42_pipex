/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:25 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/16 20:54:36 by sbueno-s         ###   ########.fr       */
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

void	free_mem(t_pipex *pipex)
{
	if (pipex->cmd)
		free_matrix(pipex->cmd);
	if (pipex->p_fds)
	{
		free(pipex->p_fds);
		pipex->p_fds = NULL;
	}
	if (pipex->pids)
		free(pipex->pids);
}

void	system_error(t_pipex *pipex, char *msg)
{
	int	exitstatus;

	exitstatus = pipex->status;
	free_mem(pipex);
	if (pipex->exec && pipex->exec->args)
		free_matrix(pipex->exec->args);
	if (pipex->exec && pipex->exec->dirs)
		free_matrix(pipex->exec->dirs);
	if (pipex->exec && pipex->exec->pathname)
		free(pipex->exec->pathname);
	perror(msg);
	exit(exitstatus);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
