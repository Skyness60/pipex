/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:49:57 by sperron           #+#    #+#             */
/*   Updated: 2024/08/22 12:57:59 by sperron          ###   ########.fr       */
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
