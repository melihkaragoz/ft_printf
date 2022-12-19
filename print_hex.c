/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:43:02 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/19 07:55:17 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_int(unsigned int nb)
{
	char	*s;
	int		len;

	s = ft_unsigned_itoa(nb);
	len = ft_strlen(s);
	free(s);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (len);
}

int	ft_print_hex(unsigned int nb, char x)
{
	int	tmp;

	tmp = 0;
	if (nb == 0)
	{
		ft_putstr("0");
		return (1);
	}
	if (nb >= 16)
		tmp += ft_print_hex(nb / 16, x);
	if (x == 'x')
		tmp += write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (x == 'X')
		tmp += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	return (tmp);
}

int	ft_print_ptr(unsigned long nb, char x)
{
	int	tmp;

	(void)x;
	tmp = 0;
	if (nb >= 16)
		tmp += ft_print_ptr(nb / 16, x);
	if (x == 'x')
		tmp += write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (x == 'X')
		tmp += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	return (tmp);
}
