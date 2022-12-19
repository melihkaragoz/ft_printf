/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:48:03 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/19 07:53:08 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
