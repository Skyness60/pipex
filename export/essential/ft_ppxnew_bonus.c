/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:27:10 by sperron           #+#    #+#             */
/*   Updated: 2024/09/01 00:40:44 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

t_pipex	*ft_ppxnew(int cmd_i)
{
	t_pipex	*new;

	new = malloc(sizeof(t_pipex));
	if (new == NULL)
		return (NULL);
	new->cmd_i = cmd_i;
	new->here_doc = 0;
	new->status = 0;
	new->next = NULL;
	new->fd[0] = 0;
	new->fd[1] = 0;
	new->pid = -1;
	return (new);
}
