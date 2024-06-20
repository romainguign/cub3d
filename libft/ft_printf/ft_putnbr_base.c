/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:06:17 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/16 12:15:35 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_base(unsigned long long nbr,
	unsigned long long len_base, char *base, int len)
{
	if (nbr >= len_base)
	{
		len = ft_convert_base((nbr / len_base), len_base, base, len + 1);
		write(1, &base[nbr % len_base], 1);
	}
	else if (nbr < len_base)
	{
		write(1, &base[nbr], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr_len(long int nbr, char *base)
{
	long long int	len_base;
	long long int	number;
	int				len;

	len = 0;
	number = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		len++;
		number = -1 * number;
	}
	len_base = 0;
	while (base[len_base])
		len_base++;
	len = ft_convert_base(number, len_base, base, len);
	return (len);
}

int	ft_putnb_hex(long long nbr, char *base)
{
	unsigned long long	len_base;
	unsigned long long	number;
	int					len;

	len_base = 0;
	len = 0;
	number = nbr;
	while (base[len_base])
		len_base++;
	len = ft_convert_base(number, len_base, base, len);
	return (len);
}
