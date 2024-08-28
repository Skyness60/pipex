/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:25:12 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 07:07:49 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../../../includes/pipex_bonus.h"

static void	found_and_execute(char **cmd, char **envp, t_pipex *node)
{
	char	*path;

	path = found_path(envp, cmd[0]);
	if (!path)
	{
		ft_free(cmd);
		free(node);
		exit(127);
	}
	if (execve(path, (char *const *)cmd, (char *const *)envp) == -1)
	{
		ft_free(cmd);
		free(path);
		free(node);
		exit(127);
	}


}

static int	child_exec(int cmd_i, char **av, char **envp, t_pipex *node)
{
	char	**cmd;

	if (av[cmd_i][0] == '\0')
	{
		if (av[3][0] != '\0' || av[3][0] != ' ')
			free(node);
		exit(5);
	}
	cmd = split_with_quotes(av[cmd_i], ' ');
	if (!cmd)
	{
		free(node);
		exit(EXIT_FAILURE);
	}
	found_and_execute(cmd, envp, node);
	return (0);
}

int	first_child(int *cmd_i, t_pipex **pipex, char **av, char **envp)
{
	t_pipex	*new_stack_node;
	int		cmd_fdr;

	new_stack_node = ft_ppxnew((*cmd_i)++);
	if (!new_stack_node)
		return (-1);
	ft_ppxadd_back(pipex, new_stack_node);
	check_heredoc(av, new_stack_node);
	if (pipe((new_stack_node)->fd) == -1)
		clear_and_exit(av, pipex);
	new_stack_node->pid = fork();
	if (new_stack_node->pid == -1)
		clear_and_exit(av, pipex);
	if (new_stack_node->pid == 0)
	{
		cmd_fdr = infile_child(av, new_stack_node);
		if (cmd_fdr == 2 || cmd_fdr == 3)
			return (cmd_fdr);
		child_exec(new_stack_node->cmd_i, av, envp, new_stack_node);
	}
	if (dup2(new_stack_node->fd[0], STDIN_FILENO) == -1)
		return (close_pipe(new_stack_node->fd), -1);
	return (close_pipe(new_stack_node->fd), new_stack_node->status);
}
