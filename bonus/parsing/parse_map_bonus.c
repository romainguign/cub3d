/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:40:35 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/24 12:50:59 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static int	check_access(char *filename)
{
	int	fd;

	fd = open (filename, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error\ncub3d: the map ", 2);
		ft_putstr_fd(filename, 2);
		ft_putstr_fd(": is a directory\n", 2);
		close(fd);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("cub3d: map");
		return (-1);
	}
	return (fd);
}

static int	missing_data(t_map *map)
{
	t_textures	*tmp;

	tmp = map->textures;
	if (!tmp->no_texture || !tmp->so_texture || !tmp->we_texture
		|| !tmp->ea_texture || tmp->c == -1 || tmp->f == -1
		|| !map->block || !map->spawn_x)
	{
		free_map(map);
		ft_putstr_fd("Error\ncub3d: missing data in map file\n", 2);
		return (0);
	}
	return (1);
}

static t_map	*fill_map(int fd)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_putstr_fd(MALLOC_ERROR, 2);
		close (fd);
		return (0);
	}
	if (!check_map_file(fd, map))
		return (0);
	if (!fill_textures(map))
		return (0);
	if (!copy_map(map))
		return (0);
	if (!missing_data(map))
		return (0);
	return (map);
}

static int	check_file(char	*filename)
{
	char	*tmp;
	int		fd;

	tmp = filename;
	while (*tmp)
		tmp++;
	if (*(tmp - 1) != 'b' || *(tmp - 2) != 'u' || *(tmp - 3) != 'c'
		|| *(tmp - 4) != '.')
	{
		ft_putstr_fd("Error\ncub3d: invalid extension map file: \
needed '.cub'\n", 2);
		return (-1);
	}
	fd = check_access(filename);
	return (fd);
}

t_map	*parse_map(char	*filename)
{
	t_map	*map;
	int		fd;

	fd = check_file(filename);
	if (fd == -1)
		return (0);
	map = fill_map(fd);
	if (!map)
		return (0);
	if (!is_valid_map(map))
	{
		free_map(map);
		return (0);
	}
	return (map);
}
