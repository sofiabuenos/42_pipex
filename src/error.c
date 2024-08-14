/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:25 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/31 16:03:58 by sbueno-s         ###   ########.fr       */
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
void	system_error2(t_exec *exec, char *msg)
{
	if (exec->args)
		free_matrix(exec->args);
	if (exec->dirs)
		free_matrix(exec->dirs);
	perror(msg);
	exit(EXIT_FAILURE);
}


void	system_error(char *msg)
{
	//ft_printf("errno = %s\n", strerror(errno));
	perror(msg);
	exit(EXIT_FAILURE);
}
