/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:54:28 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 08:07:00 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			i;
	size_t		size;
	char		*new;

	i = -1;
	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (!(new = ft_strnew(size)))
		return (NULL);
	while (s[++i])
		new[i] = f(i, s[i]);
	return (new);
}
