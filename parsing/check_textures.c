/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:04:05 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/19 17:58:09 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_access(char *texture)
{
	int fd;
	
	fd = open(texture, O_DIRECTORY);
	if (fd != -1)
	{
		close (fd);
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(texture, 2);
		ft_putstr_fd(": is a directory\n", 2);
		return (0);
	}
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(texture, 2);
		perror(" ");
		return (0);
	}
	close(fd);
	return (1);
}

static int  check_xpm(char *texture)
{
	int len;

	len = ft_strlen(texture);
	if (len < 4)
		return (0);
	if (texture[len - 1] != 'm' || texture[len - 2] != 'p' || texture[len - 3] != 'x' || texture[len - 4] != '.' )
	{
		ft_putstr_fd("cub3d: ", 2);
		ft_putstr_fd(texture, 2);
		ft_putstr_fd(": bad extension need '.xpm'\n", 2);
		return (0);
	}
	return (1);
}

int check_textures(t_textures *textures, t_map *map)
{
	textures->NO_texture[ft_strlen(textures->NO_texture) - 1] = '\0';
	textures->SO_texture[ft_strlen(textures->SO_texture) - 1] = '\0';
	textures->EA_texture[ft_strlen(textures->EA_texture) - 1] = '\0';
	textures->WE_texture[ft_strlen(textures->WE_texture) - 1] = '\0';

	if (!check_xpm(textures->NO_texture)
		|| !check_xpm(textures->SO_texture) 
		|| !check_xpm(textures->EA_texture)
		|| !check_xpm(textures->WE_texture)
		|| !check_access(textures->NO_texture)
		|| !check_access(textures->NO_texture)
		|| !check_access(textures->NO_texture)
		|| !check_access(textures->NO_texture))
	{
		free_map(map);
		return (0);
	}
	return (1);
}
