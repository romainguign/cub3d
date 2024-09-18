/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsoloher <tsoloher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:03:45 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/18 11:06:06 by tsoloher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	if (argc != 2)
	{
		ft_putstr_fd("cub3d: invalid number of arguments\n", 2);
		return (1);
	}
	cube = ft_calloc(1, sizeof(t_cube));
	if (!cube)
		return (0);
	cube->map = parse_map(argv[1]);
	if (!cube->map)
	{
		free(cube);
		return (1);
	}
	start_game(cube);
	free_all(cube);
	return (0);
}
