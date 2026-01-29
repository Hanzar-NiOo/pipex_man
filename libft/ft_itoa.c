/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:10:15 by hnioo             #+#    #+#             */
/*   Updated: 2025/09/09 21:51:32 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	len(long n)
{
	size_t	idx;
	long	ln;

	idx = 0;
	ln = n;
	if (ln == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		idx++;
	}
	while (n > 0)
	{
		n /= 10;
		idx++;
	}
	return (idx);
}

char	*ft_itoa(int n)
{
	size_t	str_len;
	long	num;
	char	*str;

	num = n;
	str_len = len(num);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (num == 0)
		str[0] = '0';
	str[str_len--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[str_len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
