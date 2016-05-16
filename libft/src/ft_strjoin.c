/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 07:55:55 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 16:41:32 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	size;
	char	*join;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = ft_strnew(size + 1)))
		return (NULL);
	while (i < size + 1)
		join[i++] = (*s1 != 0 ? *s1++ : *s2++);
	join[i] = 0;
	return (join);
}
