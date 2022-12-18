/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:46:45 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/12/18 15:52:24 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
//# include <stdio.h>

int		check_print_type(char *str, va_list va, int i);
int		ft_print_unsigned_int(unsigned int nb);
int		ft_print_hex(unsigned long nb, char x);
int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
#endif
