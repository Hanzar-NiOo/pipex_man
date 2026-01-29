/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 08:52:55 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/14 11:27:10 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	to_fill;
	size_t	idx;

	dst_len = ft_strlen(dst);
	to_fill = dstsize - dst_len - 1;
	if (dst_len >= dstsize)
		return (dstsize + ft_strlen(src));
	idx = 0;
	if (to_fill > ft_strlen(src))
	{
		while (src[idx])
		{
			dst[dst_len + idx] = src[idx];
			idx++;
		}
	}
	while (to_fill > 0 && src[idx])
	{
		dst[dst_len + idx] = src[idx];
		idx++;
		to_fill--;
	}
	dst[dstsize] = '\0';
	return (dst_len + ft_strlen(src));
}
