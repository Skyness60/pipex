/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:03:22 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 01:35:15 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

void	close_and_clear(int pipe[2], t_pipex **pipex)
{
	close_pipe(pipe);
	ft_ppxclear(pipex);
}
