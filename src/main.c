/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiabueno <sofiabueno@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:35:54 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/08/13 18:59:18 by sofiabueno       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char *envp[])
{
	if (ac < 5)
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	else
		run_pipex(ac, av, envp);
	return (0);
}
