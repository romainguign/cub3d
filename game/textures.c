/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:53:52 by tsoloher          #+#    #+#             */
/*   Updated: 2024/09/19 18:16:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void		get_texture(t_ray *ray, t_mlx *mlx)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			ray->texture = mlx->ea_img;
		else
			ray->texture = mlx->we_img;
	}
	else
	{
		if (ray->dir_y < 0)
			ray->texture = mlx->so_img;
		else
			ray->texture = mlx->no_img;
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

void	draw_textures(t_ray *ray, t_game *game, t_mlx *mlx, int x)
{
	get_texture(ray, mlx);
	get_texture_offset(ray, game);
	draw_texture(ray, game, mlx, x); 
}


void	destroy_textures(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->no_img);
	mlx_destroy_image(mlx->mlx, mlx->so_img);
	mlx_destroy_image(mlx->mlx, mlx->we_img);
	mlx_destroy_image(mlx->mlx, mlx->ea_img);
}

void			load_textures(t_textures *textures, t_mlx *mlx)
{
	mlx->no_img = ft_calloc(1, sizeof(t_image));
	mlx->so_img = ft_calloc(1, sizeof(t_image));
	mlx->we_img = ft_calloc(1, sizeof(t_image));
	mlx->ea_img = ft_calloc(1, sizeof(t_image));
	
	mlx->no_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->no_texture, &mlx->no_img->width, &mlx->no_img->height);
	mlx->so_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->so_texture, &mlx->so_img->width, &mlx->so_img->height);
	mlx->we_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->ea_texture, &mlx->we_img->width, &mlx->we_img->height);
	mlx->ea_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->we_texture, &mlx->ea_img->width, &mlx->ea_img->height);
	
	if (!mlx->no_img->img || !mlx->so_img->img| !mlx->we_img->img || !mlx->ea_img->img)
	{
		ft_putstr_fd("Error\nTexture not found\n", 2);
		exit(0);
	}
	
	mlx->no_img->pixels = mlx_get_data_addr(mlx->no_img->img, &mlx->no_img->bpp,
			&mlx->no_img->size_line, &mlx->no_img->endian);
	mlx->so_img->pixels = mlx_get_data_addr(mlx->so_img->img, &mlx->so_img->bpp,
			&mlx->so_img->size_line, &mlx->so_img->endian);
	mlx->we_img->pixels = mlx_get_data_addr(mlx->we_img->img, &mlx->we_img->bpp,
			&mlx->we_img->size_line, &mlx->we_img->endian);
	mlx->ea_img->pixels = mlx_get_data_addr(mlx->ea_img->img, &mlx->ea_img->bpp,
			&mlx->ea_img->size_line, &mlx->ea_img->endian);
}
