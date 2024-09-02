/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:49:57 by sperron           #+#    #+#             */
/*   Updated: 2024/09/01 15:18:36 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_ppxclear(t_pipex **pipex)
{
	t_pipex	*temp;

	if (!pipex || !*pipex)
		return ;
	while (*pipex != NULL)
	{
		temp = (*pipex)->next;
		free(*pipex);
		*pipex = temp;
	}
	return ;
}
