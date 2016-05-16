/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:38:58 by scollon           #+#    #+#             */
/*   Updated: 2016/01/06 14:44:38 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_to_hex(char *str)
{
	int i;
	int e;
	int hex;

	i = ft_strlen(str);
	e = 1;
	hex = 0;
	while (--i >= 0 && e <= 1048576)
	{
		if (ft_isdigit(str[i]))
			hex += (str[i] - '0') * e;
		else if ('a' <= str[i] && str[i] <= 'f')
			hex += (str[i] - 'a' + 10) * e;
		else if ('A' <= str[i] && str[i] <= 'F')
			hex += (str[i] - 'A' + 10) * e;
		e *= 16;
	}
	return (hex);
}
