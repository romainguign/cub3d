/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:03:38 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/25 17:32:04 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "map_infos.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

/*----------------------------- Errors messages -----------------------------*/
# define MALLOC_ERROR		"cub3d: malloc: failed allocation memory\n"

/*-------------------------------- Utils --------------------------------*/
void	free_all(t_map *map);
int		is_space(char c);
void	free_tab(void **tab);
long long int	ft_atoll(const char *str);


#endif