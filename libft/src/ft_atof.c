/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 10:10:02 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 10:33:47 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	i;
	double	value;
	int		negative;

	i = 1.0;
	value = 0;
	negative = 0;
	while (*str == '\r' || *str == '\v' || *str == '\t' ||
			*str == '\n' || *str == '\f' || *str == ' ')
		str++;
	*str == '-' ? negative = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while (*str >= '0' && *str <= '9')
		value = (value * 10) + (*(str++) - '0');
	if (*str == '.' && (str++))
		while (*str >= '0' && *str <= '9')
			value += (*(str++) - '0') / (i *= 10);
	return (negative && value > 0 ? -value : value);
}
