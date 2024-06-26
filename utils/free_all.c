/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:03:36 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/26 17:14:56 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_textures *textures)
{
	if (textures->NO_texture)
		free(textures->NO_texture);
	if (textures->SO_texture)
		free(textures->SO_texture);
	if (textures->WE_texture)
		free(textures->WE_texture);
	if (textures->EA_texture)
		free(textures->EA_texture);
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

void	free_all(t_map *map)
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
}
