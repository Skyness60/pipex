/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:25:26 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 05:51:17 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

static void	found_and_execute(char **cmd, char **envp, t_pipex **node)
{
	char	*path;

	path = found_path(envp, cmd[0]);
	if (!path)
	{
		ft_free(cmd);
		ft_ppxclear(node);
		exit(127);
	}
	if (exec(cmd, path, envp) == -1)
	{
		ft_free(cmd);
		free(path);
		ft_ppxclear(node);
		exit(127);
	}
}

static int	child_exec(int cmd_i, char **av, char **envp, t_pipex **node)
{
	char	**cmd;

	if (av[cmd_i][0] == '\0')
	{
		ft_ppxclear(node);
		exit(127);
	}
	cmd = split_with_quotes(av[cmd_i], ' ');
	if (!cmd)
	{
		ft_ppxclear(node);
		exit(127);
	}
	found_and_execute(cmd, envp, node);
	return (0);
}

int	second_child(int cmd_i, t_pipex **pipex, char **av, char **envp)
{
	t_pipex	*new_stack_node;

	new_stack_node = ft_ppxnew(cmd_i);
	if (!new_stack_node)
		clear_and_exit(av, pipex);
	ft_ppxadd_back(pipex, new_stack_node);
	if (pipe((new_stack_node)->fd) == -1)
		exit(EXIT_FAILURE);
	new_stack_node->pid = fork();
	if (new_stack_node->pid == -1)
		clear_and_exit(av, pipex);
	if (new_stack_node->pid == 0)
	{
		if (outfile_child(cmd_i, av, new_stack_node, pipex) == -1)
			return (ft_ppxclear(pipex), -1);
		if (child_exec(cmd_i, av, envp, pipex) != 0)
			return (close_and_clear(new_stack_node->fd, pipex), -1);
	}
	return (close_pipe(new_stack_node->fd), new_stack_node->status);
}
