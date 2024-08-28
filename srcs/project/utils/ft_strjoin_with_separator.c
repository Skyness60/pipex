/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_with_separator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:44:00 by sperron           #+#    #+#             */
/*   Updated: 2024/08/22 13:56:26 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

char	*ft_strjoin_with_separator(char const *s1, char const *s2)
{
	size_t	dest_len;
	int		i;
	char	*dest;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	dest_len = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (dest_len + 2));
	i = 0;
	j = 0;
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
		dest[j++] = s1[i++];
	dest[j++] = '/';
	i = 0;
	while (s2[i] != '\0')
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

//#include <stdio.h>
//int	main()
//{
//	char const s1[255] = "toto";
//	char const s2[255] = "tata";
//	char *res = ft_strjoin_with_separator(s1, s2);
//	printf("%s\n", res);
//	return (0);
//}