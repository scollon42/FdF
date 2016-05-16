/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:01:46 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 07:46:11 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (s[len] == c)
		return ((char *)&s[len]);
	while (len)
	{
		if (s[--len] == (unsigned char)c)
			return ((char *)&s[len]);
	}
	return (NULL);
}
