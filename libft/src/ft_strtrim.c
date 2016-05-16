/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:53:40 by scollon           #+#    #+#             */
/*   Updated: 2016/02/01 08:57:50 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*trim;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	len = i > len ? 1 : len - i + 2;
	if (!(trim = ft_strnew(len)))
		return (NULL);
	while (--len > 0)
		trim[j++] = s[i++];
	return (trim);
}
