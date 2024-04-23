/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:16:09 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/20 12:16:16 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	perror_and_exit(char *str)
{
	error_msg(str, NULL);
	exit(EXIT_FAILURE);
}

void	error_msg(char *message, char *arg)
{
	write(2, message, ft_strlen(message));
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
}

void	if_invalid_cmd_args(char **cmd_args)
{
	if (!cmd_args[0])
	{
		error_msg("Error!!! Command not found1: %s", cmd_args[0]);
		exit(EXIT_FAILURE);
	}
}
