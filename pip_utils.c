/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:35:38 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/31 15:40:53 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int fd_in, int fd_out, int pip[2])
{
	if (fd_in)
		close(fd_in);
	if (fd_out)
		close(fd_out);
	close(pip[0]);
	close(pip[1]);
}
