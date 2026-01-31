/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:28:58 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/30 02:10:18 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_failure(char *str, t_error type, int code)
{
	log_error(str, type);
	exit(code);
}

void	exit_success(int code)
{
	exit(code);
}

void	log_error(char *str, t_error type)
{
	ft_putstr_fd("pipex: ", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (type == ARGUMENTS)
		ft_putstr_fd(": Incorrect number of arguments\n", 2);
	if (type == MALLOC)
		ft_putstr_fd(": memory allocation failed\n", 2);
	if (type == EXISTENCE)
		ft_putstr_fd(": No such file or directory\n", 2);
	if (type == PERMISSION)
		ft_putstr_fd(": Permission denied\n", 2);
	if (type == COMMAND)
		ft_putstr_fd(": command not found\n", 2);
	if (type == DIRECTORY)
		ft_putstr_fd(": Is a directory\n", 2);
	if (type == PIPE)
		ft_putstr_fd(": pipe() failed on get_pipe_fd()\n", 2);
	if (type == FORK)
		ft_putstr_fd(": fork() failed in pip_process.c\n", 2);
	if (type == DUP2)
		ft_putstr_fd(": dup2() failed on child_process()\n", 2);
}

// void	cmd_error_handling(char *cmd)
// {
// 	if (access(cmd, F_OK) == -1)
// 	{
// 		if (ft_strchr(cmd, '/'))
// 			exit_failure(cmd, EXISTENCE, EXIT_CMD_NOT_FOUND);
// 		else
// 			exit_failure(cmd, COMMAND, EXIT_CMD_NOT_FOUND);
// 	}
// 	if (access(cmd, X_OK) == 0 && ft_strchr(cmd, '/'))
// 		exit_failure(cmd, DIRECTORY, EXIT_CMD_NOT_EXECUTABLE);
// 	else if (access(cmd, X_OK) == 0 && !ft_strchr(cmd, '/'))
// 		exit_failure(cmd, COMMAND, EXIT_CMD_NOT_FOUND);
// 	exit_failure(cmd, PERMISSION, EXIT_CMD_NOT_EXECUTABLE);
// }

void	log_guide_instructions(void)
{
	ft_putstr_fd("\nThis is how to execute the program:"
		"\n\t./pipex <file1> <cmd1> <cmd2> <file2>\n"
		"\n\tfile1, file2\t: file names of infile and outfile;"
		"\n\tcmd1, cmd2\t: shell commands with respective parameters;"
		"\n", 2);
}
