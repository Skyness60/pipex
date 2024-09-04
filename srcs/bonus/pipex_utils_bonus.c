/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:03:40 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 16:47:58 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*road;
	char	*temp;

	i = 0;
	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		road = ft_strjoin(temp, cmd);
		free(temp);
		if (!road)
			return (NULL);
		if (access(road, F_OK) == 0)
			return (road);
		else
			free(road);
		i++;
	}
	return (ft_strdup("0"));
}

void	close_pipe(t_ppx *ppx)
{
	if (!ppx)
		return ;
	while (ppx->prev)
		ppx = ppx->prev;
	while (ppx)
	{
		close(ppx->pipe_fd[0]);
		close(ppx->pipe_fd[1]);
		ppx = ppx->next;
	}
}

char	**find_paths(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!envp[i])
		return (ft_split(strdup("0"), ' '));
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

int	middle_cmd(t_ppx **ppx, int i, char **envp, char **av)
{
	if (ppx_add_back(ppx, ppx_new(envp)) == -1)
		return (-1);
	*ppx = last_pip(*ppx);
	if (pipe((*ppx)->pipe_fd) == -1)
		return (perror("pip2"), -1);
	exec_child_midle(*ppx, av[i - 1]);
	close((*ppx)->prev->pipe_fd[0]);
	close((*ppx)->prev->pipe_fd[1]);
	i++;
	return (i);
}
