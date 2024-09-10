# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:03:42 by roguigna          #+#    #+#              #
#    Updated: 2024/09/09 16:10:33 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

CC				= cc

CFLAGS 			= -Wall -Wextra -g3 #-Werror 

LIBFT			= libft/libft.a

INCLUDE			= -I includes -I libft/includes

LIB				= -L libft -lft		

MLX_FLAGS		= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

##############################  COLORS  ###################################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[3;92m
YELLOW = \033[0;93m
BLUE = \033[3;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


##############################  SOURCES  #####################################

OBJ_DIR			= object

SRC_FILES		= cub3d.c \
				  utils/utils.c \
				  utils/free_all.c \
				  parsing/parse_map.c \
				  parsing/fill_texture.c \
				  parsing/check_map_file.c \
				  parsing/file_to_char.c \
				  parsing/copy_map.c \
				  parsing/is_valid_map.c \
				  game/initialize_window.c \
				  game/draw.c \
				  game/moves.c \
				  game/raycaster.c \
				  game/minimap_mask.c \
				  game/draw_minimap.c \
				  game/events.c \
				  game/init_game.c


OBJ             = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

##############################  RULES  #######################################

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) $(MLX_FLAGS) $(INCLUDE) -o $(NAME) 
	@echo "${GREEN}Cub3d executable file is ready! ${DEF_COLOR}"
	
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -Imlx_linux -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(dir $(OBJ))

$(LIBFT):
	@make --quiet -C libft 

clean:
	@rm -rf $(OBJ_DIR)
	@make --quiet clean -C libft
	@echo "${GRAY}Cub3d object files cleaned! ${DEF_COLOR}"

fclean: clean
	@rm -f $(NAME)
	@make --quiet fclean -C libft
	@echo "${YELLOW}Cub3d executable files cleaned! ${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re