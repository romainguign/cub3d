/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:18:24 by roguigna          #+#    #+#             */
/*   Updated: 2024/06/26 14:17:23 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	char	*tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

int	main(void)
{
	char str[] = "Hello world!";

	printf ("str : %s, real len : %ld, my len : %d", str, strlen(str), ft_strlen(str));
	return (0);
}