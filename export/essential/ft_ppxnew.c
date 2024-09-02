/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppxnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:27:10 by sperron           #+#    #+#             */
/*   Updated: 2024/09/01 03:16:04 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_pipex	*ft_ppxnew(int cmd_i)
{
	t_pipex	*new;

	new = malloc(sizeof(t_pipex));
	if (new == NULL)
		return (NULL);
	new->cmd_i = cmd_i;
	new->status = 0;
	new->next = NULL;
	return (new);
}
