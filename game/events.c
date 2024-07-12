/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:30:40 by roguigna          #+#    #+#             */
/*   Updated: 2024/07/12 11:35:53 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyup(int	keycode, char *input)
{
	if (keycode == XK_w)
		input[0] = 0;
	if (keycode == XK_s)
		input[1] = 0;
	if (keycode == XK_Left)
		input[2] = 0;
	if (keycode == XK_Right)
		input[3] = 0;
	if (keycode == XK_a)
		input[4] = 0;
	if (keycode == XK_d)
		input[5] = 0;
}

void	keydown(int	keycode, char *input)
{
	if (keycode == XK_w)
		input[0] = 1;
	if (keycode == XK_s)
		input[1] = 1;
	if (keycode == XK_Left)
		input[2] = 1;
	if (keycode == XK_Right)
		input[3] = 1;
	if (keycode == XK_a)
		input[4] = 1;
	if (keycode == XK_d)
		input[5] = 1;
}