# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isapavad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 19:17:26 by isapavad          #+#    #+#              #
#    Updated: 2024/03/20 12:48:52 by isapavad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = pipex_bonus
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
HEADER = ./includes/pipex.h
BONUS_HEADER = ./includes/pipex_bonus.h

MANDATORY_SRC = ./mandatory/pipex.c ./mandatory/error.c ./mandatory/execute.c \
./mandatory/processes.c ./mandatory/envp.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

BONUS_SRC = ./bonus/connect_heredoc_to_gnl_bonus.c ./bonus/envp_bonus.c \
./bonus/error_bonus.c ./bonus/execute_bonus.c ./bonus/pipex_bonus.c \
./bonus/processes_bonus.c \
./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJ)
	@make -C ./libft
	@make -C ./ft_printf
	$(CC) $(CFLAGS) -I $(HEADER) -o $(NAME) $(MANDATORY_OBJ) $(LIBFT) $(FT_PRINTF)

$(BONUS_NAME): $(BONUS_OBJ)
	@make -C ./libft
	@make -C ./ft_printf
	$(CC) $(CFLAGS) -I $(BONUS_HEADER) -o $(BONUS_NAME) $(BONUS_OBJ)  $(LIBFT) $(FT_PRINTF)

clean:
	$(RM) $(MANDATORY_OBJ) $(BONUS_OBJ)
	@make clean -C ./libft
	@make clean -C ./ft_printf

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(RM) $(LIBFT) $(FT_PRINTF)

re: clean all

.PHONY: all clean fclean re
