/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:36:37 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/09 00:17:17 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			idx;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	idx = 0;
	while (idx < n)
	{
		if (str[idx] == chr)
			return ((void *) &str[idx]);
		idx++;
	}
	return (NULL);
}
