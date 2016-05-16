/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:44:33 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 13:33:39 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tdst;
	char	*tsrc;

	tdst = (char *)dst;
	tsrc = (char *)src;
	if (tsrc <= tdst)
	{
		tdst += len - 1;
		tsrc += len - 1;
		while (len--)
			*tdst-- = *tsrc--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
