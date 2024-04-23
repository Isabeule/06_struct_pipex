/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isapavad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:45 by isapavad          #+#    #+#             */
/*   Updated: 2024/03/20 12:53:35 by isapavad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

# define HERE_DOC "Usage: ./pipex_bonus here_doc <lim> CMD1 CMD2 CMDn file.\n"
# define BONUS_ARGS "Usage: ./pipex_bonus file1 CMD1 CMD2 CMDn file2."
# define HERE_DOC_ARG 1
# define INFILE 0
# define OUTFILE 1
# define HERE_DOC_FD 2
# define LAST_FD 3

typedef struct s_pipex
{
    int here_doc_arg;
    int here_doc_end[2];
    int end[2];
    int infile_fd;
    int outfile_fd;
    int i;
    char    *file1;
    char    *file2;
}               t_pipex;


void	child_process(char **av, int *end);
void	last_child_process(int ac, char **av, char **envp, int *end);
void	perror_and_exit(char *str);
void	error_msg(char *message, char *arg);
void	invalid_args_msg_exit(void);
void	execute(char *cmd_av, char **envp);
char	*search_in_envp(char *cmd_args, char **envp);
int		connect_heredoc_to_gnl(char *limiter, int fd);
int		open_file(char *filename, int mode, int *end);

#endif
