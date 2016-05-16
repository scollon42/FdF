/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:13:32 by scollon           #+#    #+#             */
/*   Updated: 2016/01/06 12:21:34 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_base(unsigned int n, unsigned int base)
{
	char	number[16];

	ft_strcpy(number, "0123456789ABCDEF");
	if (n > 0)
	{
		ft_base(n / base, base);
		ft_putchar(number[n % base]);
	}
}
