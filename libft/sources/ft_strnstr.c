/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:26:33 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 14:28:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (little[0] == '\0' || ((!big || !little) && len == 0))
		return ((char *)big);
	if (ft_strlen(big) < ft_strlen(little) || len == 0)
		return (0);
	while (big[i] && i < len)
	{
		k = i;
		while (big[k] == little[j] && big[k]
			&& k < len)
		{
			if (!little[j + 1])
				return ((char *)big + i);
			j++;
			k++;
		}
		j = 0;
		i++;
	}
	return (0);
}
