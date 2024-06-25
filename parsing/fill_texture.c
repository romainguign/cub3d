/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:50:51 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/25 17:49:24 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	convert_color(char *line, long long int *color)
{
	long long int RGB[3];
	char	**RGBascii;
	int		i;
	
	if (*color != -1)
	{
		ft_putstr_fd("cub3d: double definition of the color\n", 2);
		return (0);
	}
	i = 1;	
	while (line[i] && is_space(line[i]))
		i++;
	RGBascii = ft_split(&line[i], ',');
	if (!RGBascii)
	{
		free_tab((void**)RGBascii);
		ft_putstr_fd(MALLOC_ERROR, 2);
		return (0);
	}
	RGB[0] = ft_atoll(RGBascii[0]);
	RGB[1] = ft_atoll(RGBascii[1]);
	RGB[2] = ft_atoll(RGBascii[2]);
	free_tab((void**)RGBascii);
	*color = (RGB[0] << 16) + (RGB[1] << 8) + RGB[2];
	return (1);
}

static int	dup_texture(char *line, char *texture)
{
	int	i;

	i = 2;
	printf("line : %s\n", line);
	if (texture)
	{
		ft_putstr_fd("cub3d: double definition of texture\n", 2);
		return (0);
	}
	while (line[i] && is_space(line[i]))
		i++;
	texture = ft_strdup(&line[i]);
	if (!texture)
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
	while (is_space(*tmp) && *(++tmp));
	if (*tmp == '\0')
		return (1);
	else if (!ft_strncmp("NO", tmp, 2))
		result = dup_texture(tmp, texture->NO_texture);
	else if (!ft_strncmp("SO", tmp, 2))
		result = dup_texture(tmp, texture->NO_texture);
	else if (!ft_strncmp("WE", tmp, 2))
		result = dup_texture(tmp, texture->NO_texture);
	else if (!ft_strncmp("EA", tmp, 2))
		result = dup_texture(tmp, texture->NO_texture);
	else if (!ft_strncmp("F", tmp, 1))
		result = convert_color(tmp, &texture->F);
	else if (!ft_strncmp("C", tmp, 1))
		result = convert_color(tmp, &texture->C);
	else
		return (-1);
	return (result);
}

int	fill_textures(int fd, t_map *map)
{
	char	*line;
	int		result;
	
	line = get_next_line(fd);
	map->textures = ft_calloc(1, sizeof(t_textures));
	if (!map->textures)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		free_all(map);
		return (0);
	}
	map->textures->C = -1;
	map->textures->F = -1;
	while (line)
	{
		result = copy_texture(line, map->textures);
		if (!result)
		{
			free_all(map);
			return (0);
		}
		if (result == -1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	// check_texures
	printf("NO : %s\n", map->textures->NO_texture);
	printf("SO : %s\n", map->textures->SO_texture);
	printf("WE : %s\n", map->textures->WE_texture);
	printf("EA : %s\n", map->textures->EA_texture);
	printf("F : %lld\n", map->textures->F);
	printf("C : %lld\n", map->textures->C);
	printf("last line : %s\n", line);
	return (1);
}
