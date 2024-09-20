/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:38:52 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static int	is_texture(char *line)
{
	if (!ft_strncmp("NO", line, 2)
		|| !ft_strncmp("SO", line, 2)
		|| !ft_strncmp("WE", line, 2)
		|| !ft_strncmp("EA", line, 2)
		|| !ft_strncmp("F", line, 1)
		|| !ft_strncmp("C", line, 1))
		return (1);
	return (0);
}

t_file	*skip_textures(t_file *file)
{
	int		i;
	t_file	*tmp;

	tmp = file;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i] && is_space(tmp->line[i]))
			i++;
		if (tmp->line[i] != '\0' && !is_texture(&tmp->line[i]))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int	check_map_file(int fd, t_map *map)
{
	file_to_char(fd, map);
	close (fd);
	return (1);
}
