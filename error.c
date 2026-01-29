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

void	ft_err_exit(char *err_msg)
{
	write (2, "error\n", 6);
	write (2, err_msg, ft_strlen(err_msg));
	write (2, "\n", 1);
	exit (1);
}

// #include "../includes/pipex.h"

// void	exit_failure(t_pipex *data, char *str, t_error type, int code)
// {
// 	log_error(str, type);
// 	close_fd(data);
// 	free_char_double_pointer(data->path);
// 	exit(code);
// }

// void	exit_success(t_pipex *data, int code)
// {
// 	close_and_free(data);
// 	exit(code);
// }

// void	log_error(char *str, t_error type)
// {
// 	ft_putstr_fd("pipex: ", STDERR);
// 	if (str)
// 		ft_putstr_fd(str, STDERR);
// 	if (type == ARGUMENTS)
// 		ft_putstr_fd(": Incorrect number of arguments\n", STDERR);
// 	if (type == MALLOC)
// 		ft_putstr_fd(": memory allocation failed\n", STDERR);
// 	if (type == EXISTENCE)
// 		ft_putstr_fd(": No such file or directory\n", STDERR);
// 	if (type == PERMISSION)
// 		ft_putstr_fd(": Permission denied\n", STDERR);
// 	if (type == COMMAND)
// 		ft_putstr_fd(": command not found\n", STDERR);
// 	if (type == DIRECTORY)
// 		ft_putstr_fd(": Is a directory\n", STDERR);
// 	if (type == PIPE)
// 		ft_putstr_fd(": pipe() failed on get_pipe_fd()\n", STDERR);
// 	if (type == FORK)
// 		ft_putstr_fd(": fork() failed on pipex()\n", STDERR);
// 	if (type == DUP2)
// 		ft_putstr_fd(": dup2() failed on child_process()\n", STDERR);
// }

// void	cmd_error_handling(t_pipex *data, char *cmd)
// {
// 	if (data->path == NULL)
// 		exit_failure(data, cmd, EXISTENCE, EXIT_CMD_NOT_FOUND);
// 	if (access(cmd, F_OK) == -1)
// 	{
// 		if (ft_strchr(cmd, '/'))
// 			exit_failure(data, cmd, EXISTENCE, EXIT_CMD_NOT_FOUND);
// 		else
// 			exit_failure(data, cmd, COMMAND, EXIT_CMD_NOT_FOUND);
// 	}
// 	if (access(cmd, X_OK) == 0 && ft_strchr(cmd, '/'))
// 		exit_failure(data, cmd, DIRECTORY, EXIT_CMD_NOT_EXECUTABLE);
// 	else if (access(cmd, X_OK) == 0 && !ft_strchr(cmd, '/'))
// 		exit_failure(data, cmd, COMMAND, EXIT_CMD_NOT_FOUND);
// 	exit_failure(data, cmd, PERMISSION, EXIT_CMD_NOT_EXECUTABLE);
// }

// void	log_guide_instructions(void)
// {
// 	ft_putstr_fd("\nThis is how to execute the program:"
// 		"\n\t./pipex <file1> <cmd1> <cmd2> <file2>\n"
// 		"\n\tfile1, file2\t: file names of infile and outfile;"
// 		"\n\tcmd1, cmd2\t: shell commands with respective parameters;"
// 		"\n", STDERR);
// }
