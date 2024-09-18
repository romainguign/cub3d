/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:01:53 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/18 16:01:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	init_raycasting(int x, t_ray *ray, t_game *game)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = game->dir_x + game->plane_x * ray->camera_x;
	ray->dir_y = game->dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->pos_x;
	ray->map_y = (int)game->pos_y;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

static void	step_dda(t_ray *ray, t_game *game)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (game->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - game->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (game->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - game->pos_y) * ray->deltadist_y;
	}
}

static int	perform_dda(t_map *map, t_ray *ray)
{
	while (1)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0
			|| ray->map_x < 0
			|| ray->map_y > map->height - 1
			|| ray->map_x > map->width - 1)
			return (0);
		else if (map->block[ray->map_y][ray->map_x] == WALL)
			return (1);
	}
}

static void	calculate_line_height(t_ray *ray, t_game *game)
{
	if (ray->hit == 0)
	{
		ray->line_height = 0;
		ray->draw_start = WIN_HEIGHT / 2;
		ray->draw_end = WIN_HEIGHT / 2;
		return ;
	}
	if (ray->side == 0)
		ray->raywall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->raywall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WIN_HEIGHT / ray->raywall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game->pos_y + ray->raywall_dist * ray->dir_y;
	else
		ray->wall_x = game->pos_x + ray->raywall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

int	raycaster(t_game *game, t_map *map, t_mlx *mlx)
{
	t_ray	ray;
	int		x;

	x = 0;
	ray = game->ray;
	while (x < WIN_WIDTH)
	{
		init_raycasting(x, &ray, game);
		step_dda(&ray, game);
		ray.hit = perform_dda(map, &ray);
		calculate_line_height(&ray, game);
		draw_column(map, mlx->img, &ray, x);
		if (ray.draw_start != WIN_HEIGHT / 2 && ray.draw_end != WIN_HEIGHT / 2)
			draw_textures(&ray, game, mlx, map->textures, x);
		x++;
	}
	// minimap(map, game, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (1);
}
