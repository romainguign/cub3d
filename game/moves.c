/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:16:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/19 18:31:03 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	camera_moves(t_game *game, char *input)
{
	double	old_plane_x;
	double	old_dir_x;

	if (input[2] == 1)
	{
		old_plane_x = game->plane_x;
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(-SENSI) - game->dir_y * sin(-SENSI);
		game->dir_y = old_dir_x * sin(-SENSI) + game->dir_y * cos(-SENSI);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-SENSI) - game->plane_y
			* sin(-SENSI);
		game->plane_y = old_plane_x * sin(-SENSI) + game->plane_y * cos(-SENSI);
	}
	if (input[3] == 1)
	{
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(SENSI) - game->dir_y * sin(SENSI);
		game->dir_y = old_dir_x * sin(SENSI) + game->dir_y * cos(SENSI);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(SENSI) - game->plane_y
			* sin(SENSI);
		game->plane_y = old_plane_x * sin(SENSI) + game->plane_y * cos(SENSI);
	}
}

static void	calc_new_pos(t_game *game, double *new_x,
	double *new_y, char *input)
{
	double	move_speed;

	move_speed = SPEED;
	if ((input[1] || input[2]) && (input[4] || input[5]))
		move_speed = SPEED / sqrt(2);
	if (input[0] == 1)
	{
		*new_x += game->dir_x * move_speed;
		*new_y += game->dir_y * move_speed;
	}
	if (input[1] == 1)
	{
		*new_x -= game->dir_x * move_speed;
		*new_y -= game->dir_y * move_speed;
	}
	if (input[4] == 1)
	{
		*new_x -= game->plane_x * move_speed;
		*new_y -= game->plane_y * move_speed;
	}
	if (input[5] == 1)
	{
		*new_x += game->plane_x * move_speed;
		*new_y += game->plane_y * move_speed;
	}
}

void	player_moves(t_game *game, t_map *map, char *input)
{
	double	new_x;
	double	new_y;

	new_x = game->pos_x;
	new_y = game->pos_y;
	calc_new_pos(game, &new_x, &new_y, input);
	game->pos_x = new_x;
	game->pos_y = new_y;
	if (game->pos_x >= map->width - 2.5)
		game->pos_x = 0.5;
	else if (game->pos_x < 0.5)
		game->pos_x = map->width - 2.5;
	if (game->pos_y >= map->height - 1.5)
		game->pos_y = 1;
	else if (game->pos_y < 1)
		game->pos_y = map->height - 1.5;
}
