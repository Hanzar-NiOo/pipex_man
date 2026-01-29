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
			break ;
		}
		idx++;
	}
	if (!paths)
		ft_err_exit ("Env : Paths not found");
	return (paths);
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
		if (access(ft_strjoin(tmp, cmd), X_OK) == 0)
			return (exec);
		idx++;
	}
	if (!exec)
		ft_err_exit ("Pipex : Command not found");
	return (NULL);
}

static void	ft_pip_execve(char *cmd, char **env)
{
	char	**args;
	char	**paths;

	paths = ft_get_paths(env);
	args = ft_split(cmd, ' ');
	args[0] = ft_get_execve(args[0], paths);
	execve(args[0], args, env);
}

void	ft_pip_f_process(char *cmd, int fd, int pip[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_err_exit("Fork : Resource temporarily unavailable");
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
		ft_err_exit("Fork : Resource temporarily unavailable");
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
