/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:07:27 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 01:47:37 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_ppxadd_back(t_pipex **pipex, t_pipex *new)
{
	t_pipex	*tmp;

	if (!new || !pipex)
		return ;
	if (*pipex == NULL)
	{
		*pipex = new;
		return ;
	}
	tmp = *pipex;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
