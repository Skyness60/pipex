/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fail_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:01:42 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 03:07:19 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

void	clear_and_exit(char **av, t_pipex **pipex)
{
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		del_heredoc(*pipex);
	ft_ppxclear(pipex);
	exit(EXIT_FAILURE);
}
