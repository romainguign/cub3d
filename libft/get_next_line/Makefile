# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 18:03:40 by roguigna          #+#    #+#              #
#    Updated: 2023/11/30 18:38:03 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################VARIABLES############################

NAME		= gnl.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

######################## SOURCES ##############################

SRC			= get_next_line.c get_next_line_bonus.c \
			get_next_line_utils.c

OBJ			= ${SRC:.c=.o}

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