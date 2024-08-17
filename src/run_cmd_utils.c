/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:16:00 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/17 16:11:37 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * 
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
