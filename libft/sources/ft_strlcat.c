/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:21:45 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 14:28:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	total_len;
	size_t	i;

	i = 0;
	if ((dst == 0 || src == 0) && size == 0)
		return (0);
	len_dest = ft_strlen(dst);
	total_len = ft_strlen(src);
	if (len_dest > size)
		return (total_len + size);
	total_len += len_dest;
	while (len_dest + 1 < size && src[i])
	{
		dst[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dst[len_dest] = '\0';
	return (total_len);
}
