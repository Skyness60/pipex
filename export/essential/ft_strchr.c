/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:37:48 by sperron           #+#    #+#             */
/*   Updated: 2024/08/26 19:51:47 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essential.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *) str + i);
		i++;
	}
	if (c == '\0')
		return ((char *) str + i);
	return (NULL);
}
