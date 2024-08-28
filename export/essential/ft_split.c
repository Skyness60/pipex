/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:14:17 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 06:07:04 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "essential.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

int	is_separator(char c, char sep)
{
	return (c == sep);
}
void valid(char **result, char s, int count, int i)
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
                while (result[i][j] != '\'')
                {
                    if (is_separator(result[i][j], s))
                        state = 1;
					j++;
                }
            }
			j++;
        }
        if (state == 0)
            remove_char_from_string(result[i], result[i], count, 0);
    }
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
	valid(result, ' ', count, 0);
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
