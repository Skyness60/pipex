/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:59:06 by sperron           #+#    #+#             */
/*   Updated: 2024/09/02 10:41:53 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

static void	found_and_execute(char **cmd, char **envp, t_pipex	**pipex)
{
	char	*cmd_path;

	cmd_path = found_path(envp, cmd[0]);
	if (cmd_path == NULL)
	{
		ft_free(cmd);
		ft_ppxclear(pipex);
		exit(127);
	}
	if (exec(cmd, cmd_path, envp) == -1)
	{
		ft_free(cmd);
		free(cmd_path);
		ft_ppxclear(pipex);
		exit(127);
	}
}

static int	child_exec(int cmd_i, char **argv, char **envp, t_pipex	**pipex)
{
	char	**cmd;

	if (argv[cmd_i][0] == '\0')
	{
		ft_ppxclear(pipex);
		exit(5);
	}
	cmd = split_with_quotes(argv[cmd_i], ' ');
	if (cmd == NULL)
	{
		ft_ppxclear(pipex);
		exit(EXIT_FAILURE);
	}
	found_and_execute(cmd, envp, pipex);
	return (0);
}

static void close_all_fds(t_pipex *pipex)
{
    close(pipex->fd[0]);
    close(pipex->fd[1]);
    // Ajoutez ici d'autres descripteurs de fichiers spécifiques à fermer si nécessaire
}

static void free_pipex(t_pipex *pipex)
{
    t_pipex *temp;

    while (pipex)
    {
        temp = pipex;
        pipex = pipex->next;
        free(temp);
    }
}


int middle_child(int *cmd_i, t_pipex **pipex, char **av, char **env)
{
    t_pipex *new_stack_node;

    new_stack_node = ft_ppxnew((*cmd_i)++);
    if (new_stack_node == NULL)
        clear_and_exit(av, pipex);
    ft_ppxadd_back(pipex, new_stack_node);
    if (pipe((new_stack_node)->fd) == -1)
        clear_and_exit(av, pipex);
    new_stack_node->pid = fork();
    if (new_stack_node->pid == -1)
        clear_and_exit(av, pipex);
    if (new_stack_node->pid == 0)
    {
        close_all_fds(*pipex); // Fermer les descripteurs de fichiers spécifiques
        if (fd_childs(new_stack_node) == -1)
            exit(EXIT_FAILURE);
        if (child_exec(new_stack_node->cmd_i, av, env, pipex) == -1)
            exit(EXIT_FAILURE);
        close(new_stack_node->fd[0]);
        close(new_stack_node->fd[1]);
        free_pipex(*pipex); // Libérer la mémoire allouée
        exit(EXIT_SUCCESS);
    }
    close(new_stack_node->fd[0]);
    close(new_stack_node->fd[1]);
    return (new_stack_node->status);
}
