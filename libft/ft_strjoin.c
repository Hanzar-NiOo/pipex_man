/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:05:31 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/14 12:58:05 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, const char *s2)
{
	unsigned int	idx;
	unsigned char	*result;
	unsigned int	result_len;

	if (!s1 && !s2)
		return (NULL);
	result_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(result_len * sizeof(char));
	if (!result)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	while (s2[idx - ft_strlen(s1)])
	{
		result[idx] = s2[idx - ft_strlen(s1)];
		idx++;
	}
	result[idx] = '\0';
	return ((char *)result);
}
