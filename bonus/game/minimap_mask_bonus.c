/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_mask_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:29:16 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

static void	do_circle(int x, int y, int r, t_mask *mask)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		mask->minimap[(int)(y + y1)][(int)(x + x1)] = 1;
		i += 0.1;
	}
}

void	fill_center_circle(t_mask *mask, int y, int x)
{
	while (mask->minimap[y][x] == 0 && x < MINIMAP_RADIUS + 1)
		x++;
	if (x > MINIMAP_RADIUS)
		return ;
	while (mask->minimap[y][x] == 1)
		x++;
	if (x > MINIMAP_RADIUS)
		return ;
	while (mask->minimap[y][x] == 0 && x < MINIMAP_RADIUS * 2)
	{
		mask->minimap[y][x] = 1;
		x++;
	}
}

void	fill_minimap_mask(t_mask *mask)
{
	int	y;

	do_circle(MINIMAP_RADIUS, MINIMAP_RADIUS + 1, MINIMAP_RADIUS, mask);
	y = 0;
	while (mask->minimap[y])
	{
		fill_center_circle(mask, y, 0);
		y++;
	}
}

int	minimap_mask(t_mask *mask)
{
	int	i;

	i = 0;
	mask->minimap = ft_calloc((MINIMAP_RADIUS * 2) + 3, sizeof(char *));
	if (!mask->minimap)
		return (0);
	while (i < MINIMAP_RADIUS * 2 + 2)
	{
		mask->minimap[i] = ft_calloc((MINIMAP_RADIUS * 2) + 2, sizeof(char));
		if (!mask->minimap[i])
			return (0);
		i++;
	}
	fill_minimap_mask(mask);
	return (1);
}
