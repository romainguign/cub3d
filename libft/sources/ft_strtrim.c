/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:47:04 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 14:28:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_inset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_inset(s1[start], set))
		start++;
	if (start > end)
	{
		trimmed = malloc(sizeof(char) * 1);
		trimmed[0] = '\0';
		return (trimmed);
	}
	while (end > 0 && ft_inset(s1[end], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 2));
	if (!trimmed)
		return (0);
	ft_strlcpy(trimmed, s1 + start, end - start + 2);
	return (trimmed);
}
