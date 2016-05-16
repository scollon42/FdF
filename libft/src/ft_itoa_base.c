/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:21:45 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 09:21:57 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen_base(long n, int *abs, int base)
{
	int		len;

	len = 0;
	*abs = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		*abs = -1;
		len += 1;
		base != 10 ? len -= 1 : 0;
	}
	while (n > 0)
	{
		n /= base;
		len += 1;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	int		abs;
	int		conv;
	char	*ret;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_nbrlen_base((long)value, &abs, base);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ret[len] = '\0';
	ret[0] = (abs == -1 ? '-' : 0);
	while (--len > 0)
	{
		conv = (value % base) * abs;
		ret[len] = (conv > 9) ? (conv - 10) + 'A' : conv + '0';
		value /= base;
	}
	if (abs == 1 || base != 10)
	{
		conv = (value % base) * abs;
		ret[len] = (conv > 9) ? (conv - 10) + 'A' : conv + '0';
	}
	return (ret);
}
