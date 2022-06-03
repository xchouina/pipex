/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:52:43 by xchouina          #+#    #+#             */
/*   Updated: 2022/04/11 11:32:16 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_printing_ptr(unsigned long long n, int base_len, char *base)
{
	char	c;

	if (n > 0)
	{
		ft_printing_ptr(n / base_len, base_len, base);
		c = base[(n % base_len)];
		ft_pf_putchar(c);
	}
}

int	ft_putptr(unsigned long long p, int base_len, char *base)
{
	int	len;

	len = 0;
	len += ft_pf_putstr("0x");
	if (p == 0)
		len += ft_pf_putchar('0');
	else
	{
		ft_printing_ptr(p, base_len, base);
		len += ft_ptr_len(p);
	}
	return (len);
}
