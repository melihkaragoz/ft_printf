/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:44:33 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/19 08:13:45 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
