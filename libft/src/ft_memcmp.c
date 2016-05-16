/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:54:56 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 14:58:44 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (n--)
	{
		if ((*st1) != (*st2))
			return ((unsigned char)*st1 - (unsigned char)*st2);
		st1++;
		st2++;
	}
	return (0);
}
