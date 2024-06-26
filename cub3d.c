/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:03:45 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/26 10:14:48 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	
	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (1);
	}
	map = parse_map(argv[1]);
	if (!map)
		return (1);
	free_all(map);
	return (0);
}
