/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:03:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/19 18:16:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	free_textures(t_textures *textures)
{
	if (textures->no_texture)
		free(textures->no_texture);
	if (textures->so_texture)
		free(textures->so_texture);
	if (textures->we_texture)
		free(textures->we_texture);
	if (textures->ea_texture)
		free(textures->ea_texture);
	free(textures);
}

void	ft_free_tab(void **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->map_file)
			ft_fileclear(&map->map_file, free);
		if (map->textures)
			free_textures(map->textures);
		if (map->block)
			ft_free_tab((void **)map->block);
		free (map);
	}
	map = NULL;
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->mlx)
		free(mlx->mlx);
	if (mlx->img)
		free(mlx->img);
	free(mlx);
	mlx = NULL;
}

void	free_all(t_cube *cube)
{
	if (cube->map)
		free_map(cube->map);
	if (cube->mlx)
		free_mlx(cube->mlx);
	if (cube->game)
	{
		if (cube->game->mask)
		{
			if (cube->game->mask->minimap)
				free_tab((void **)cube->game->mask->minimap);
			free(cube->game->mask);
		}
		free(cube->game);
	}
	free(cube);
}
