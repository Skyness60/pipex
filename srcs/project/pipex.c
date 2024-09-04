/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:34:58 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 02:40:54 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}

int	ppx_error(t_error_code code, char **av, int ac, char *cmd)
{
	if (code == ERR_FILE_NOT_FOUND)
		return (ft_dprintf(2, "pipex: %s: No such file or directory\n",
			av[1]), 1);
	else if (code == ERR_ARGS)
		return (ft_dprintf(2, "pipex: syntax error near unexpected token `%s'\n",
			av[ac - 1]), 2);
	else if (code == ERR_PERMISSION_DENIED)
		return (ft_dprintf(2, "pipex: %s: Permission denied\n", cmd), 1);
	else if (code == ERR_CMD_NOT_FOUND)
		return (ft_dprintf(2, "pipex: %s: command not found\n", cmd), 127);
	else if (code == ERR_PIPE_FAILURE)
		return (ft_dprintf(2, "pipex: pipe failure\n"), 1);
	else if (code == ERR_FORK_FAILURE)
		return (ft_dprintf(2, "pipex: fork failure\n"), 1);
	else 
		return (ft_dprintf(2, "pipex: unknown error\n"), 1);
}


static void	ft_exec_infile(char *path, char **cmds, t_ppx *ppx, char *cmd)
{
	if (path[0] == '0' && path[1] == 0 && (ft_strncmp(ppx->paths[0], "0",
				2) != 0))
	{
		ppx_error(ERR_CMD_NOT_FOUND, cmds, 0, cmd);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(0);
		return ;
	}
	if (execve(path, cmds, ppx->envp) == -1)
	{
		perror(cmds[0]);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(0);
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
		exit(1);
		return ;
	}
	if (execve(path, cmds, ppx->envp) == -1)
	{
		perror(cmds[0]);
		free(path);
		ft_free_strs(cmds);
		ppx_del(&ppx);
		exit(EXIT_FAILURE);
		return ;
	}
	exit(EXIT_FAILURE);
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
		return (ft_free_strs(cmds), free(path), ppx_del(&ppx));
	else if (pid == 0)
	{
		if (file_to_pipe(file, ppx) == 1)
			return (ft_exec_infile(path, cmds, ppx, cmd));
		else
			return (free(path), ft_free_strs(cmds), ppx_del(&ppx),
				exit(0));
	}
	else
		return (ft_free_strs(cmds), free(path));
}

void	exec_child_last(t_ppx *ppx, char *cmd, char *file)
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
		return (ft_free_strs(cmds), free(path), ppx_del(&ppx));
	else if (pid == 0)
	{
		if (pipe_to_file(file, ppx) == 1)
			return (ft_exec_outfile(path, cmds, ppx, cmd));
		else
			return (free(path), ft_free_strs(cmds), ppx_del(&ppx),
				exit(EXIT_FAILURE));
	}
	else
		return (ft_free_strs(cmds), free(path));
}


void take_path_exec(char **av, char **envp, t_ppx *ppx)
{
	int i;

	i = 4;
	ppx = NULL;
	if (ppx_add_back(&ppx, ppx_new(envp)) == -1)
		return ;
	if (pipe(ppx->pipe_fd) == -1)
		return (ppx_error(ERR_PIPE_FAILURE, av, 0, 0), ppx_del(&ppx));
	exec_child_first(ppx, av[2], av[1]);
	exec_child_last(ppx, av[i - 1], av[i]);
	close(ppx->pipe_fd[0]);
	close(ppx->pipe_fd[1]);
}
int	test(char **av, int ac)
{
	int	j;
	int	i;

	i = 2;
	while (i < ac - 1)
	{
		j = 0;
		while (av[i][j] == ' ' && av[i][j])
			j++;
		if (av[i][j] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	t_ppx	*ppx;
	int		status;
	int		exit_status;

	i = 4;
	ppx = NULL;
	if (ac != 5)
		return (ppx_error(1, av, ac, 0), 2);
	take_path_exec(av, envp, ppx);
	while (i > 2)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
				return (exit_status);
		}
		i--;
	}
	ppx_del(&ppx);
	return (0);
}


