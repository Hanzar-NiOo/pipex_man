/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:33:11 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/30 00:56:48 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	pip[2];
	int	fd_infile;
	int	fd_outfile;

	argc_check(argc);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile < 0)
		exit_failure(argv[1], EXISTENCE, EXIT_FAILURE);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile < 0)
		exit_failure(argv[4], EXISTENCE, EXIT_FAILURE);
	if (pipe(pip) < 0)
		exit_failure(NULL, PIPE, EXIT_FAILURE);
	pip_f_process(argv[2], fd_infile, pip, env);
	pip_s_process(argv[3], pip, fd_outfile, env);
	close_fd(fd_infile, fd_outfile, pip);
	wait(NULL);
	wait(NULL);
	return (0);
}
