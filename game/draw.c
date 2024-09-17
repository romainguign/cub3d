/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:28:19 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/17 17:13:12 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
				img_pix_put(img, x, y, map->textures->C);
			else
				img_pix_put(img, x, y, map->textures->F);
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
		if (y >= ray->draw_start && y <= ray->draw_end)
		{
			if (y == ray->draw_start || y == ray->draw_end)
				img_pix_put(img, x, y, 00000000);
			else
				img_pix_put(img, x, y, 11112657);
		}
		else if (y < ray->draw_start)
			img_pix_put(img, x, y, map->textures->C);
		else
			img_pix_put(img, x, y, map->textures->F);
		y++;
	}
}
