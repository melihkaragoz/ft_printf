/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:30:21 by mkaragoz          #+#    #+#             */
/*   Updated: 2022/10/31 20:13:01 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		till_i_collapse;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	till_i_collapse = ft_strlen(s1) - 1;
	while (till_i_collapse && ft_strchr(set, s1[till_i_collapse]))
		till_i_collapse--;
	result = ft_substr(s1, 0, till_i_collapse + 1);
	if (result == NULL)
		return (0);
	return (result);
}
