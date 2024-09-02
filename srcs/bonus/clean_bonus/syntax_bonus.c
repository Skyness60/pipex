/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:27:24 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 16:32:06 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

void	syntax_error(char **av, int ac)
{
	if (ac == 1)
	{
		ft_printf("pipex: syntax error near unexpected token '|'\n");
		return ;
	}
	ft_printf("pipex: syntax error near unexpected token '%s'\n", av[ac - 1]);	
}
