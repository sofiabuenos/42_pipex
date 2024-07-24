/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:19:06 by sbueno-s          #+#    #+#             */
/*   Updated: 2024/07/24 18:23:35 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	execute_cmd(char *cmd)
{
	char	**tmp;

	tmp = ft_split(cmd, ' ');
	if (tmp != NULL)
	{
		
	}
	else
		system_error("Error splitting cmd\n");
}


/**
 * dup2(infile, STDIN_FILENO) -> redirects stdin to indile;
 * dup2(fd[1], STDOUT_FILENO  -> redirects stdout to the pipe's writing fd;
 */
void	child_task(char **av, int fd[])
{
	int	infile;
	//char	**cmd1;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		system_error("Error opening infile\n");
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	//correr o comando 1
	close(fd[0]);
	close(infile);
	/* cmd1 = ft_split(av[2], ' ');  // Divida o comando em palavras separadas
    if (cmd1 == NULL)
        system_error("Error splitting cmd1\n");
    execvp(cmd1[0], cmd1);  // Execute o comando
    ft_free_matrix(cmd1);  // Libere a memória alocada por ft_split */
}

void	parent_task(char **av, int fd[])
{
	int	outfile;
	// char	**cmd2;

	outfile = open(av[4], O_WRONLY | O_CREAT, 0644);
	if (outfile == -1)
		system_error("Error opening outfile\n");
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	// correr o comando 2
	close(outfile);
	close(fd[1]);
	/* cmd2 = ft_split(av[3], ' ');  // Divida o comando em palavras separadas
    if (cmd2 == NULL)
        system_error("Error splitting cmd2\n");
    execvp(cmd2[0], cmd2);  // Execute o comando
    ft_free_matrix(cmd2);  // Libere a memória alocada por ft_split */
}