/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:53:52 by tsoloher          #+#    #+#             */
/*   Updated: 2024/09/18 17:31:02 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		get_texture(t_ray *ray, t_game *game, t_textures *textures, t_mlx *mlx)
{
	(void)game;
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			ray->texture = mlx->EA_img;
		else
			ray->texture = mlx->WE_img;
	}
	else
	{
		if (ray->dir_y < 0)
			ray->texture = mlx->SO_img;
		else
			ray->texture = mlx->NO_img;
	}
}

static void		get_texture_offset(t_ray *ray, t_game *game)
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

static void draw_texture(t_ray *ray, t_game *game, t_mlx *mlx, int x)
{
	int y;
	int color;
	int tex_y;
	int d;

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

		color = *(int *)(ray->texture->pixels + (tex_y * ray->texture->size_line + ray->tex_x * (ray->texture->bpp / 8)));
		*(int *)(mlx->img->pixels + (y * mlx->img->size_line + x * (mlx->img->bpp / 8))) = color;
		y++;
	}
}

void	draw_textures(t_ray *ray, t_game *game, t_mlx *mlx, t_textures *textures, int x)
{
	get_texture(ray, game, textures, mlx);
	get_texture_offset(ray, game);
	draw_texture(ray, game, mlx, x); 
}


void	destroy_textures(t_textures *textures, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->NO_img);
	mlx_destroy_image(mlx->mlx, mlx->SO_img);
	mlx_destroy_image(mlx->mlx, mlx->WE_img);
	mlx_destroy_image(mlx->mlx, mlx->EA_img);
}

void			load_textures(t_textures *textures, t_mlx *mlx)
{
	mlx->NO_img = ft_calloc(1, sizeof(t_image));
	mlx->SO_img = ft_calloc(1, sizeof(t_image));
	mlx->WE_img = ft_calloc(1, sizeof(t_image));
	mlx->EA_img = ft_calloc(1, sizeof(t_image));
	
	mlx->NO_img->img = mlx_xpm_file_to_image(mlx->mlx, "textures/bipbip.xpm", &mlx->NO_img->width, &mlx->NO_img->height);
	mlx->SO_img->img = mlx_xpm_file_to_image(mlx->mlx, "textures/coyote.xpm", &mlx->SO_img->width, &mlx->SO_img->height);
	mlx->WE_img->img = mlx_xpm_file_to_image(mlx->mlx, "textures/Taz_.xpm", &mlx->EA_img->width, &mlx->EA_img->height);
	mlx->EA_img->img = mlx_xpm_file_to_image(mlx->mlx, "textures/bipbip.xpm", &mlx->WE_img->width, &mlx->WE_img->height);
	if (!mlx->NO_img->img || !mlx->SO_img->img| !mlx->WE_img->img || !mlx->EA_img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		exit(0);
	}
	
	mlx->NO_img->pixels = mlx_get_data_addr(mlx->NO_img->img, &mlx->NO_img->bpp,
			&mlx->NO_img->size_line, &mlx->NO_img->endian);
	mlx->SO_img->pixels = mlx_get_data_addr(mlx->SO_img->img, &mlx->SO_img->bpp,
			&mlx->SO_img->size_line, &mlx->SO_img->endian);
	mlx->WE_img->pixels = mlx_get_data_addr(mlx->WE_img->img, &mlx->WE_img->bpp,
			&mlx->WE_img->size_line, &mlx->WE_img->endian);
	mlx->EA_img->pixels = mlx_get_data_addr(mlx->EA_img->img, &mlx->EA_img->bpp,
			&mlx->EA_img->size_line, &mlx->EA_img->endian);
}
