/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:09:02 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/19 01:20:51 by mkaragoz         ###   ########.fr       */
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
		write(1, str+(i++), 1);
	return (len);
}

int	ft_putchar(char c)
{
	write(1,&c,1);
	return (1);
}

int	ft_putnbr(int nb)
{
	char	*s;
	int		len;

	s = ft_itoa(nb);
	len = ft_strlen(s);
	free(s);
 	if (nb < 0)
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

void	check_print_type(char *str, va_list va, int i, int *lenp)
{
	if (!str && *str && *str != '%')
		return ;
	else if(str[i] == 'c')
		*lenp += ft_putchar(va_arg(va,int));
	else if (str[i] == 's')
		*lenp += ft_putstr(va_arg(va,char*));
	else if (str[i] == 'd' || str[i] == 'i')
		*lenp += ft_putnbr(va_arg(va,int));
	else if (str[i] == 'p')
	{
		*lenp += ft_putstr("0x");
		*lenp += ft_print_hex(va_arg(va,unsigned long),'x');
	}
	else if (str[i] == 'x' || str[i] == 'X')
		*lenp += ft_print_hex(va_arg(va,unsigned long),str[i]);
	else if (str[i] == 'u')
		*lenp += ft_print_unsigned_int(va_arg(va,unsigned int));
	else if (str[i] == '%')
	{
		ft_putchar('%');
		*(lenp) += 1;
	}
	else
		return ;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	digit_finder(int a)
{
	int	result;

	result = 0;
	if (a == 0)
		return (1);
	else if (a == -2147483648)
		return (11);
	else if (a < 0)
	{
		result++;
		a *= -1;
	}
	while (a > 9)
	{
		a /= 10;
		result++;
	}
	return (++result);
}

int	uns_digit_finder(unsigned int a)
{
	int	result;

	result = 0;
	if (a == 0)
		return (1);
	while (a > 9)
	{
		a /= 10;
		result++;
	}
	return (++result);
}

void	ch_sign(int *v, char *res)
{
	*(v) *= -1;
	*(res) = '-';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = digit_finder(n);
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	result[size--] = '\0';
	if (n == 0)
		result[size--] = '0';
	else if (n == -2147483648)
	{
		result[size--] = '8';
		n = -214748364;
	}
	if (n < 0)
		ch_sign(&n, result);
	while (n > 0)
	{
		result[size--] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*result;
	int		size;

	size = uns_digit_finder(n);
	result = malloc(sizeof(char) * size + 1);
	if (!result)
		return (0);
	result[size--] = '\0';
	if (n == 0)
		result[size--] = '0';
	while (n > 0)
	{
		result[size--] = (n % 10) + 48;
		n /= 10;
	}
	return (result);
}
