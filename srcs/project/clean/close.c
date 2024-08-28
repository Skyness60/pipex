/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:03:22 by sperron           #+#    #+#             */
/*   Updated: 2024/08/22 13:04:32 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	close_and_clear(int pipe[2], t_pipex **pipex)
{
	close_pipe(pipe);
	ft_ppxclear(pipex);
}
