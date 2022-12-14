/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:48 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/15 01:11:47 by mkaragoz         ###   ########.fr       */
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

int	check_print_type(char *str,int	i)
{
	int	len;

	len = 0;
	if (!str && *str && *str != '%')
		return (NULL);
	else if(str == 'c')
	{
		ft_putchar(str[++i]);
		len++;
	}
	else if(str == 's')
	{
		len += ft_putstr(str+(++i));
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	char *tmp;
	int	pr_len;
	int	i;

	i = 0;
	tmp = str;

	while (tmp[i])
	{
		if (tmp[i] && tmp[i] != '%')
		{
			write(1,tmp[i++],1);
			pr_len++;
		}
 		else if(tmp[i] == '%')
		{
			i++;
			pr_len += check_print_type(tmp,i);
		}
	}
	return (pr_len);
}

// printf("")
