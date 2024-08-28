/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:49:57 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 01:47:32 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_ppxclear(t_pipex **pipex)
{
	if (!pipex || !(*pipex))
		return ;
	if ((*pipex)->next)
		ft_ppxclear((&(*pipex)->next));
	free(*pipex);
}
