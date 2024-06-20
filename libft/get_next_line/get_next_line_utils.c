/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:48:40 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 18:23:40 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_utils.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == 0)
		return (0);
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t			i;
	size_t			str_len;
	char			*str;

	i = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (str_len));
	if (str == 0)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strlcat(str, s2, str_len);
	free(s1);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char				*array;

	if (nmemb != 0 && size != 0 && (nmemb * size) / size != nmemb)
		return (0);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	array = malloc(size * nmemb);
	if (array == 0)
		return (0);
	ft_bzero(array, nmemb * size);
	return (array);
}
