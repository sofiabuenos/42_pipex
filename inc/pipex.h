/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:36:20 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/26 20:09:53 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/* Stucts */

typedef struct s_exec
{
	char	*pathname;
	char	**args;
	char	**dirs;
}			t_exec;

void	system_error(char *msg);
void	system_error2(t_exec *exec, char *msg);
void	child_task(char **av, int *fd, char *envp[]);
void	parent_task(char **av, int *fd, char *envp[]);
void	run_cmdx(char *cmdx, char **envp);
void	get_right_path(t_exec *exec, char **envp);
void	free_matrix(char **matrix);
#endif