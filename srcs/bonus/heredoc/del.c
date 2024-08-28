/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:47:49 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 03:49:01 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

void	del_heredoc(t_pipex	*pipex)
{
	char	*heredoc_name;
	char	*itoa;

	itoa = ft_itoa(pipex->here_doc);
	heredoc_name = ft_strjoin("here_doc", itoa);
	if (heredoc_name == NULL)
		return ;
	unlink(heredoc_name);
	free(heredoc_name);
	free(itoa);
}
