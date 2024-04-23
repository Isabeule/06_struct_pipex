/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_heredoc_to_gnl_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:15:10 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/21 09:59:26 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	connect_heredoc_to_gnl(char *limiter, int fd)
{
	char	*str;

	while (1)
	{
		ft_printf("> ");
		str = get_next_line(0);
		if (!str)
		{
			error_msg("Missing limiter: ", limiter);
			break ;
		}
		if (ft_strncmp(str, limiter, (int)ft_strlen(limiter)) == 0)
			break ;
		write(fd, str, ft_strlen(str));
		free(str);
	}
	if (str)
		free(str);
	return (1);
}