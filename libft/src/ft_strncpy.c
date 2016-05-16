/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:23:24 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 09:23:27 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;

	i = -1;
	while (++i < n)
	{
		if (*src)
		{
			dst[i] = *src;
			src++;
		}
		else
			dst[i] = 0;
	}
	return (dst);
}
