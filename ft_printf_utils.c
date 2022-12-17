/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:09:02 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/17 03:33:10 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
		write(1,str+(i++),1);
	return (len);
}

void	ft_putchar(char c)
{
	write(1,&c,1);
}

int	ft_putnbr(int nb)
{
 	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return (ft_strlen(ft_itoa(nb)));
}

int ft_print_hex(unsigned long nb, char x)
{
	(void)x;
	int tmp = 0;
	if (nb >= 16)
		tmp += ft_print_hex(nb / 16,x);
	if (x == 'x')
		tmp += write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (x == 'X')
		tmp += write(1, &"0123456789ABCDEF"[nb % 16], 1);
	return tmp;
}

int	check_print_type(char *str, va_list va, int i)
{
	int		len;

	len = 0;
	if (!str && *str && *str != '%')
		return (0);
	else if(str[i] == 'c')
	{
		ft_putchar(va_arg(va,int));
		len++;
	}
	else if (str[i] == 's')
		len = ft_putstr(va_arg(va,char*));
	else if (str[i] == 'd' || str[i] == 'i')
		len = ft_putnbr(va_arg(va,int));
	else if (str[i] == 'p')
	{
		len = ft_putstr("0x");
		len += ft_print_hex(va_arg(va,unsigned long),'x');
	}
	else if (str[i] == 'x' || str[i] == 'X')
		len = ft_print_hex(va_arg(va,unsigned long),str[i]);
	else if (str[i] == '%')
	{
		ft_putchar('%');
		len++;
	}
	else
		return (0);
	return (len);
}
