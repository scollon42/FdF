/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 07:55:13 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 16:06:08 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*dup;

	i = -1;
	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if ((dup = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (s1[++i] != 0)
		dup[i] = s1[i];
	dup[i] = 0;
	return (dup);
}
