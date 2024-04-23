/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:20:16 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/21 13:36:10 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/*int	open_file(char *filename, int mode, int *end)
{
	int	fd;

	if (mode == INFILE)
		fd = open(filename, O_RDONLY);
	if (mode == OUTFILE)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (mode == LAST)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(filename);
		close(end[0]);
		close(end[1]);
		exit(1);
	}
	return (fd);
}*/

/*void	last_child_process(char **av, int *end)
{
	int	outfile_fd;

	outfile_fd = open_file(*(av - 1), LAST, end);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	close(end[0]);
	close(end[1]);
//	execute(*(av - 2), envp);
}

void	child_process(char **av, char **envp, int *end)
{
	int	infile_fd;

	infile_fd = open_file(av[1], INFILE, end);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	close(end[0]);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	execute(av[2], envp);
}*/
