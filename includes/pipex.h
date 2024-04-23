/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:01:25 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/20 12:26:10 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# define INFILE 0
# define OUTFILE 1

void	child_1_process(char **av, char **envp, int *end);
void	child_2_process(char **av, char **envp, int *end);
void	perror_and_exit(char *str);
void	error_msg(char *message, char *arg);
void	invalid_args_msg_exit(void);
void	execute(char *cmd_av, char **envp);
char	*search_in_envp(char *cmd_args, char **envp);
int		connect_heredoc_to_gnl(char *limiter, int fd);
int		open_file(char *filename, int mode, int *end);

#endif
