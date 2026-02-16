# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalosta- <jalosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 14:40:20 by jalosta-          #+#    #+#              #
#    Updated: 2026/02/16 17:04:18 by jalosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -I includes

LIBFT_SRCS = srcs/utils/libft/ft_putchar_fd.c srcs/utils/libft/ft_itoa.c srcs/utils/libft/ft_putstr_fd.c srcs/utils/libft/ft_putnbr_fd.c srcs/utils/libft/ft_strlen.c srcs/utils/libft/ft_strdup.c srcs/utils/libft/ft_strjoin.c srcs/utils/libft/ft_strchr.c srcs/utils/libft/ft_strncmp.c srcs/utils/libft/ft_substr.c srcs/utils/libft/ft_lstdelone.c srcs/utils/libft/ft_lstclear.c srcs/utils/libft/ft_lstnew.c srcs/utils/libft/ft_lstadd_back.c srcs/utils/libft/ft_lstlast.c srcs/utils/libft/ft_lstsize.c srcs/utils/libft/ft_strlcpy.c

DPRINTF_SRCS = srcs/utils/ft_dprintf/ft_dprintf.c

GNL_SRCS = srcs/utils/get_next_line_trimmed/get_next_line_trimmed.c

SRCS = srcs/main.c srcs/parser.c srcs/checkpoints.c $(DPRINTF_SRCS) $(GNL_SRCS) $(LIBFT_SRCS)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re