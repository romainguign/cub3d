/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:41:47 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/16 10:49:27 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_len(char *str)
{
	int		len;

	if (!str)
	{
		len = ft_putstr_len("(null)");
		return (len);
	}
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(long long int n, int len)
{
	long long	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = n * -1;
		len += ft_putchar_len('-');
		len = ft_putnbr(nbr, len);
	}
	else if (n > 9)
	{
		len = ft_putnbr(n / 10, len);
		n = n % 10 + 48;
		len += ft_putchar_len(nbr);
	}
	else if (n < 10)
	{
		n = n % 10 + 48;
		len += ft_putchar_len(nbr);
	}
	return (len);
}

int	ft_putpointer(va_list arg_list)
{
	int		len;
	va_list	tmp;

	va_copy(tmp, arg_list);
	if (va_arg(tmp, void *) == NULL)
	{
		len = ft_putstr_len("(nil)");
		va_end(tmp);
		return (len);
	}
	len = 2;
	write(1, "0x", 2);
	len += ft_putnb_hex(va_arg(arg_list, long long int), "0123456789abcdef");
	va_end(tmp);
	return (len);
}

int	ft_error(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (-1);
}
