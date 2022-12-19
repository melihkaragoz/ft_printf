/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:09:02 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/19 07:50:31 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_print_type(char *str, va_list va, int i, int *lenp)
{
	if (!str && *str && *str != '%')
		return ;
	else if (str[i] == 'c')
		*lenp += ft_putchar(va_arg(va, int));
	else if (str[i] == 's')
		*lenp += ft_putstr(va_arg(va, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		*lenp += ft_putnbr(va_arg(va, int));
	else if (str[i] == 'p')
	{
		*lenp += ft_putstr("0x");
		*lenp += ft_print_ptr(va_arg(va, unsigned long), 'x');
	}
	else if (str[i] == 'x' || str[i] == 'X')
		*lenp += ft_print_hex(va_arg(va, unsigned long), str[i]);
	else if (str[i] == 'u')
		*lenp += ft_print_unsigned_int(va_arg(va, unsigned int));
	else if (str[i] == '%')
	{
		ft_putchar('%');
		*(lenp) += 1;
	}
	else
		return ;
}
