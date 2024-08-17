/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:36:20 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/17 16:19:33 by sbueno-s         ###   ########.fr       */
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
typedef struct s_fds
{
	int	fd[2];
}		t_fds;

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
typedef struct s_pipex
{
	t_exec		*exec;
	t_fds		*p_fds;
	pid_t		*pids;
	char		**cmd;
	int			num_cmd;
	int			status;
}				t_pipex;

/*PIPEX*/
void	init_pipex(t_pipex *pipex, int ac);
void	commands_init(t_pipex *pipex, char **av);
void	create_pipes(t_pipex *pipex);
void	alloc_pids_arr(t_pipex *pipex);
void	fork_and_execute(t_pipex *pipex, int ac, char **av, char *envp[]);
/*REDIRECT AND WAIT*/
void	close_fds(t_pipex *pipex);
void	infile_redirect(t_pipex *pipex, char **av);
void	outfile_redirect(t_pipex *pipex, int ac, char **av, int i);
void	std_redirect(t_pipex *pipex, int i);
int		wait_for_child(t_pipex *pipex);
/*RUN CMD*/
void	run_cmdx(t_pipex *pipex, char *cmd_i, char **envp);
/*EXEC_UTILS*/
void	get_absolute_path(t_pipex *pipex, char **envp);
int		find_slash(char *str);
char	*concatenate(t_pipex *pipex, char *dir);
/*ERRORS*/
void	ft_error(char *msg);
void	system_error(t_pipex *pipex, char *msg);
void	free_matrix(char **matrix);
void	free_mem(t_pipex *pipex);

#endif