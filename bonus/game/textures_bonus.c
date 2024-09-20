/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:53:52 by tsoloher          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	get_texture(t_ray *ray, t_mlx *mlx)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			ray->texture = mlx->we_img;
		else
			ray->texture = mlx->ea_img;
	}
	else
	{
		if (ray->dir_y < 0)
			ray->texture = mlx->so_img;
		else
			ray->texture = mlx->no_img;
	}
}

static void	get_texture_offset(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->wall_x = game->pos_y + ray->raywall_dist * ray->dir_y;
	else
		ray->wall_x = game->pos_x + ray->raywall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)ray->texture->width);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = ray->texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = ray->texture->width - ray->tex_x - 1;
}

static void	draw_texture(t_ray *ray, t_game *game, t_mlx *mlx, int x)
{
	int	y;
	int	color;
	int	tex_y;
	int	d;

	(void)game;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		d = y * 256 - WIN_HEIGHT * 128 + ray->line_height * 128;
		tex_y = ((d * ray->texture->height) / ray->line_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= ray->texture->height)
			tex_y = ray->texture->height - 1;
		color = *(int *)(ray->texture->pixels
				+ (tex_y * ray->texture->size_line
					+ ray->tex_x * (ray->texture->bpp / 8)));
		*(int *)(mlx->img->pixels + (y * mlx->img->size_line
					+ x * (mlx->img->bpp / 8))) = color;
		y++;
	}
}

void	draw_textures(t_ray *ray, t_game *game, t_mlx *mlx, int x)
{
	get_texture(ray, mlx);
	get_texture_offset(ray, game);
	draw_texture(ray, game, mlx, x);
}
