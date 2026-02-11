# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:40:20 by jalosta-          #+#    #+#              #
#    Updated: 2026/02/11 15:44:41 by jalosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -I includes

LIBFT_SRCS = srcs/libft/ft_putchar_fd.c srcs/libft/ft_itoa.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strlen.c srcs/libft/ft_strdup.c srcs/libft/ft_strjoin.c srcs/libft/ft_strchr.c srcs/libft/ft_substr.c

DPRINTF_SRCS = srcs/ft_dprintf/ft_dprintf.c

GNL_SRCS = srcs/get_next_line/get_next_line.c

SRCS = srcs/main.c $(DPRINTF_SRCS) $(GNL_SRCS) $(LIBFT_SRCS)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re