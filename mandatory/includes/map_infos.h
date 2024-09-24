/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:09 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/24 13:02:15 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFOS_H
# define MAP_INFOS_H

# include "cube.h"

typedef enum e_block
{
	EMPTY,
	FLOOR,
	WALL,
	SPAWN,
	BAD
}	t_block;

typedef struct s_textures
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	long long int	f;
	long long int	c;
}	t_textures;

typedef struct s_file
{
	char			*line;
	struct s_file	*next;
}	t_file;

typedef struct s_map
{
	t_file		*map_file;
	t_block		**block;
	t_textures	*textures;
	char		spawn_direction;
	int			height;
	int			width;
	int			spawn_x;
	int			spawn_y;
}	t_map;

/*---------------------------- Parsing functions ----------------------------*/
t_map	*parse_map(char	*filename);
int		fill_textures(t_map *map);
int		convert_color(char *line, long long int *color);
int		copy_map(t_map *map);
int		check_map_file(int fd, t_map *map);
int		check_textures(t_textures *textures, t_map *map);
int		is_valid_map(t_map *map);
t_file	*skip_textures(t_file *file);
void	file_to_char(int fd, t_map *map);
void	ft_fileclear(t_file **lst, void (*del)(void*));

#endif