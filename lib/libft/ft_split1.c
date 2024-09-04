/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:14:17 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 11:26:47 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_separator(char c, char sep)
{
	return (c == sep);
}

char	**valid(char **result, char s, int count)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (result[i])
	{
		j = 0;
		while (result[i][j])
		{
			if (result[i][j] == '\'')
				counter++;
			j++;
		}
		i++;
	}
	if (counter % 2 == 1)
	{
		if (i > 0)
			result[i - 1] = prompt_command(result[i - 1]);
	}
	valid2(result, s, count, 0);
	return (result);
}

char	**split_with_quotes(char *str, char sep)
{
	char	**result;
	int		count;
	int		j;

	if (!str)
		return (NULL);
	count = 0;
	count_word_spe(str, sep, &count);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	j = 0;
	tab_str(result, str, sep, &j);
	result[j] = NULL;
	result = valid(result, ' ', count);
	if (!result)
		free(result);
	return (result);
}
//int main() {
//    char *test_str = "grep 'line' ' ' 'ta'";
//    char **result = split_with_quotes(test_str, ' ');
//    for (int i = 0; result[i]; i++) {
//        printf("Part %d: %s\n", i, result[i]);
//        free(result[i]);
//    }
//    free(result);
//    return 0;
//}
