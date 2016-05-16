/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:23:39 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 09:23:53 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str, int len)
{
	int start;
	int end;

	start = 0;
	end = len - 1;
	while (start < end)
		ft_swap(&str[start++], &str[end--]);
}
