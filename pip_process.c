/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:40:41 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/30 00:52:14 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **env)
{
	char	**paths;
	char	*tmp;
	int		idx;

	idx = 0;
	paths = NULL;
	while (env[idx])
	{
		if (ft_strncmp("PATH=", env[idx], 5) == 0)
		{
			tmp = ft_strtrim(env[idx], "PATH=");
			paths = ft_split(tmp, ':');
			return (paths);
		}
		idx++;
	}
	return (NULL);
}

static char	*get_execve(char *cmd, char **paths)
{
	char	*exec;
	char	*tmp;
	int		idx;

	if (ft_strncmp(cmd, "./", 2) == 0)
		return (ft_strdup(cmd));
	idx = 0;
	while (paths[idx])
	{
		tmp = ft_strjoin(paths[idx], "/");
		exec = ft_strjoin(tmp, cmd);
		if (access(ft_strjoin(tmp, cmd), F_OK | X_OK) == 0)
			return (exec);
		idx++;
	}
	return (NULL);
}

static void	pip_execve(char *cmd, char **env)
{
	char	**args;
	char	**paths;

	if (invalid_cmd_arg(cmd))
		exit_failure(cmd, COMMAND, EXIT_CMD_NOT_FOUND);
	paths = get_paths(env);
	if (!paths)
		exit_failure("ft_split() on get_paths()", MALLOC, EXIT_FAILURE);
	args = ft_split(cmd, ' ');
	// int	idx = 0;
	// while (args[idx++])
	// 	printf("args[%i] = %s\n", idx, args[idx]);
	if (!args)
		exit_failure("ft_split()", MALLOC, EXIT_FAILURE);
	args[0] = get_execve(args[0], paths);
	// printf("args[0] = %s\n", args[0]);
	if (!args[0])
		exit_failure("ft_strjoin()", MALLOC, EXIT_FAILURE);
	if (access(args[0], F_OK) == 0)
	{
		if (access(args[0], X_OK) == 0)
		{
			if(execve(args[0], args, env) == -1)
				exit_failure(cmd, PERMISSION, EXIT_CMD_NOT_EXECUTABLE);
		}
		else
			exit_failure(cmd, COMMAND, EXIT_CMD_NOT_EXECUTABLE);
	}
	else
		exit_failure(cmd, COMMAND, EXIT_CMD_NOT_EXECUTABLE);
}

void	pip_f_process(char *cmd, int fd_in, int pip[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit_failure("pip_f_process()", FORK, EXIT_FAILURE);
	if (pid == 0)
	{
		if (dup2(fd_in, STDIN_FILENO) < 0)
			exit_failure("pip_f_process()", DUP2, EXIT_FAILURE);
		if (dup2(pip[1], STDOUT_FILENO) < 0)
			exit_failure("pip_f_process()", DUP2, EXIT_FAILURE);
		close_fd(fd_in, '\0', pip);
		pip_execve(cmd, env);
	}
}

void	pip_s_process(char *cmd, int pip[2], int fd_out, char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit_failure("pip_s_process()", FORK, EXIT_FAILURE);
	if (pid == 0)
	{
		if (dup2(pip[0], STDIN_FILENO) == -1)
			exit_failure("pip_s_process()", DUP2, EXIT_FAILURE);
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			exit_failure("pip_s_process()", DUP2, EXIT_FAILURE);
		close_fd('\0', fd_out, pip);
		pip_execve(cmd, env);
	}
}
