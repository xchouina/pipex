/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x-X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:56:11 by xchouina          #+#    #+#             */
/*   Updated: 2022/04/11 11:32:15 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n)
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

void	ft_printing_hex(unsigned int n, int base_len, char *base)
{
	char			c;

	if (n > 0)
	{
		ft_printing_hex(n / base_len, base_len, base);
		c = base[(n % base_len)];
		ft_pf_putchar(c);
	}
}

int	ft_put_hex_nbr(unsigned int n, int base_len, char *base)
{
	if (n == 0)
		return (ft_pf_putchar('0'));
	else
		ft_printing_hex(n, base_len, base);
	return (ft_hex_len(n));
}
