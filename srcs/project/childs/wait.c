/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:34:53 by sperron           #+#    #+#             */
/*   Updated: 2024/09/01 03:46:50 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

static int	check_cmd_null(char **av, int status, t_pipex *temp)
{
	if (WEXITSTATUS(status) == 2)
		return (ft_printf("pipex: %s: Permission denied\n", av[1]), 1);
	if (WEXITSTATUS(status) == 1)
		return (ft_printf("pipex: %s: No such file or directory\n", av[1]), 0);
	if (WEXITSTATUS(status) == 5)
		return (ft_printf("pipex: %s: command not found\n", av[temp->cmd_i]));
	if (WEXITSTATUS(status) == 127)
		return (ft_printf("pipex: %s: command not found\n", av[temp->cmd_i]),
			127);
	if (WEXITSTATUS(status) == 4)
		return (ft_printf("pipex: %s: Permission denied\n", av[4]), 1);
	return (WEXITSTATUS(status));
}

static t_pipex	*reverse_list(t_pipex *head)
{
	t_pipex *prev;
	t_pipex *current;
	t_pipex *next;

	prev = NULL;
	current = head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

int	wait_childs(t_pipex **pipex, char **av, int *array)
{
	t_pipex	*temp;
	int	i;
	int	first_error_status;
    int current_status;

	if (!pipex || !(*pipex))
		return -1;
	*pipex = reverse_list(*pipex);
    first_error_status = 0;
	i = 0;
	temp = *pipex;
	while (temp)
	{
		if (temp->pid > 0)
			waitpid(temp->pid, &(temp->status), 0);
		current_status = check_cmd_null(av, temp->status, temp);
		array[i] = current_status;
		if (first_error_status == 0 && current_status != 0)
			first_error_status = current_status;
		temp = temp->next;
		i++;
	}
	return (first_error_status);
}
