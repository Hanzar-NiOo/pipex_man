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

	ft_argc_check(argc);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		ft_exit_failure(argv[1], EXISTENCE, EXIT_FAILURE);
	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
		ft_exit_failure(argv[4], EXISTENCE, EXIT_FAILURE);
	if (pipe(pip) == -1)
		ft_exit_failure(NULL, PIPE, EXIT_FAILURE);
	ft_pip_f_process(argv[2], fd_infile, pip, env);
	ft_pip_s_process(argv[3], fd_outfile, pip, env);
	close(pip[0]);
	close(pip[1]);
	close(fd_infile);
	close(fd_outfile);
	wait(NULL);
	wait(NULL);
	return (0);
}
