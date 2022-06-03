/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c-s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:53:54 by xchouina          #+#    #+#             */
/*   Updated: 2022/04/11 11:32:17 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_pf_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pf_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_pf_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_pf_putchar(str[i]);
		i++;
	}
	return (i);
}
