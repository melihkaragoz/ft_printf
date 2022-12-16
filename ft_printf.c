/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:48 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/16 10:03:06 by mkaragoz         ###   ########.fr       */
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

int	check_print_type(char *str, va_list va, int i)
{
	int		len;
	char	*news;
	char	newc;

	len = 0;
	if (!str && *str && *str != '%')
		return (0);
	else if(str[i] == 'c')
	{
		newc = va_arg(va,int);
		ft_putchar(newc);
		len++;
	}
	else if(str[i] == 's')
	{
		news = va_arg(va,char*);
		len = ft_putstr(news);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	char *tmp;
	int	pr_len;
	int	i;
	va_list va;

	i = 0;
	pr_len = 0;
	va_start(va,str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1,str+(i++),1);
			pr_len++;
		}
 		else if(str[i] == '%')
		{
			i++;
			pr_len += check_print_type((char *)str,va,i++);
		}
	}
	return (pr_len);
}

// printf("")
