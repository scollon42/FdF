/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:08:19 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 09:21:10 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = -1;
	if (s1 == NULL || s2 == NULL || s1 == 0 || s2 == 0)
		return (0);
	while (++i < n)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
