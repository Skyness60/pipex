/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:34:53 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 06:51:02 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

static int	check_cmd_null(char **av, int status, t_pipex *temp)
{
	if (WEXITSTATUS(status) == 2)
		return (ft_printf("%s: %s: Permission denied\n", av[2], av[1]), 1);
	if (WEXITSTATUS(status) == 1)
		return (ft_printf("pipex: %s: No such file or directory\n", av[1]), 1);
	if (WEXITSTATUS(status) == 5)
		return (ft_printf("pipex: %s: command not found\n", av[temp->cmd_i]));
	if (WEXITSTATUS(status) == 127)
		return (ft_printf("pipex: %s: command not found\n", av[temp->cmd_i]),
			127);
	if (WEXITSTATUS(status) == 4)
		return (ft_printf("%s: %s: Permission denied\n", av[3], av[4]), 1);
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

int	wait_childs(t_pipex **pipex, char **av)
{
	t_pipex	*temp;
	int	first_error_status;
    int current_status;

	if (!pipex || !(*pipex))
		return -1;
	*pipex = reverse_list(*pipex);
    first_error_status = 0;
	temp = *pipex;
	while (temp)
	{
		waitpid(temp->pid, &(temp->status), 0);
		current_status = check_cmd_null(av, temp->status, temp);
		if (first_error_status == 0 && current_status != 0)
			first_error_status = current_status;
		temp = temp->next;
	}
	return (first_error_status);
}
