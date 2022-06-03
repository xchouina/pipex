/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:59:19 by xchouina          #+#    #+#             */
/*   Updated: 2022/04/11 11:32:18 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_pf_strlen(char *str);
int		ft_pf_putchar(int c);
int		ft_pf_putstr(char *str);

int		ft_ptr_len(unsigned long long n);
int		ft_putptr(unsigned long long p, int base_len, char *base);
void	ft_printing_ptr(unsigned long long n, int base_len, char *base);

int		ft_len(int n);
int		ft_putnbr_base(int n, int base_len, char *base);
int		ft_put_unsigned_nbr(unsigned int n, int base_len, char *base);

int		ft_hex_len(unsigned int n);
int		ft_put_hex_nbr(unsigned int n, int base_len, char *base);
void	ft_printing_hex(unsigned int n, int base_len, char *base);

int		ft_what_arg_r_u(char c, va_list args);
int		ft_printf(const char *str, ...);
#endif