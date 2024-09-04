/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:52:26 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 00:51:42 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	valid2(char **result, char s, int count, int i)
{
	int j;
    int state;

    while (result[++i])
    {
        j = 0;
        state = 0;
        while (result[i][j])
        {
            if (result[i][j] == '\'')
            {
				j++;
                while (result[i][++j] != '\'')
                {
					state = 0;
                    if (is_separator(result[i][j], s))
                        state = 1;
                }
            }
			j++;
        }
        if (state == 0)
            remove_char_from_string(result[i], result[i], count, 0);
    }
}
