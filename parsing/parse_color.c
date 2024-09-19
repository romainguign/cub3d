/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:41:11 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/19 14:51:14 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	check_color_single_color(char *color,
	int i, int space_between, int size_nb)
{
	while (color[i])
	{
		if (is_space(color[i]) && size_nb > 0)
		{
			space_between = 1;
			i++;
		}
		else if (is_space(color[i]))
			i++;
		else if (is_num(color[i]))
		{
			if (space_between == 1)
				return (0);
			i++;
			size_nb++;
		}
		else
			return (0);
	}
	if (size_nb == 0 || size_nb > 3)
		return (0);
	return (1);
}

static int	check_valid_rgb(char **rgb_ascii)
{
	int	i;

	i = 0;
	while (rgb_ascii[i])
	{
		if (i >= 3)
			return (0);
		if (!check_color_single_color(rgb_ascii[i], 0, 0, 0))
			return (0);
		i++;
	}
	return (1);
}

static char	**split_rgb(char *line)
{
	int		i;
	char	**rgb_ascii;

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
	if (!check_valid_rgb(rgb_ascii))
	{
		free_tab((void **)rgb_ascii);
		ft_putstr_fd("cub3d: invalid RGB value\n", 2);
		return (0);
	}
	return (rgb_ascii);
}

int	convert_color(char *line, long long int *color)
{
	long long int	rgb[3];
	char			**rgb_ascii;

	if (*color != -1)
	{
		ft_putstr_fd("cub3d: double definition of the color\n", 2);
		return (0);
	}
	rgb_ascii = split_rgb(line);
	if (!rgb_ascii)
		return (0);
	rgb[0] = ft_atoll(rgb_ascii[0]);
	rgb[1] = ft_atoll(rgb_ascii[1]);
	rgb[2] = ft_atoll(rgb_ascii[2]);
	free_tab((void **)rgb_ascii);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (-2);
	*color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (1);
}
