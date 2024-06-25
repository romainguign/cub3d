/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:09 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/25 17:10:32 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INFOS_H
# define MAP_INFOS_H

# include "cub3d.h"

typedef enum e_block
{
	EMPTY,
	FLOOR,
	WALL,
	SPAWN
}	t_block;

typedef struct s_textures
{
	char			facing_direction;
	char			*NO_texture;
	char			*SO_texture;
	char			*WE_texture;
	char			*EA_texture;
	long long int	F;
	long long int	C;
}	t_textures;

typedef struct s_map
{
	t_block		**block;
	t_textures	*textures;
	int			width;
	int			height;
}	t_map;

/*----------------------------- Parsing functions -----------------------------*/
t_map	*parse_map(char	*filename);
int		fill_textures(int fd, t_map *map);

#endif