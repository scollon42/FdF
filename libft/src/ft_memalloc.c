/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:39:33 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 13:08:19 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if ((mem = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	size += 1;
	while (--size > 0)
		mem[size] = 0;
	mem[size] = 0;
	return ((void*)mem);
}
