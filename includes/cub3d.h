/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:03:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/07/11 18:41:59 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "map_infos.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "parameters.h"

# define PI 3.1415926535

typedef struct	s_image
{
	void	*img;
	char	*pixels;
	int		bpp;
	int		endian;
	int		size_line;
}	t_image ;


typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_image	*img;
}	t_mlx ;

typedef struct	mask
{
	char	**minimap;
}	t_mask ;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	raywall_dist;
	double	wall_x;
}	t_ray ;


typedef struct game
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	t_ray	ray;
	t_mask	*mask;
}	t_game ;

typedef struct s_cube
{
	t_map	*map;
	t_game	*game;
	t_mlx	*mlx;
}	t_cube ;

/*----------------------------- Errors messages -----------------------------*/
# define MALLOC_ERROR		"cub3d: malloc: failed allocation memory\n"

/*---------------------------------- Utils ----------------------------------*/
void	free_map(t_map *map);
void	free_all(t_cube *cube);
int		is_space(char c);
void	free_tab(void **tab);
long long int	ft_atoll(const char *str);

/*---------------------------------- Game -----------------------------------*/
int		start_game(t_cube *cube);
void	img_pix_put(t_image *img, int x, int y, int color);
void	camera_moves(t_game *game, int key_code);
void	player_moves(t_game *game, t_map *map, int key_code);
void	draw_column(t_map *map, t_image *img,t_ray *ray, int x);
int		raycaster(t_game *game, t_map *map, t_mlx *mlx);

//minimap
int		minimap_mask(t_mask *mask);
void    minimap(t_map *map, t_game *game, t_mlx *mlx);

#endif