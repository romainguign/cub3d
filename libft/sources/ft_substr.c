/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:41:45 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/30 14:28:34 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	total_len;
	char	*new_str;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s) <= len)
		total_len = ft_strlen(s) - start + 1;
	else
		total_len = len + 1;
	new_str = malloc(sizeof(char) * (total_len));
	if (new_str == 0)
		return (0);
	while (i < len && s[i + start])
	{
		new_str[i] = s[i + start];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
