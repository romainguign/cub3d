/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:53:52 by tsoloher          #+#    #+#             */
/*   Updated: 2024/09/17 23:45:29 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		get_texture(t_ray *ray, t_game *game, t_textures *textures)
{
	(void)game;
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			ray->texture = textures->EA_texture;
		else
			ray->texture = textures->WE_texture;
	}
	else
	{
		if (ray->dir_y < 0)
			ray->texture = textures->SO_texture;
		else
			ray->texture = textures->NO_texture;
	}
}

static void		get_texture_offset(t_ray *ray, t_game *game)
{
	if (ray->side == 0)
		ray->wall_x = game->pos_y + ray->raywall_dist * ray->dir_y;
	else
		ray->wall_x = game->pos_x + ray->raywall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->dir_x > 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		ray->tex_x = TEX_WIDTH - ray->tex_x - 1;
}

static void		draw_texture(t_ray *ray, t_game *game, t_mlx *mlx, int x)
{
	int		y;
	int		color;
	int		tex_y;
	int		d;

	(void)game;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		d = y * 256 - WIN_HEIGHT * 128 + ray->line_height * 128;
		tex_y = ((d * TEX_HEIGHT) / ray->line_height) / 256;
		color = *(int *)(mlx->img->pixels + (tex_y * mlx->img->size_line
					+ ray->tex_x * (mlx->img->bpp / 8)));
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		*(int *)(mlx->img->pixels + (y * mlx->img->size_line + x
					* (mlx->img->bpp / 8))) = color;
		y++;
	}
}

void			draw_textures(t_ray *ray, t_game *game, t_mlx *mlx, t_textures *textures)
{
	get_texture(ray, game, textures);
	get_texture_offset(ray, game);
	draw_texture(ray, game, mlx, ray->tex_x);
}


void			free_textures(t_textures *textures, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, textures->NO_texture);
	mlx_destroy_image(mlx->mlx, textures->SO_texture);
	mlx_destroy_image(mlx->mlx, textures->WE_texture);
	mlx_destroy_image(mlx->mlx, textures->EA_texture);
}

void			init_textures(t_textures *textures)
{
	textures->NO_texture = NULL;
	textures->SO_texture = NULL;
	textures->WE_texture = NULL;
	textures->EA_texture = NULL;
}



void			load_textures(t_textures *textures, t_mlx *mlx)
{
	int tex_width;
	int tex_height;

	
	textures->NO_texture = mlx_xpm_file_to_image(mlx->mlx, "coyote.xpm", &tex_width, &tex_height);
	textures->SO_texture = mlx_xpm_file_to_image(mlx->mlx, "coyote.xpm", &tex_width, &tex_height);
	textures->WE_texture = mlx_xpm_file_to_image(mlx->mlx, "coyote.xpm", &tex_width, &tex_height);
	textures->EA_texture = mlx_xpm_file_to_image(mlx->mlx, "coyote.xpm", &tex_width, &tex_height);

	if (!textures->NO_texture || !textures->SO_texture || !textures->WE_texture || !textures->EA_texture)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		exit(0);
	}
}