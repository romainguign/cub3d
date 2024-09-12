/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:56:18 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/12 10:04:42 by roguigna         ###   ########.fr       */
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
	map->spawn_direction = c;
	map->spawn_x = x;
	map->spawn_y = y;
	return (SPAWN);
}

static int	fill_map(t_map *map, t_file *start_map)
{
	int		y;
	int		x;
	t_file	*tmp;
	
	y = 0;
	tmp = start_map;
	while (y < map->height)
	{
		x = 0;
		map->block[y] = ft_calloc(map->width + 1, sizeof(t_block));
		if (!map->block[y])
		{
			ft_putstr_fd(MALLOC_ERROR, 2);
			free_map(map);
			return (0);
		}
		while (tmp->line[x])
		{
			map->block[y][x] = block_type(tmp->line[x], map, x, y);
			x++;
		}
		y++;
		tmp = tmp->next;
	}
	return (1);
}

static void	get_size(t_map *map, t_file *start_map)
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
			return ;
		tmp = tmp->next;
	}
}

int	copy_map(t_map *map)
{
	t_file	*start_map;
	
	start_map = skip_textures(map->map_file);
	t_file	*tmp = start_map;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
	get_size(map, start_map);
	printf ("width : %d, height : %d\n", map->width, map->height);
	map->block = ft_calloc(map->height + 1, sizeof(t_block *));
	if (!map->block)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		free_map(map);
		return (0);
	}
	if (!fill_map(map, start_map))
		return (0);

	printf("JE PRINT LA \n");
	for(int y = 0; y < map->height; y++)
	{
		for(int x = 0; x < map->width - 1; x++)
			printf("%d", map->block[y][x]);
		printf("\n");
	}
	printf ("spawX : %d, spawnY : %d\n", map->spawn_x, map->spawn_y);
	return (1);
}
