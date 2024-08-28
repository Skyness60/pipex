/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:12:52 by sperron           #+#    #+#             */
/*   Updated: 2024/08/26 19:48:56 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essential.h"

char	*ft_strndup(const char *str, int n)
{
	char	*dup;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, str, n);
	dup[n] = '\0';
	return (dup);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;

	if (*str == '\0')
	{
		dup = (char *)malloc(1 * sizeof(char));
		*dup = '\0';
		return (dup);
	}
	len = ft_strlen(str);
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}
