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

void	argc_check(int argc)
{
	if (argc != 5)
	{
		log_error("Error", ARGUMENTS);
		log_guide_instructions();
		exit(EXIT_FAILURE);
	}
}

int	valid_cmd_arg(char *cmd)
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
