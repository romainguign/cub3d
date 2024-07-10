/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:01:53 by roguigna          #+#    #+#             */
/*   Updated: 2024/07/09 14:16:57 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster(t_game *game, t_map *map, t_mlx *mlx)
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		x;
	
	// boucle pour les murs
	x = 0;
	while (x < WIN_WIDTH)
	{
		cameraX = 2 * x / (double)WIN_WIDTH - 1;
		rayDirX = game->dir_x + game->plane_x * cameraX;
		rayDirY = game->dir_y + game->plane_y * cameraX;

		int mapX = (int)game->pos_x;
		int mapY = (int)game->pos_y;

		double sideDistX;
		double sideDistY;
		
		double deltaDistX;
		double deltaDistY;
		double perpWallDist;
		
		// if (rayDirX == 0)
		// 	deltaDistX = 1e30;
		// else
			deltaDistX = fabs(1 / rayDirX);
		// if (rayDirY == 0)
		// 	deltaDistY = 1e30;
		// else
			deltaDistY = fabs(1 / rayDirY);
		
		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->pos_y) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			printf("mapY : %d, mapX : %d\n", mapY, mapX);
			if (mapX < 0 || mapX >= map->width || mapY < 0 || mapY >= map->height - 1) {
				hit = 1;
				break; // Sortie de la boucle pour éviter l'accès hors limites
			}
			if (map->block[mapY][mapX] == WALL)
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);
		
		int	draw_len[2];
		draw_len[0] = -lineHeight / 2 + WIN_HEIGHT / 2;
		if(draw_len[0] < 0)
			draw_len[0] = 0;
		draw_len[1] = lineHeight / 2 + WIN_HEIGHT / 2;
		if(draw_len[1] >= WIN_HEIGHT)
			draw_len[1] = WIN_HEIGHT - 1;
		draw_column(map, mlx->img, draw_len, x);
		x++;
	}
	minimap(map, game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	
	// boucle pour le sol
}