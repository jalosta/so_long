# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:40:20 by jalosta-          #+#    #+#              #
#    Updated: 2026/02/10 10:25:20 by jalosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -I includes

LIBFT_SRCS = srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putunbr_fd.c srcs/libft/ft_strlen.c srcs/libft/ft_strchr.c srcs/libft/ft_strdup.c srcs/libft/ft_strjoin.c

$(NAME): srcs/main.c srcs/ft_dprintf/ft_dprintf.c $(LIBFT_SRCS)
	$(CC) $(FLAGS) srcs/main.c srcs/ft_dprintf/ft_dprintf.c $(LIBFT_SRCS) -o $(NAME)
all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re