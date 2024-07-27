/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:54 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/26 20:06:26 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


/**
 * dup2(infile, STDIN_FILENO) -> redirects stdin to indile;
 * dup2(fd[1], STDOUT_FILENO  -> redirects stdout to the pipe's writing fd;
 */
void	child_task(char **av, int *fd, char *envp[])
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		system_error("Error opening infile\n");
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(infile);
	run_cmdx(av[2], envp);
}

void	parent_task(char **av, int *fd, char *envp[])
{
	int	outfile;
	outfile = open(av[4], O_WRONLY | O_CREAT, 0644);
	if (outfile == -1)
		system_error("Error opening outfile\n");
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(outfile);
	close(fd[1]);
	run_cmdx(av[3], envp);
}

int	main(int ac, char **av, char *envp[])
{
	int	fd[2];
	int	pid;
	int	status;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			system_error("Error creating pipe\n");
		pid = fork();
		if (pid == -1)
			system_error("Error creating child process\n");
		if (pid == 0)
		{
			child_task(av, fd, envp);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
			parent_task(av, fd, envp);
		}
	}
	else
		ft_putstr_fd("Check parameters. Please use: ./pipex infile cmd1 cmd2 outfile\n", 2);
	return (0);
}
