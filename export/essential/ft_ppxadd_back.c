/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:07:27 by sperron           #+#    #+#             */
/*   Updated: 2024/08/22 16:05:18 by sperron          ###   ########.fr       */
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
