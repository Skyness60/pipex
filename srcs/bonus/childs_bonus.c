/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:45:05 by sperron           #+#    #+#             */
/*   Updated: 2024/09/05 16:06:26 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	ft_exec_infile(char *path, char **cmds, t_ppx *ppx, char *cmd)
{
	if (path[0] == '0' && path[1] == 0 && (ft_strncmp(ppx->paths[0], "0",
				2) != 0))
	{
		ppx_error(ERR_CMD_NOT_FOUND, cmds, 0, cmd);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(127);
		return ;
	}
	if (execve(path, cmds, ppx->envp) == -1)
	{
		perror(cmds[0]);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(1);
		return ;
	}
	exit(0);
}

static void	ft_exec_outfile(char *path, char **cmds, t_ppx *ppx, char *cmd)
{
	if (path[0] == '0' && path[1] == 0 && (ft_strncmp(ppx->paths[0], "0",
				2) != 0))
	{
		ppx_error(ERR_CMD_NOT_FOUND, cmds, 0, cmd);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(127);
		return ;
	}
	if (execve(path, cmds, ppx->envp) == -1)
	{
		perror(cmds[0]);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(1);
		return ;
	}
	exit(1);
}

void	exec_child_first(t_ppx *ppx, char *cmd, char *file)
{
	pid_t	pid;
	char	*path;
	char	**cmds;

	cmds = split_with_quotes(cmd, ' ');
	path = find_path(ppx->paths, cmds[0]);
	if (!cmds || !path)
		return (ft_free_strs(cmds), free(path), ppx_del(&ppx));
	pid = fork();
	if (pid == -1)
		return (ppx_error(5, cmds, 0, cmd), ft_free_strs(cmds),
			free(path), ppx_del(&ppx));
	else if (pid == 0)
	{
		if (file_to_pipe(file, ppx) == 1)
			return (ft_exec_infile(path, cmds, ppx, cmd));
		else
			return (free(path), ft_free_strs(cmds), ppx_del(&ppx),
				exit(1));
	}
	else
		return (ft_free_strs(cmds), free(path));
}

void	exec_child_last(t_ppx *ppx, char *cmd, char *file, bool heredoc)
{
	pid_t	pid;
	char	*path;
	char	**cmds;

	cmds = split_with_quotes(cmd, ' ');
	path = find_path(ppx->paths, cmds[0]);
	if (!cmds || !path)
		return (ft_free_strs(cmds), free(path), ppx_del(&ppx));
	pid = fork();
	if (pid == -1)
		return (ppx_error(5, cmds, 0, cmd), ft_free_strs(cmds),
			free(path), ppx_del(&ppx));
	else if (pid == 0)
	{
		if (pipe_to_file(file, ppx, heredoc) == 1)
			return (ft_exec_outfile(path, cmds, ppx, cmd));
		else
			return (free(path), ft_free_strs(cmds), ppx_del(&ppx),
				exit(EXIT_FAILURE));
	}
	else
		return (ft_free_strs(cmds), free(path));
}

void	exec_child_midle(t_ppx *ppx, char *cmd)
{
	pid_t	pid;
	char	*path;
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	path = find_path(ppx->paths, cmds[0]);
	if (!cmds || !path)
		return (ft_free_strs(cmds), free(path), ppx_del(&ppx));
	pid = fork();
	if (pid == -1)
		return (ft_free_strs(cmds), free(path), ppx_del(&ppx));
	else if (pid == 0)
	{
		pipe_to_pipe(ppx->prev->pipe_fd, ppx->pipe_fd, ppx);
		return (ft_exec_infile(path, cmds, ppx, cmd));
	}
	else
		return (ft_free_strs(cmds), free(path));
}
