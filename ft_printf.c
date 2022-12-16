/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:48 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/16 13:10:05 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
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
	va_end(va);
	return (pr_len);
}
