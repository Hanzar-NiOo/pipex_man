/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:34:27 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/30 00:15:16 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_argc_check(int argc)
{
	if (argc != 5)
	{
		ft_log_error("Error", ARGUMENTS);
		ft_log_guide_instructions();
	}
	return (1);
}

int	ft_invalid_cmd_arg(char *cmd)
{
	int	i;

	if (!cmd || cmd[0] == '\0')
		return (1);
	i = 0;
	while (cmd[i])
	{
		if (ft_isprint(cmd[i]))
			return (0);
		i++;
	}
	return (1);
}
