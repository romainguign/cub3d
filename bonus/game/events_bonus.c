/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:30:40 by roguigna          #+#    #+#             */
/*   Updated: 2024/09/20 16:01:18 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_bonus.h"

int	key_realease(int keycode, char *input)
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
	return (1);
}

int	key_press(int keycode, t_cube *cube)
{
	char	*input;

	input = cube->game->input;
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
	if (keycode == XK_Escape)
		destroy(cube);
	return (1);
}
