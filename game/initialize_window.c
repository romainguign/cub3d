/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:41:05 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/09 16:08:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	destroy(t_cube *cube)
{
	mlx_clear_window(cube->mlx->mlx, cube->mlx->win);
	mlx_destroy_image(cube->mlx->mlx, cube->mlx->img->img);
	mlx_destroy_window(cube->mlx->mlx, cube->mlx->win);
	mlx_destroy_display(cube->mlx->mlx);
	mlx_loop_end(cube->mlx->mlx);
	free_all(cube);
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_hook(int kcode, t_cube *cube)
{
	if (kcode == XK_Escape)
		destroy(cube);
	
	return (0);
}

int	key_loop(int kcode, t_cube *cube)
{
	int		modifyed;
	char	*input;

	modifyed = 0;
	input = cube->game->input;
	keydown(kcode, input);
	if (input[0] || input[1])
	{
		player_moves(cube->game, cube->map, input);
		modifyed++;
	}
	if (input[2] || input[3])
	{
		camera_moves(cube->game, input);
		modifyed++;
	}
	if (modifyed > 0)
		raycaster(cube->game, cube->map, cube->mlx);
	printf("x : %f y : %f\n", cube->game->pos_x, cube->game->pos_y);
	return (1);
}

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

void	game_loop(t_map *map, t_mlx *mlx, t_game *game, t_cube *cube)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return ;
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "cube");
	if (mlx->win == NULL)
		return ;
	mlx->img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img->img)
		return ;
	mlx->img->pixels = mlx_get_data_addr(mlx->img->img, &mlx->img->bpp, &mlx->img->size_line, &mlx->img->endian);
	raycaster(game, map, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_key_hook(mlx->win, key_hook, cube);
	mlx_hook(mlx->win, 2, 1L<<0, key_loop, cube);
	mlx_hook(mlx->win, 3, 1L<<0, keyup, game->input);
	mlx_hook(mlx->win, 17, 0L, &destroy, cube);
	mlx_loop(mlx->mlx);
}

int	start_game(t_cube *cube)
{
	cube->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!cube || !init_game(cube))
		return (0);
	game_loop(cube->map, cube->mlx, cube->game, cube);
	return (1);
}
