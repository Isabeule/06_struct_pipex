/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:04 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/20 12:18:14 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_envp_directories(char **envp)
{
	char	**envp_directories;
	int		i;

	i = 0;
	envp_directories = NULL;
	while (envp[i] != NULL && envp[i][0] != '\0')
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			break ;
		}
		i++;
	}
	if (!envp[i])
		return (NULL);
	envp_directories = ft_split(envp[i] + 5, ':');
	if (!envp_directories)
		return (NULL);
	return (envp_directories);
}

char	*search_in_envp(char *cmd_args, char **envp)
{
	char	*path;
	char	*half_path;
	char	**envp_directories;

	int (i) = 0;
	if (ft_strchr(cmd_args, '/'))
		return (ft_strdup(cmd_args));
	envp_directories = get_envp_directories(envp);
	if (!envp_directories)
		return (NULL);
	while (envp_directories[i])
	{
		half_path = ft_strjoin(envp_directories[i], "/");
		path = ft_strjoin(half_path, cmd_args);
		free(half_path);
		if (access(path, F_OK) == 0)
		{
			free(envp_directories);
			return (path);
		}
		free(path);
		i++;
	}
	ft_freetab(envp_directories);
	return (NULL);
}
