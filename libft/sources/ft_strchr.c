/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:18:07 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/04 14:23:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && (unsigned char)s[i] != (unsigned char)c)
		i++;
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (0);
}
