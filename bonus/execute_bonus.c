/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:19:15 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/20 12:19:22 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	if_invalid_path(char *cmd_path, char **cmd_args, char **envp)
{
	int	err;

	if (execve(cmd_path, cmd_args, envp) == -1)
	{
		if (errno == EACCES)
		{
			err = errno;
			perror(cmd_args[0]);
			errno = err;
			exit(126);
		}
		write(2, cmd_args[0], ft_strlen(cmd_args[0]));
		write(2, ": command not found.\n", 21);
		exit(EXIT_FAILURE);
	}
}

void	execute(char *cmd_av, char **envp)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(cmd_av, ' ');
	if (!cmd_args)
		perror_and_exit("Malloc fails: see cmd_args...");
	path = search_in_envp(cmd_args[0], envp);
	if_invalid_path(path, cmd_args, envp);
	ft_freetab(cmd_args);
	exit(0);
}
