/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 05:22:46 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 05:30:50 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	process_arguments(int ac, char **av, char **envp, t_ppx *ppx)
{
	int	i;

	i = 4;
	if (ft_strncmp(av[1], "here_doc", 9) == 0 && ac > 5)
		creat_here_doc_take_path_exec(av, envp);
	else if (ft_strncmp(av[1], "here_doc", 9) != 0)
		i = take_path_exec(av, envp, ppx, i);
	else
		return (ppx_error(6, av, ac, 0), 1);
	return (i);
}
