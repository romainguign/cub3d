/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:10:12 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/21 16:49:53 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	destroy_textures(t_mlx *mlx)
{
	if (mlx->no_img->img)
		mlx_destroy_image(mlx->mlx, mlx->no_img->img);
	if (mlx->so_img->img)
		mlx_destroy_image(mlx->mlx, mlx->so_img->img);
	if (mlx->we_img->img)
		mlx_destroy_image(mlx->mlx, mlx->we_img->img);
	if (mlx->ea_img->img)
		mlx_destroy_image(mlx->mlx, mlx->ea_img->img);
}

static int	get_textures_data(t_mlx *mlx)
{
	mlx->no_img->pixels = mlx_get_data_addr(mlx->no_img->img, &mlx->no_img->bpp,
			&mlx->no_img->size_line, &mlx->no_img->endian);
	mlx->so_img->pixels = mlx_get_data_addr(mlx->so_img->img, &mlx->so_img->bpp,
			&mlx->so_img->size_line, &mlx->so_img->endian);
	mlx->we_img->pixels = mlx_get_data_addr(mlx->we_img->img, &mlx->we_img->bpp,
			&mlx->we_img->size_line, &mlx->we_img->endian);
	mlx->ea_img->pixels = mlx_get_data_addr(mlx->ea_img->img, &mlx->ea_img->bpp,
			&mlx->ea_img->size_line, &mlx->ea_img->endian);
	if (!mlx->no_img->pixels || !mlx->so_img->pixels
		|| !mlx->we_img->pixels || !mlx->ea_img->pixels)
		return (0);
	return (1);
}

int	load_textures(t_textures *textures, t_mlx *mlx)
{
	mlx->no_img = ft_calloc(1, sizeof(t_image));
	mlx->so_img = ft_calloc(1, sizeof(t_image));
	mlx->we_img = ft_calloc(1, sizeof(t_image));
	mlx->ea_img = ft_calloc(1, sizeof(t_image));
	if (!mlx->no_img || !mlx->so_img || !mlx->we_img || !mlx->ea_img)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		return (0);
	}
	mlx->no_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->no_texture,
			&mlx->no_img->width, &mlx->no_img->height);
	mlx->so_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->so_texture,
			&mlx->so_img->width, &mlx->so_img->height);
	mlx->we_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->ea_texture,
			&mlx->we_img->width, &mlx->we_img->height);
	mlx->ea_img->img = mlx_xpm_file_to_image(mlx->mlx, textures->we_texture,
			&mlx->ea_img->width, &mlx->ea_img->height);
	if (!mlx->no_img->img || !mlx->so_img->img || !mlx->we_img->img
		|| !mlx->ea_img->img || !get_textures_data(mlx))
	{
		ft_putstr_fd("cub3d: texture loading error\n", 2);
		return (0);
	}
	return (1);
}
