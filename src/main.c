/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:54 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/23 19:39:32 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * dup2(infile, STDIN_FILENO) -> redirects stdin to indile;
 * dup2(fd[1], STDOUT_FILENO  -> redirects stdout to the pipe's writing fd;
 */
void	child_task(char **av, int fd[])
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		system_error("Error opening file\n");
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	//correr o comando
}

int	main(int ac, char **av)
{
	int	fd[2];
	int	pid;
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			system_error("Error opening pipe\n");
		pid = fork();
		if (pid == -1)
			system_error("Error creating child process\n");
		if (pid == 0)
			child_task(av, fd);
		if (pid != 0)
			parent_task();
	}
	else
		ft_putstr_fd("Check parameters. Please use: ./pipex infile cmd1 cmd2 outfile\n", 2);
	return (0);
}
