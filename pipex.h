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

// # define STDIN 0
// # define STDOUT 1
// # define STDERR 2

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
	// DUP2,
	EXISTENCE,
	// PERMISSION,	
	COMMAND,
	// DIRECTORY,
}	t_error;

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

// # include <stdio.h>

void	ft_log_error(char *str, t_error type);
void	ft_exit_failure(char *str, t_error type, int code);
void	ft_log_guide_instructions(void);
// void	ft_err_exit(char *err_msg);
int		ft_argc_check(int argc);
int		ft_invalid_cmd_arg(char *cmd);
void	ft_pip_f_process(char *cmd, int fd, int pip[2], char **env);
void	ft_pip_s_process(char *cmd, int fd, int pip2[2], char **env);

#endif
