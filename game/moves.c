/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:16:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/07/11 20:06:52 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	camera_moves(t_game *game, int key_code)
{
	// if (key_code == XK_Up)
	// 	game->dir_y += SENSIBILITY;
	if (key_code == XK_Left)
	{
		double oldDirX;
		oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(-SENSIBILITY) - game->dir_y * sin(-SENSIBILITY);
		game->dir_y = oldDirX * sin(-SENSIBILITY) + game->dir_y * cos(-SENSIBILITY);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(-SENSIBILITY) - game->plane_y * sin(-SENSIBILITY);
		game->plane_y = oldPlaneX * sin(-SENSIBILITY) + game->plane_y * cos(-SENSIBILITY);
	}
		// if (key_code == XK_Down)
		// 	game->dir_y -= SENSIBILITY;
	if (key_code == XK_Right)
	{
		double oldDirX = game->dir_x;
		game->dir_x = game->dir_x * cos(SENSIBILITY) - game->dir_y * sin(SENSIBILITY);
		game->dir_y = oldDirX * sin(SENSIBILITY) + game->dir_y * cos(SENSIBILITY);
		double oldPlaneX = game->plane_x;
		game->plane_x = game->plane_x * cos(SENSIBILITY) - game->plane_y * sin(SENSIBILITY);
		game->plane_y = oldPlaneX * sin(SENSIBILITY) + game->plane_y * cos(SENSIBILITY);
	}
	// if (game->dir_x > 1)
	// 	game
}

void	player_moves(t_game *game, t_map *map, int key_code)
{
	double	new_x;
	double	new_y;
	
	new_x = game->pos_x;
	new_y = game->pos_y;
	if (key_code == XK_w)
	{
		new_x += game->dir_x * SPEED;
		new_y += game->dir_y * SPEED;
	}
	if (key_code == XK_s)
	{
		new_x -= game->dir_x * SPEED;
		new_y -= game->dir_y * SPEED;
	}

	//temp
	// if (key_code == XK_w)
	// 	game->pos_y += SPEED;
	// if (key_code == XK_s)
	// 	game->pos_y -= SPEED;
	// if (key_code == XK_s)
	// {
	// 	new_x -= game->dir_x * SPEED;
	// 	new_y -= game->dir_y * SPEED;
	// }
	
	// // if ((int)new_x > 0 && (int)new_x < map->width && map->block[(int)game->pos_y][(int)new_x] != WALL)
		game->pos_x = new_x;
	// // if ((int)new_y > 0 && (int)new_y < map->height && map->block[(int)new_y][(int)game->pos_x] != WALL)
		game->pos_y = new_y;
	// if (key_code == XK_a)
	// 	game->pos_x -= SPEED;
	// if (key_code == XK_d)
	// 	game->pos_x += SPEED;
}
	