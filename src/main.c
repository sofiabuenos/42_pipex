/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:54 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/20 17:00:56 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av)
{
	int	fd[2];
	if (ac != 5)
		quit_pipex("Check parameters. Please use: ./pipex infile cmd1 cmd2 outfile");
	if (pipe(fd) == -1)
		quit_pipex("Error opening pipe");
}
