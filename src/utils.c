/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:16:00 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/07/27 17:04:36 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * UTILS LEGIT: YES
 * Verificar se nesse caso usaria mesmo system error ou outra forma de encerrar o programa
 */
char *concatenate(t_exec *exec, char *dir)
{
	char *temp;
	char *path_name;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		system_error2(exec, "join failed");
	path_name = ft_strjoin(temp, exec->args[0]);
	free(temp);
	if (!path_name)
		system_error2(exec, "join failed");
	return path_name;
}

/**
 * UTILS LEGIT: YES
 */
void	find_and_set_executable_path(t_exec *exec)
{
	int		i;
	char	*path_tmp;

	path_tmp = NULL;
	i = -1;
	while (exec->dirs[++i])
	{
		path_tmp = concatenate(exec, exec->dirs[i]);
		if (access(path_tmp, X_OK) == 0)
		{
			exec->pathname = ft_strdup(path_tmp);
			free(path_tmp);
			return; 
		}
	}
	if (path_tmp)
		free(path_tmp); 
	system_error2(exec, "No valid pathname found\n");
}

/**
 * UTILS LEGIT: YES
 */
void	get_right_path(t_exec *exec, char **envp)
{
	int	found;
	int	i;

	found = 0;
	i = -1;
	while(envp[++i]) // verificar se env n~ao ' nulo env -i ./pipex ...
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		exec->dirs = ft_split(envp[i] + 5, ':');
		find_and_set_executable_path(exec);
	}
	else
		system_error2(exec, "Variable PATH not found\n"); // deixar a execve tentar executar o comando com pathname = argv[0]
	
}
