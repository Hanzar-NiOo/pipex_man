/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 00:24:58 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/09 07:15:33 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			idx;

	total_size = count * size;
	if (total_size == 0)
		return (malloc(0));
	if (count > INT_MAX || size > INT_MAX || total_size > INT_MAX)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < total_size)
		ptr[idx++] = 0;
	return (ptr);
}
