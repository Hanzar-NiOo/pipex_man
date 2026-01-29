/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:12:50 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/08 23:58:22 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	unsigned int	idx;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (dest == NULL && src == NULL)
		return (NULL);
	idx = 0;
	if (src > dest)
	{
		while (idx < num)
		{
			dest[idx] = src[idx];
			idx++;
		}
	}
	else
	{
		while (0 < num--)
			dest[num] = src[num];
	}
	return (dest);
}
