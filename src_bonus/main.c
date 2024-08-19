/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:54 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/17 18:10:26 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;

	if (ac < 5)
		ft_error("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	else
	{
		init_pipex(&pipex, ac);
		commands_init(&pipex, av);
		create_pipes(&pipex);
		alloc_pids_arr(&pipex);
		fork_and_execute(&pipex, ac, av, envp);
	}
	return (0);
}
