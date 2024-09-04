/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:38:59 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 00:44:17 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_ppx	*ppx_new(char **envp)
{
	t_ppx	*new;

	new = (t_ppx *)malloc(sizeof(t_ppx));
	if (!new)
		return (NULL);
	new->envp = envp;
	new->next = NULL;
	new->prev = NULL;
	new->paths = find_paths(envp);
	if (!new->paths)
		return (free(new), NULL);
	return (new);
}

int	ppx_add_back(t_ppx **ppx, t_ppx *new)
{
	t_ppx	*temp;

	if (!new)
		return (0);
	temp = *ppx;
	if (!temp)
	{
		*ppx = new;
		return (1);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (1);
}

void	ppx_del(t_ppx **ppx)
{
	t_ppx	*temp;

	if (!ppx || !*ppx)
		return ;
	while (*ppx)
	{
		temp = *ppx;
		*ppx = (*ppx)->next;
		free(temp);
	}
	*ppx = NULL;
}
