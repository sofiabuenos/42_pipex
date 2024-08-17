/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:16:00 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/15 18:45:24 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * UTILS LEGIT: YES
 * Verificar se nesse caso usaria mesmo system error ou outra forma 
 * de encerrar o programa
 */
char	*concatenate(t_pipex *pipex, char *dir)
{
	char	*temp;
	char	*path_name;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		system_error(pipex, "join failed");
	path_name = ft_strjoin(temp, pipex->exec->args[0]);
	free(temp);
	if (!path_name)
		system_error(pipex, "join failed");
	return (path_name);
}

int	find_slash(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '/')
			return (0);
	}
	return (1);
}
