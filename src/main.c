/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:54 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/24 18:19:39 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char *const envp[])
{
	int	fd[2];
	int	pid;
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			system_error("Error creating pipe\n");
		pid = fork();
		if (pid == -1)
			system_error("Error creating child process\n");
		if (pid == 0)
			child_task(av, fd, envp);
		if (pid != 0)
			parent_task(av, fd, envp);
	}
	else
		ft_putstr_fd("Check parameters. Please use: ./pipex infile cmd1 cmd2 outfile\n", 2);
	return (0);
}
