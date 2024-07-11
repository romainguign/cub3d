/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:28:19 by roguigna          #+#    #+#             */
/*   Updated: 2024/07/11 19:41:15 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->pixels + (y * img->size_line + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_column(t_map *map, t_image *img,t_ray *ray, int x)
{
	int		y;

	y = 0;
	// printf("%d -> %d\n", len_line[0], len_line[1]);
	while (y < WIN_HEIGHT)
	{
		if (y >= ray->draw_start && y <= ray->draw_end)
		{
			// printf("1\n");
			if (y == ray->draw_start || y == ray->draw_end)
				img_pix_put(img, x, y, 00000000);
			else
				img_pix_put(img, x, y, 11112657);
		}
		else if (y < ray->draw_start)
		{
			// printf("2\n");
			img_pix_put(img, x, y, map->textures->C);	
		}
		else
		{
			// printf("3\n");
			img_pix_put(img, x, y, map->textures->F);
		}
		y++;
	}
}