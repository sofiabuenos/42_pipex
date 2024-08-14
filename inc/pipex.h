/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:36:20 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/13 18:49:45 by sofiabueno       ###   ########.fr       */
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

/*Structure which contains an array of integers - a pipe's couple of fds*/
typedef struct s_pipe_fds
{
	int	fd[2];
}		t_pipe_fds;

/*Structure which keeps execve's arguments*/
typedef struct s_exec
{
	char	*pathname;
	char	**args;
	char	**dirs;
}			t_exec;

/**
 * *exec   = pointer to a structure which contains the arguments to execve;
 * *p_fds  = pointer to an array of spipe_fds structures;
 * **cmd   = arr that contains all the commands passed as the program arguments;
 * num_cmd = number of commands;
 */
typedef struct s_cmdx
{
	t_exec		*exec;
	t_pipe_fds	*p_fds;
	char		**cmd;
	int			num_cmd;
}				t_cmdx;

/*PIPEX*/
void	run_pipex(int ac, char **av, char *envp[]);
/*PIPEX_UTILS*/
void	close_fds(t_cmdx *cmds);
void	infile_redirect(t_cmdx *cmds, char **av);
void	outfile_redirect(t_cmdx *cmds, int ac, char **av, int i);
void	std_redirect(t_cmdx *cmds, int i);
void	wait_for_child(t_cmdx *cmds);
/*EXEC*/
void	run_cmdx(t_cmdx *cmds, char *cmd_i, char **envp);
/*EXEC_UTILS*/
void	get_right_path(t_cmdx *cmds, char **envp);
int		find_slash(char *str);
/*ERRORS*/
void	system_error(char *msg);
void	system_error2(t_cmdx *cmds, char *msg);
void	free_matrix(char **matrix);

#endif