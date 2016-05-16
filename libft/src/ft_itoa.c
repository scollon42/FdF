/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:22:05 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 09:22:08 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa(int nbr)
{
	int		len;
	int		abs;
	char	*ret;

	len = ft_nbrlen((long)nbr, &abs);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ret[len] = '\0';
	abs == -1 ? ret[0] = '-' : 0;
	while (--len > 0)
	{
		ret[len] = ((nbr % 10) * abs) + '0';
		nbr /= 10;
	}
	if (abs == 1)
		ret[len] = (nbr % 10) + '0';
	return (ret);
}
