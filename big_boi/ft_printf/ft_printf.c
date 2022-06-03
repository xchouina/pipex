/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:59:01 by xchouina          #+#    #+#             */
/*   Updated: 2022/04/11 11:32:14 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_what_arg_r_u(char c, va_list args)
{
	int	l;

	l = 0;
	if (c == 'c')
		l = ft_pf_putchar(va_arg(args, int));
	else if (c == 's')
		l = ft_pf_putstr(va_arg(args, char *));
	else if (c == 'p')
		l = ft_putptr(va_arg(args, unsigned long long), 16, "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		l = ft_putnbr_base(va_arg(args, int), 10, "0123456789");
	else if (c == 'u')
		l = ft_put_unsigned_nbr(va_arg(args, unsigned int), 10, "0123456789");
	else if (c == 'x')
		l = ft_put_hex_nbr(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (c == 'X')
		l = ft_put_hex_nbr(va_arg(args, unsigned long), 16, "0123456789ABCDEF");
	else if (c == '%')
		l = ft_pf_putchar('%');
	return (l);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_what_arg_r_u(str[++i], args);
		else
			len += ft_pf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
