/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d-i-u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:54:53 by xchouina          #+#    #+#             */
/*   Updated: 2022/04/11 11:32:16 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putnbr_base(int n, int base_len, char *base)
{
	char	c;
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{	
		ft_pf_putchar('-');
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base_len, base);
	c = base[(nb % base_len)];
	write(1, &c, 1);
	return (ft_len(n));
}

int	ft_put_unsigned_nbr(unsigned int n, int base_len, char *base)
{
	char			c;
	unsigned int	len;
	unsigned int	nalt;

	len = 0;
	nalt = n;
	if (nalt <= 0)
		len = 1;
	while (nalt)
	{
		len++;
		nalt = nalt / 10;
	}
	if (n >= (unsigned)base_len)
		ft_put_unsigned_nbr(n / base_len, base_len, base);
	c = base[(n % base_len)];
	write(1, &c, 1);
	return (len);
}
