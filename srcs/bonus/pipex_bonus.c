/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:27:44 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 06:51:44 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		cmd_i;
	int		cmd;
	int		s;
	
	if (ac < 5)
		return (0);
	pipex = NULL;
	cmd_i = 2;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		cmd_i++;
	cmd = first_child(&cmd_i, &pipex, av, envp);
	if (cmd == 2 || cmd == 3)
		exit(cmd);
	while (cmd_i < (ac - 2))
	{
		if (middle_child(&cmd_i, &pipex, av, envp) == -1)
			exit(EXIT_FAILURE);
	}
	if (second_child(cmd_i, &pipex, av, envp) == -1)
		exit(EXIT_FAILURE);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		del_heredoc((pipex));
	return (s = wait_childs(&pipex, av), ft_ppxclear(&pipex), exit(s), 0);
}
