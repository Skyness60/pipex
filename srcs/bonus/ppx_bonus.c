/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 00:38:59 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 16:47:03 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

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
		return (free(new), ft_free_strs(new->paths), NULL);
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
	t_ppx	*save;

	temp = *ppx;
	if (!temp)
		return ;
	while (temp->prev)
		temp = temp->prev;
	while (temp)
	{
		save = temp->next;
		ft_free_strs(temp->paths);
		free(temp);
		temp = save;
	}
	*ppx = NULL;
}

t_ppx	*last_pip(t_ppx *ppx)
{
	while (ppx->next)
		ppx = ppx->next;
	return (ppx);
}
