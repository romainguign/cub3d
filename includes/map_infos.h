/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_infos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:37:09 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/20 16:26:04 by roguigna         ###   ########.fr       */
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

typedef struct s_map
{
	t_block	**block;
	char	facing_direction;
	
	int		width;
	int		height;
}	t_map;

/*----------------------------- Parsing functions -----------------------------*/
t_map	*parse_map(char	*filename);

#endif