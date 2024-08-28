/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:27:44 by sperron           #+#    #+#             */
/*   Updated: 2024/08/23 15:10:33 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		cmd_i;
	int		cmd;
	int		status;
	int *status_array;
	
	if (ac == 5)
	{
		pipex = NULL;
		cmd_i = 2;
		cmd = first_child(&cmd_i, &pipex, av, envp);
		if (cmd == 2 || cmd == 3)
			exit(cmd);
		if (second_child(cmd_i, &pipex, av, envp) == -1)
			exit(EXIT_FAILURE);
		status_array = malloc(2 * sizeof(int));
		if (!status_array)
			return (1);
		status = wait_childs(&pipex, av, status_array);
		ft_ppxclear(&pipex);
		free(status_array);
		exit(status);
	}
	else
		return (0);
}
