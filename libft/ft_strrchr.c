/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:09:07 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/08 21:11:54 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned int	idx;
	char			*res;
	char			chr;

	res = NULL;
	str = (char *)s;
	chr = (char)c;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == chr)
			res = &str[idx];
		idx++;
	}
	if (str[idx] == chr)
		res = &str[idx];
	return (res);
}
