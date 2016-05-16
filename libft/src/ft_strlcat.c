/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:44:10 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 16:41:45 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst1;
	char const	*src1;
	size_t		n;
	size_t		dlen;

	dst1 = dst;
	src1 = (char *)src;
	n = size;
	while (*dst1 != 0 && n-- != 0)
		dst1++;
	dlen = dst1 - dst;
	if ((n = size - dlen) == 0)
		return (dlen + ft_strlen(src1));
	while (*src1 != 0 && n != 0)
	{
		if (n != 1)
		{
			*dst1++ = *src1;
			n--;
		}
		src1++;
	}
	*dst1 = 0;
	return (dlen + (src1 - src));
}
