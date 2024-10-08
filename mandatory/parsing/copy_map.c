/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:56:18 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/24 16:28:22 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static t_block	block_type(char c, t_map *map, int x, int y)
{
	if (c == ' ' || c == '\0' || c == '\n')
		return (EMPTY);
	if (c == '0')
		return (FLOOR);
	if (c == '1')
		return (WALL);
	if (c != 'N' && c != 'W' && c != 'E' && c != 'S')
		return (BAD);
	map->spawn_direction = c;
	map->spawn_x = x;
	map->spawn_y = y;
	return (SPAWN);
}

static int	fill_block(char	*line, int y, t_map *map)
{
	int	x;

	x = 0;
	while (line[x])
	{
		map->block[y][x] = block_type(line[x], map, x, y);
		if (map->block[y][x] == BAD)
		{
			ft_putstr_fd("Error\ncub3d: bad character in map\n", 2);
			free_map(map);
			return (0);
		}
		x++;
	}
	return (1);
}

static int	fill_map(t_map *map, t_file *start_map)
{
	int		y;
	t_file	*tmp;

	y = 0;
	tmp = start_map;
	while (y < map->height)
	{
		map->block[y] = ft_calloc(map->width + 1, sizeof(t_block));
		if (!map->block[y])
		{
			ft_putstr_fd(MALLOC_ERROR, 2);
			free_map(map);
			return (0);
		}
		if (!fill_block(tmp->line, y, map))
			return (0);
		y++;
		tmp = tmp->next;
	}
	return (1);
}

static int	get_size(t_map *map, t_file *start_map)
{
	t_file	*tmp;
	int		i;

	tmp = start_map;
	while (tmp)
	{
		i = 0;
		map->height++;
		if (ft_strlen(tmp->line) > (size_t)map->width)
			map->width = ft_strlen(tmp->line);
		while (tmp->line[i] && is_space(tmp->line[i]))
			i++;
		if (tmp->line[i] == '\0')
			break ;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->line[0] != '\n' || tmp->line[0] == '\0')
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	copy_map(t_map *map)
{
	t_file	*start_map;

	start_map = skip_textures(map->map_file);
	if (!get_size(map, start_map))
	{
		ft_putstr_fd("Error\ncub3d: error: additionnal content after map\n", 2);
		free_map(map);
		return (0);
	}
	map->block = ft_calloc(map->height + 1, sizeof(t_block *));
	if (!map->block)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		free_map(map);
		return (0);
	}
	if (!fill_map(map, start_map))
		return (0);
	return (1);
}
