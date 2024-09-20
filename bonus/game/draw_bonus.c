/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:28:19 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 15:11:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

void	draw_ceiling_floor(t_map *map, t_image *img)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (y < WIN_HEIGHT / 2)
				img_pix_put(img, x, y, map->textures->c);
			else
				img_pix_put(img, x, y, map->textures->f);
			y++;
		}
		x++;
	}
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixels + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_column(t_map *map, t_image *img, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		if (y <= ray->draw_start)
			img_pix_put(img, x, y, map->textures->c);
		else if (y > ray->draw_end)
			img_pix_put(img, x, y, map->textures->f);
		y++;
	}
}
