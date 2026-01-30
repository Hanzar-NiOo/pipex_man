/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:17:32 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/09 07:44:53 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	unsigned int	str_len;
	unsigned char	*cpy;
	unsigned int	idx;

	str_len = ft_strlen(str);
	cpy = malloc(str_len * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	idx = 0;
	while (idx < str_len)
	{
		cpy[idx] = str[idx];
		idx++;
	}
	cpy[idx] = '\0';
	return ((char *)cpy);
}
