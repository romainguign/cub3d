/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:41:29 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/16 11:07:39 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list arg_list, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar_len(va_arg(arg_list, int));
	else if (c == 's')
		len = ft_putstr_len(va_arg(arg_list, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_len(va_arg(arg_list, int), "0123456789");
	else if (c == 'u')
		len = ft_putnb_hex(va_arg(arg_list, unsigned int), "0123456789");
	else if (c == 'x')
		len = ft_putnb_hex(va_arg(arg_list, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_putnb_hex(va_arg(arg_list, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len = ft_putchar_len('%');
	else if (c == 'p')
		len = ft_putpointer(arg_list);
	else
		len = ft_error(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg_list;

	if (!str)
		return (-1);
	len = 0;
	i = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (-1);
			len += ft_check_type(arg_list, str[i + 1]);
			i += 1;
		}
		else
			len += ft_putchar_len(str[i]);
		i++;
	}
	va_end(arg_list);
	return (len);
}
