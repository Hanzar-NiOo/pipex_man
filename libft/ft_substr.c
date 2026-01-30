/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 07:50:02 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/14 12:52:36 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*small;
	unsigned int	idx;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		small = malloc(1 * sizeof(char));
		small[0] = '\0';
		return ((char *)small);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	small = malloc((len + 1) * sizeof(char));
	if (!small)
		return (NULL);
	idx = 0;
	while (idx < len && s[idx])
	{
		small[idx] = s[start + idx];
		idx++;
	}
	small[idx] = '\0';
	return ((char *)small);
}
