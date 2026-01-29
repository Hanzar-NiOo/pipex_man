/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 09:24:33 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/14 12:57:55 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, const char *set)
{
	size_t	idx;
	size_t	end;

	idx = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[idx]))
		idx++;
	while (ft_strrchr(set, s1[end]))
		end--;
	return ((char *)ft_substr(s1, idx, end - (idx - 1)));
}
