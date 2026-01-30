/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:20:18 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/09 00:20:27 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	idx;
	size_t	to_find_idx;

	idx = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[idx] && idx < len)
	{
		if (len - idx < ft_strlen(to_find))
			return (NULL);
		if (to_find[0] == str[idx])
		{
			to_find_idx = 0;
			while (to_find[to_find_idx])
			{
				if (to_find[to_find_idx] != str[idx + to_find_idx])
					break ;
				if (to_find_idx == ft_strlen(to_find) - 1)
					return ((char *)str + idx);
				to_find_idx++;
			}
		}
		idx++;
	}
	return (NULL);
}
