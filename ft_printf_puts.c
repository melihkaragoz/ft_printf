/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:39:33 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/19 07:52:57 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!str)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	len = ft_strlen(str);
	while (str[i])
		write(1, str + (i++), 1);
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	char	*s;
	int		len;

	s = ft_itoa(nb);
	len = ft_strlen(s);
	free(s);
	if (nb == -2147483648)
	{
		ft_putstr("-2");
		ft_putnbr(147483648);
		return (11);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (len);
}
