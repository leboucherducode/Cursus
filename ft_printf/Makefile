# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeschwar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 09:54:52 by jeschwar          #+#    #+#              #
#    Updated: 2024/11/05 14:28:37 by jeschwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        = utils.c ft_print_pointer.c ft_printf.c

OBJS        = $(SRCS:.c=.o)

CC          = cc

CFLAGS      = -Wall -Wextra -Werror

NAME        = libftprintf.a

all:        $(NAME)

$(NAME):    $(OBJS)
			ar rsc $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:     clean
			rm -f $(NAME)

re:         fclean all

.PHONY:     all clean fclean re bonus
