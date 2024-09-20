# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:03:42 by roguigna          #+#    #+#              #
#    Updated: 2024/09/20 15:50:58 by roguigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

NAME_BONUS		= cub3D_bonus

CC				= cc

CFLAGS 			= -Wall -Wextra -g3 #-Werror 

LIBFT			= libft/libft.a

INCLUDE			= -I mandatory/includes -I libft/includes

INCLUDE_BONUS	= -I bonus/includes -I libft/includes

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

OBJ_DIR			= 		mandatory/object

OBJ_DIR_BONUS	= 		bonus/object

SRC_FILES		= 		mandatory/cub3d.c \
				  		mandatory/utils/utils.c \
				  		mandatory/utils/free_all.c \
				  		mandatory/parsing/parse_map.c \
				  		mandatory/parsing/fill_texture.c \
				  		mandatory/parsing/check_map_file.c \
				  		mandatory/parsing/file_to_char.c \
				  		mandatory/parsing/copy_map.c \
				  		mandatory/parsing/is_valid_map.c \
				  		mandatory/parsing/parse_color.c \
				  		mandatory/parsing/check_textures.c \
				  		mandatory/game/initialize_window.c \
				  		mandatory/game/draw.c \
				  		mandatory/game/moves.c \
				  		mandatory/game/raycaster.c \
				  		mandatory/game/events.c \
				  		mandatory/game/init_game.c \
				  		mandatory/game/textures.c \
				  		mandatory/game/load_textures.c \

SRC_BONUS_FILES	= 		bonus/cub3d_bonus.c \
				  		bonus/utils/utils_bonus.c \
				  		bonus/utils/free_all_bonus.c \
				  		bonus/parsing/parse_map_bonus.c \
				  		bonus/parsing/fill_texture_bonus.c \
				  		bonus/parsing/check_map_file_bonus.c \
				  		bonus/parsing/file_to_char_bonus.c \
				  		bonus/parsing/copy_map_bonus.c \
				  		bonus/parsing/is_valid_map_bonus.c \
				  		bonus/parsing/parse_color_bonus.c \
				  		bonus/parsing/check_textures_bonus.c \
				  		bonus/game/initialize_window_bonus.c \
				  		bonus/game/draw_bonus.c \
				  		bonus/game/moves_bonus.c \
				  		bonus/game/raycaster_bonus.c \
				  		bonus/game/minimap_mask_bonus.c \
				  		bonus/game/draw_minimap_bonus.c \
				  		bonus/game/events_bonus.c \
				  		bonus/game/init_game_bonus.c \
				  		bonus/game/textures_bonus.c \
				  		bonus/game/load_textures_bonus.c \

OBJ             	= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

OBJ_BONUS			= $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS_FILES:.c=.o))

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

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(OBJ_BONUS) $(LIBFT) $(CFLAGS) $(MLX_FLAGS) $(INCLUDE_BONUS) -o $(NAME_BONUS) 
	@echo "${GREEN}Cub3d executable file is ready! ${DEF_COLOR}"

$(OBJ_DIR_BONUS)/%.o: %.c | $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) -Imlx_linux -c $< -o $@

$(OBJ_DIR_BONUS):
	@mkdir -p $(dir $(OBJ_BONUS))

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@make --quiet clean -C libft
	@echo "${GRAY}Cub3d object files cleaned! ${DEF_COLOR}"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make --quiet fclean -C libft
	@echo "${YELLOW}Cub3d executable files cleaned! ${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re