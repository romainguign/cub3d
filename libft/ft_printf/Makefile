# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 14:44:38 by roguigna          #+#    #+#              #
#    Updated: 2023/11/30 17:42:45 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################VARIABLES############################

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

######################## SOURCES ##############################

SRC		= ft_printf.c ft_utils.c ft_putnbr_base.c

OBJ		= ${SRC:.c=.o}

########################  RULES  ##############################

all: ${NAME}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

.c.o:
	@${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	@rm -f ${OBJ} 

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

