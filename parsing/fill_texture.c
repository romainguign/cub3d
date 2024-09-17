/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:50:51 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/17 17:48:44 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	convert_color(char *line, long long int *color)
{
	long long int	rgb[3];
	char			**rgb_ascii;
	int				i;

	if (*color != -1)
	{
		ft_putstr_fd("cub3d: double definition of the color\n", 2);
		return (0);
	}
	i = 1;
	while (line[i] && is_space(line[i]))
		i++;
	rgb_ascii = ft_split(&line[i], ',');
	if (!rgb_ascii)
	{
		free_tab((void **)rgb_ascii);
		ft_putstr_fd(MALLOC_ERROR, 2);
		return (0);
	}
	rgb[0] = ft_atoll(rgb_ascii[0]);
	rgb[1] = ft_atoll(rgb_ascii[1]);
	rgb[2] = ft_atoll(rgb_ascii[2]);
	free_tab((void **)rgb_ascii);
	*color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (1);
}

static int	dup_texture(char *line, char **texture)
{
	int	i;

	i = 2;
	if (*texture)
	{
		ft_putstr_fd("cub3d: double definition of texture\n", 2);
		return (0);
	}
	while (line[i] && is_space(line[i]))
		i++;
	*texture = ft_strdup(&line[i]);
	if (!(*texture))
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		return (0);
	}
	return (1);
}

static int	copy_texture(char *line, t_textures *texture)
{
	char	*tmp;
	int		result;

	tmp = line;
	while (is_space(*tmp) && *(++tmp))
		;
	if (*tmp == '\0')
		return (1);
	else if (!ft_strncmp("NO", tmp, 2))
		result = dup_texture(tmp, &texture->NO_texture);
	else if (!ft_strncmp("SO", tmp, 2))
		result = dup_texture(tmp, &texture->SO_texture);
	else if (!ft_strncmp("WE", tmp, 2))
		result = dup_texture(tmp, &texture->WE_texture);
	else if (!ft_strncmp("EA", tmp, 2))
		result = dup_texture(tmp, &texture->EA_texture);
	else if (!ft_strncmp("F", tmp, 1))
		result = convert_color(tmp, &texture->F);
	else if (!ft_strncmp("C", tmp, 1))
		result = convert_color(tmp, &texture->C);
	else
		return (-1);
	return (result);
}

static int	texture_loop(t_map *map)
{
	int		result;
	t_file	*tmp;

	tmp = map->map_file;
	while (tmp)
	{
		result = copy_texture(tmp->line, map->textures);
		if (!result)
		{
			free_map(map);
			return (0);
		}
		if (result == -1)
			break ;
		tmp = tmp->next;
	}
	return (1);
}

int	fill_textures(t_map *map)
{
	map->textures = ft_calloc(1, sizeof(t_textures));
	if (!map->textures)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		free_map(map);
		return (0);
	}
	map->textures->C = -1;
	map->textures->F = -1;
	if (!texture_loop(map))
		return (0);
	// check_texures extension + access
	printf("NO : %s", map->textures->NO_texture);
	printf("SO : %s", map->textures->SO_texture);
	printf("WE : %s", map->textures->WE_texture);
	printf("EA : %s", map->textures->EA_texture);
	printf("F : %lld\n", map->textures->F);
	printf("C : %lld\n", map->textures->C);
	return (1);
}
