/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:59:06 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/17 14:26:27 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int check_line(t_block **block, int height, int width, int y)
{
	int x;
	static int	spawn;

	x = 0;
	if (!spawn)
		spawn = 0;
	while (x < width - 1)
	{
		if (block[y][x] == SPAWN)
			spawn++;
		if (block[y][x] == FLOOR || block[y][x] == SPAWN)
		{
			if (x == 0 || y == 0 || y == height - 1 || x == width - 2)
				return (0);
			if (block[y - 1][x] == EMPTY || block[y][x - 1] == EMPTY
				|| block[y + 1][x] == EMPTY || block[y][x + 1] == EMPTY)
					return (0);
		}
		x++;
	}
	if (spawn > 1)
		return (0);
	return (1);
}

int is_valid_map(t_map *map)
{
	int y;

	y = 0;
	while (y < map->height)
	{
		if (!check_line(map->block, map->height, map->width, y))
		{
			ft_putstr_fd("cub3d : invalid map\n", 2);
			return (0);
		}
		y++;
	}
	return (1);
}