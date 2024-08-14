/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:16:00 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/14 20:37:22 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * UTILS LEGIT: YES
 * Verificar se nesse caso usaria mesmo system error ou outra forma 
 * de encerrar o programa
 */
char	*concatenate(t_cmdx *cmds, char *dir)
{
	char	*temp;
	char	*path_name;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		system_error2(cmds, "join failed");
	path_name = ft_strjoin(temp, cmds->exec->args[0]);
	free(temp);
	if (!path_name)
		system_error2(cmds, "join failed");
	return (path_name);
}

/**
 * UTILS LEGIT: YES
 */
void	find_and_set_executable_path(t_cmdx *cmds)
{
	int		i;
	char	*path_tmp;

	path_tmp = NULL;
	i = -1;
	while (cmds->exec->dirs[++i])
	{
		path_tmp = concatenate(cmds, cmds->exec->dirs[i]);
		if (access(path_tmp, X_OK) == 0)
		{
			cmds->exec->pathname = ft_strdup(path_tmp);
			free(path_tmp);
			return ;
		}
		free(path_tmp);
	}
	cmds->exec->pathname = ft_strdup(cmds->exec->args[0]);
}

/**
 * UTILS LEGIT: YES
 */
void	get_right_path(t_cmdx *cmds, char **envp)
{
	int	found;
	int	i;

	found = 0;
	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			found = 1;
			break ;
		}
	}
	if (found == 1)
	{
		cmds->exec->dirs = ft_split(envp[i] + 5, ':');
		find_and_set_executable_path(cmds);
	}
	else
		cmds->exec->pathname = cmds->exec->args[0];
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
