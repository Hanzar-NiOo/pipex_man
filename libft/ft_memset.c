/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:12:50 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/08 21:54:15 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	idx;

	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < num)
	{
		*(unsigned char *)(ptr + idx) = (unsigned char)value;
		idx++;
	}
	return (ptr);
}
