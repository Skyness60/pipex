/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:34:58 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 05:52:21 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

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
}

int	ppx_error(t_error_code code, char **av, int ac, char *cmd)
{
	if (code == ERR_FILE_NOT_FOUND)
		return (ft_dprintf(2, "pipex: %s: No such file or directory\n",
				av[1]), 1);
	else if (code == ERR_ARGS)
		return (ft_dprintf(2,
				"pipex: syntax error near unexpected token `%s'\n",
				av[ac - 1]), 2);
	else if (code == ERR_PERMISSION_DENIED)
		return (ft_dprintf(2, "pipex: %s: Permission denied\n", cmd), 1);
	else if (code == ERR_CMD_NOT_FOUND)
		return (ft_dprintf(2, "pipex: %s: command not found\n", cmd), 127);
	else if (code == ERR_PIPE_FAILURE)
		return (ft_dprintf(2, "pipex: pipe failure\n"), 1);
	else if (code == ERR_FORK_FAILURE)
		return (ft_dprintf(2, "pipex: fork failure\n"), 1);
	else if (code == ERR_HEREDOC)
		return (ft_dprintf(2, "pipex: fork failure\n"), 1);
	else
		return (ft_dprintf(2, "pipex: unknown error\n"), 1);
}

int	take_path_exec(char **av, char **envp, t_ppx *ppx, int i)
{
	if (ppx_add_back(&ppx, ppx_new(envp)) == -1)
		return (0);
	if (pipe(ppx->pipe_fd) == -1)
		return (ppx_error(ERR_PIPE_FAILURE, av, 0, 0), ppx_del(&ppx), 0);
	exec_child_first(ppx, av[2], av[1]);
	while (av[i + 1])
	{
		i = middle_cmd(&ppx, i, envp, av);
		if (i == -1)
			return (ppx_del(&ppx), 0);
	}
	exec_child_last(ppx, av[i - 1], av[i], false);
	close(ppx->pipe_fd[0]);
	close(ppx->pipe_fd[1]);
	ppx_del(&ppx);
	return (i);
}

int	main(int ac, char **av, char **envp)
{
	int		i;
	t_ppx	*ppx;
	int		status;
	int		exit_status;
	int		child_status;

	i = 4;
	exit_status = 0;
	status = 0;
	if (ac < 5)
		return (ppx_error(1, av, ac, 0), 2);
	ppx = NULL;
	i = process_arguments(ac, av, envp, ppx);
	while (i > 2)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			child_status = WEXITSTATUS(status);
			if (child_status != 0)
				exit_status = child_status;
		}
		i--;
	}
	return (exit_status);
}
