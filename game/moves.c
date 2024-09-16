/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:16:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/17 01:19:18 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	camera_moves(t_game *game, char *input)
{
	// if (key_code == XK_Up)
	// 	game->dir_y += SENSIBILITY;
	if (input[2] == 1)
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
	if (input[3] == 1)
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

void	player_moves(t_game *game, t_map *map, char *input)
{
	double	new_x;
	double	new_y;
	
	new_x = game->pos_x;
	new_y = game->pos_y;
	if (input[0] == 1)
	{
		new_x += game->dir_x * SPEED;
		new_y += game->dir_y * SPEED;
	}
	if (input[1] == 1)
	{
		new_x -= game->dir_x * SPEED;
		new_y -= game->dir_y * SPEED;
	}
	game->pos_x = new_x;
	game->pos_y = new_y;
	if (game->pos_x >= map->width - 2.5)
		game->pos_x = 0.5;
	else if (game->pos_x < 0.5)
		game->pos_x = map->width - 2.5;
	if (game->pos_y >= map->height - 1.5)
		game->pos_y = 0.5;
	else if (game->pos_y < 0.5)
		game->pos_y = map->height - 1.5;

	printf ("x : %f, y : %f\n", game->pos_x, game->pos_y);
}