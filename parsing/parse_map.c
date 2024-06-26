/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:40:35 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/26 15:12:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*fill_map(int fd)
{
	t_map	*map;
	
	map	= ft_calloc(1, sizeof(t_map));
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
		ft_putstr_fd("cub3d: invalid extension map file: needed '.cub'\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("cub3d");
		return (-1);
	}
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
	return (map);
	return (NULL);
}
