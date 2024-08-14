/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:16:56 by sofiabueno        #+#    #+#             */
/*   Updated: 2024/08/14 19:20:06 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_fds(t_cmdx *cmds)
{
	int	i;

	i = -1;
	while (++i < cmds->num_cmd - 1)
	{
		close(cmds->p_fds[i].fd[0]);
		close(cmds->p_fds[i].fd[1]);
	}
}

void	infile_redirect(t_cmdx *cmds, char **av)
{
	int	infile;

	if (!av[1][0])
	{
		ft_putstr_fd("No Infile name", 2);
		exit(1);
	}
	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		system_error("Error opening infile");
	dup2(infile, STDIN_FILENO);
	dup2(cmds->p_fds[0].fd[1], STDOUT_FILENO);
	close(infile);
}

void	outfile_redirect(t_cmdx *cmds, int ac, char **av, int i)
{
	int	outfile;

	if (!av[ac - 1][0])
	{
		ft_putstr_fd("No Outfile name", 2);
		exit(1);
	}
	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		system_error2 (cmds, "Error opening file");
	dup2(cmds->p_fds[i - 1].fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	std_redirect(t_cmdx *cmds, int i)
{
	dup2(cmds->p_fds[i - 1].fd[0], STDIN_FILENO);
	dup2(cmds->p_fds[i].fd[1], STDOUT_FILENO);
}

int	wait_for_child(t_cmdx *cmds)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < cmds->num_cmd)
	{
		waitpid(cmds->pids[i], &wstatus, 0);
	}
	if (WIFEXITED(wstatus))
		return(WEXITSTATUS(wstatus));
	return(0) ;
}

