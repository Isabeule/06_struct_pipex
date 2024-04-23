/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:19:44 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/21 13:41:04 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	open_file(char *filename, int mode, int *end)
{
	int	fd;

	if (mode == INFILE)
		fd = open(filename, O_RDONLY);
	if (mode == HERE_DOC_FD)
		fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (mode == OUTFILE)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (mode == LAST_FD)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd == -1)
	{
		perror(filename);
		close(end[0]);
		close(end[1]);
		exit(1);
	}
	return (fd);
}
/*
void	set_outfile(int here_doc, int *end, int *fd_out)
{
	if here_doc == 0
	{
		*outfile_fd = open_file(outfile_name, mode outfile, end);
		dup2(*outfile_fd, STDOUT_FILENO);
		close(*outfile_fd);
	}
	else if here_doc == 1
	{
		*outfile_fd = open_file(outfile_name, mode stdout, end);
		dup2(outfile_fd, STDOUT_FILENO);
		close(*outfile_fd);
	}
}

void	fork_last_child(int ac, char **av, char **envp, int *end)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("Error! Fork fails");
	if (pid == 0)
	{
		set_outfile();
		close(end[0]);
		close(end[1]);
		execute(av[ac - 2], envp);
	}
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		close(end[0]);
	}
	while (errno != ECHILD)
		waitpid(pid, NULL, 0);
}*/

void	set_infile(int here_doc, int *end)
{
	if here_doc == 0
	{
		infile_fd = open_file(infile_name, mode infile, end);
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
	else if here_doc == 1
	{
		infile_fd = open_file(infile_name, mode stdin, end);
		dup2(infile_fd, STDIN_FILENO);
		close(infile_fd);
	}
}

void	fork_child1(char **av, char **envp, t_pipex *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_and_exit("Error! Fork fails");
	if (pid == 0)
	{
		set_infile();
		close(data->end[0]);
		dup2(data->end[1], STDOUT_FILENO);
		close(data->end[1]);
		execute(av, envp);
	}
	else
	{
		close(data->end[1]);
		dup2(data->end[0], STDIN_FILENO);
		close(data->end[0]);
	}
	while (errno != ECHILD)
		waitpid(pid, NULL, 0);
}

int	init_pipex(t_pipex *data, int ac, char **av, char **envp)
{
	pid_t	here_doc_pid;

	data->file2 = av[ac -  1];
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (pipe(data->here_doc_end) == -1)
			perror_and_exit("Error! Pipe fails...");
		here_doc_pid = fork();
		if (here_doc_pid == -1)
			perror_and_exit("Error! Fork fails");
		else if (here_doc_pid == 0)
		{
			close(data->here_doc_end[0]);
			connect_heredoc_to_gnl(av[2], data->here_doc_end[1]);
			close(data->here_doc_end[1]);
		}
		else
		{
			close(data->here_doc_end[1]);
			dup2(data->here_doc_end[0], STDIN_FILENO);
			close(data->here_doc_end[0]);
		}
		while (errno != ECHILD)
			waitpid(here_doc_pid, NULL, 0);
		return (data->here_doc_arg = 1);
	}
	if (pipe(data->end[1]) == -1)
		perror_and_exit("Error! Pipe fails...");
	fork_child1(av, envp, data);
	return (data->here_doc_arg = 0);
}

void	check_args(int ac, char **av)
{
	if (ac < 5)
	{
		perror_and_exit(HERE_DOC);
		perror_and_exit(BONUS_ARGS);
	}
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			perror_and_exit(HERE_DOC);
		if (ft_strlen(av[2]) == 0)
			perror_and_exit("Invalid limiter!!!");
	}
}

int	main(int ac, char **av, char **envp)
{
	int	end[2];
	int	i;
	t_pipex	data;

	check_args(ac, av);
	init_pipex(&data, ac, av, envp);
	//printf("%d\n", data.here_doc_arg);
	i = 2 + data.here_doc_arg;
	while (i < ac - 2)
	{
		if (pipe(end) == -1)
			perror_and_exit("Error! Pipe fails...");
		fork_children(ac, av, envp, data);
		i++;
	}
	if (pipe(end) == -1)
		perror_and_exit("Error! Pipe fails...");
	fork_last_child(ac, av, envp, data);
	unlink(".here_doc_tmp");
	return (0);
}
