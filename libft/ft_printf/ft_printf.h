/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roguigna <roguigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:41:37 by roguigna          #+#    #+#             */
/*   Updated: 2023/11/16 12:15:57 by roguigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_len(char c);
int	ft_putstr_len(char *str);
int	ft_putnbr(long long int n, int len);
int	ft_putnbr_len(long int nbr, char *base);
int	ft_putnb_hex(long long nbr, char *base);
int	ft_putpointer(va_list arg_list);
int	ft_error(char c);

#endif
