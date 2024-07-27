/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:25 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/26 20:03:06 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	system_error2(t_exec *exec, char *msg)
{
	if (exec->args)
		free_matrix(exec->args);
	perror(msg);
	exit(EXIT_FAILURE);
}


void	system_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

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