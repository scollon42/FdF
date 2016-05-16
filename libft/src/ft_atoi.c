/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:34:52 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 10:33:34 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char const *str)
{
	int	i;
	int	value;
	int	negative;

	i = 0;
	value = 0;
	negative = 0;
	while (*str == '\r' || *str == '\v' || *str == '\t' ||
			*str == '\n' || *str == '\f' || *str == ' ')
		str++;
	*str == '-' ? negative = 1 : 0;
	*str == '-' || *str == '+' ? str++ : 0;
	while (*str >= '0' && *str <= '9' && i++ < 19)
		value = (value * 10) + (*(str++) - '0');
	i == 20 && negative ? value = 0 : 0;
	i == 20 && !negative ? value = -1 : 0;
	return (negative && value > 0 ? -value : value);
}
