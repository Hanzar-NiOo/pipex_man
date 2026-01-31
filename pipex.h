/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:11:33 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/27 23:43:53 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define CMD_SUCCESS 1
# define CMD_FAIL 0
# define CMD_EXEC_ERROR -1

# define EXIT_CMD_NOT_EXECUTABLE 126
# define EXIT_CMD_NOT_FOUND 127

typedef enum s_error
{
	ARGUMENTS,
	MALLOC,
	PIPE,
	FORK,
	DUP2,
	EXISTENCE,
	PERMISSION,
	COMMAND,
	DIRECTORY,
}	t_error;

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

# include <stdio.h>

void	log_error(char *str, t_error type);
void	exit_failure(char *str, t_error type, int code);
void	cmd_error_handling(char *cmd);
void	log_guide_instructions(void);
void	exit_success(int code);
void	close_fd(int fd_in, int fd_out, int pip[2]);
// void	ft_err_exit(char *err_msg);
void	argc_check(int argc);
int		valid_cmd_arg(char *cmd);
void	pip_f_process(char *cmd, int fd, int pip[2], char **env);
void	pip_s_process(char *cmd, int fd, int pip2[2], char **env);

#endif
