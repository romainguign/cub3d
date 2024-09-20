/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:21:43 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 16:01:21 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	init_ray(t_ray *ray)
{
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->raywall_dist = 0;
	ray->wall_x = 0;
	ray->hit = 0;
}

static void	init_dir(t_cube *cube)
{
	if (cube->map->spawn_direction == 'S')
	{
		cube->game->dir_y = 1;
		cube->game->plane_x = -0.66;
	}
	else if (cube->map->spawn_direction == 'N')
	{
		cube->game->dir_y = -1;
		cube->game->plane_x = 0.66;
	}
	else if (cube->map->spawn_direction == 'E')
	{
		cube->game->dir_x = 1;
		cube->game->plane_y = 0.66;
	}
	else if (cube->map->spawn_direction == 'W')
	{
		cube->game->dir_x = -1;
		cube->game->plane_y = -0.66;
	}
}

int	init_game(t_cube *cube)
{
	int	i;

	i = 0;
	cube->mlx->img = ft_calloc(1, sizeof(t_image));
	if (!cube->mlx->img)
		return (0);
	cube->game = ft_calloc(1, sizeof(t_game));
	if (!cube->game)
		return (0);
	cube->game->pos_x = cube->map->spawn_x + 0.5;
	cube->game->pos_y = cube->map->spawn_y + 0.5;
	init_dir(cube);
	cube->game->mask = ft_calloc(1, sizeof(t_mask));
	if (!cube->game->mask)
		return (0);
	while (i++ < 6)
		cube->game->input[i] = 0;
	if (!minimap_mask(cube->game->mask))
		return (0);
	return (1);
}
