# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 18:13:11 by roguigna          #+#    #+#              #
#    Updated: 2024/07/11 17:57:34 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############################  VARIABLES  ###################################

NAME 			= libft.a

FT_PRINTF		= ft_printf

GNL				= get_next_line

OBJ 			= ${SRCDIRSRC:.c=.o}

CC 				= cc

CFLAGS 			= -Wall -Wextra -Werror

INCLUDE			= includes

##############################  COLORS  ###################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


##############################  SOURCES  #####################################

SRC_DIR			= sources/

OBJ_DIR			= 	obj/

SRC_FILES		=	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
					ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove \
					ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr \
					ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr \
					ft_atoi ft_strdup ft_calloc ft_substr ft_strjoin \
					ft_strtrim ft_putchar_fd ft_putstr_fd ft_putendl_fd \
					ft_putnbr_fd ft_split ft_itoa ft_strmapi ft_striteri \
					ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
					ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
					ft_lstmap \

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF			=	.cache_exist

################################  RULES  #######################################

all: ${NAME}

${NAME}: ${OBJ}
	@make  --quiet -C ${FT_PRINTF}
	@cp ft_printf/libftprintf.a .
	@mv libftprintf.a ${NAME}
	@make --quiet -C ${GNL}
	@cp ${GNL}/gnl.a .
	@mv gnl.a ${NAME}
	@ar rcs ${NAME} ${OBJ}
	# @echo "${GREEN}libft compiled!${DEF_COLOR}"

${OBJ_DIR}%.o: ${SRC_DIR}%.c | ${OBJF}
	@${CC} ${CFLAGS} -c $< -o $@

$(OBJF):
	@mkdir -p ${OBJ_DIR}
	# @echo "${BLUE}libft object files cleaned!${DEF_COLOR}"

clean:
	@rm -f -rf ${OBJ_DIR}
	@make --quiet clean -C ${FT_PRINTF}
	@make --quiet clean -C ${GNL}
	# @echo "${BLUE}libft object files cleaned!${DEF_COLOR}"

fclean: clean
	@rm -f ${NAME}
	@make --quiet fclean -C ${FT_PRINTF}
	@make --quiet fclean -C ${GNL}
	# @echo "${CYAN}libft executable files cleaned!${DEF_COLOR}"

re: fclean all
	# @echo "${GREEN}Cleaned and rebuilt everything for libft!${DEF_COLOR}"

.SILENT:
	all

.PHONY: all clean fclean re
