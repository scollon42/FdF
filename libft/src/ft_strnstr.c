/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:12:54 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 07:42:26 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	i = -1;
	if (*s2 == 0)
		return ((char*)s1);
	while (s1[++i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = -1;
			while (s2[++j])
			{
				if (s1[i + j] != s2[j] || (i + j) == n)
					break ;
			}
			if (s2[j] == 0)
				return ((char *)&s1[i]);
		}
	}
	return (NULL);
}
