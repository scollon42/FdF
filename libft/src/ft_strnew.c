/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:34:17 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 08:37:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size > 0)
		new[size--] = 0;
	new[size] = 0;
	return (new);
}
