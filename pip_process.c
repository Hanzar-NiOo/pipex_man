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

static char	**ft_get_paths(char **env)
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
	if (!paths)
		ft_log_error("ft_split() from get_path()", MALLOC);
	return (NULL);
}

static char	*ft_get_execve(char *cmd, char **paths)
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
		// else
			// cmd_fail
		idx++;
	}
	if (!exec)
		ft_exit_failure(NULL, COMMAND, EXIT_FAILURE);
	// exit_failure(data, "ft_split() on get_abs_path()",
	// 	MALLOC, EXIT_FAILURE);
	return (NULL);
}

static void	ft_pip_execve(char *cmd, char **env)
{
	char	**args;
	char	**paths;

	paths = ft_get_paths(env);
	if (!paths)
		exit_failure("ft_split() on get_abs_path()", MALLOC, EXIT_FAILURE);
	if (ft_invalid_cmd_arg(cmd))
		exit_failure(cmd, COMMAND, EXIT_CMD_NOT_FOUND);
	args = ft_split(cmd, ' ');
	if (!args)
		exit_failure("ft_split() on execute_command()", MALLOC, EXIT_FAILURE);
	// else
	// error exit
	args[0] = ft_get_execve(args[0], paths);
	if (args[0])
		exit_failure("ft_split() on absolute", MALLOC, EXIT_FAILURE);
		// status = CMD_EXEC_ERROR;
	// if (execv() == -1)
	execve(args[0], args, env);
	// status = CMD_STATUS;
}

void	ft_pip_f_process(char *cmd, int fd, int pip[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_exit_failure(NULL, FORK, EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(fd, STDIN_FILENO);
		dup2(pip[1], STDOUT_FILENO);
		close(fd);
		close(pip[0]);
		close(pip[1]);
		ft_pip_execve(cmd, env);
	}
}

void	ft_pip_s_process(char *cmd, int fd, int pip[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_exit_failure(NULL, FORK, EXIT_FAILURE);
	if (pid == 0)
	{
		dup2(pip[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		close(pip[0]);
		close(pip[1]);
		ft_pip_execve(cmd, env);
	}
}
