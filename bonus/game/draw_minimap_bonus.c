/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:50:17 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 16:01:16 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	draw_player(int x, int y, t_image *img)
{
	int	sx;
	int	sy;

	sx = x - 2;
	while (sx < x + 3)
	{
		sy = y - 2;
		while (sy < y + 3)
		{
			img_pix_put(img, sx, sy, RED);
			sy++;
		}
		sx++;
	}
}

static void	draw_walls(t_map *map, t_mlx *mlx, t_game *game, int pos[2])
{
	double	map_x;
	double	map_y;

	map_x = game->pos_x + (pos[1] - MINIMAP_RADIUS) / MINIMAP_ZOOM;
	map_y = game->pos_y + (pos[0] - MINIMAP_RADIUS) / MINIMAP_ZOOM - 2;
	if ((int) map_x >= map->width || (int) map_y >= map->height - 1)
	{
		img_pix_put(mlx->img, pos[1] + MINIMAP_POSX, pos[0]
			+ MINIMAP_POSY, MINIMAP_F_COLOR);
		return ;
	}
	else if (map->block[(int)map_y][(int)map_x] == WALL)
		img_pix_put(mlx->img, pos[1] + MINIMAP_POSX, pos[0]
			+ MINIMAP_POSY, MINIMAP_W_COLOR);
	else
		img_pix_put(mlx->img, pos[1] + MINIMAP_POSX, pos[0]
			+ MINIMAP_POSY, MINIMAP_F_COLOR);
}

void	minimap(t_map *map, t_game *game, t_mlx *mlx)
{
	int	pos[2];

	pos[0] = 0;
	while (pos[0] < MINIMAP_RADIUS * 2 + 2)
	{
		pos[1] = 0;
		while (pos[1] < MINIMAP_RADIUS * 2)
		{
			if (game->mask->minimap[pos[0]][pos[1]] == 1)
				draw_walls(map, mlx, game, pos);
			pos[1]++;
		}
		pos[0]++;
	}
	draw_player(MINIMAP_RADIUS + MINIMAP_POSX, MINIMAP_RADIUS
		+ MINIMAP_POSY, mlx->img);
}
