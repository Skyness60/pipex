/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:24:54 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 01:35:15 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

static char	*find_env(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == 'P' && envp[i][1] == 'A' &&
			envp[i][2] == 'T' && envp[i][3] == 'H')
		{
			path = envp[i];
			return (path);
		}
		i++;
	}
	return (NULL);
}

static char	**split_path(char **envp)
{
	int		path_prefix_len;
	char	*path;
	char	**tab;

	path = find_env(envp);
	if (!path)
		return (NULL);
	tab = split_with_quotes(path, ':');
	if (!tab)
		return (NULL);
	path_prefix_len = ft_strlen(tab[0] + 5);
	ft_memmove(tab[0], tab[0] + 5, ft_strlen(tab[0] + 5));
	ft_bzero(tab[0] + path_prefix_len, ft_strlen(tab[0]) - path_prefix_len);
	return (tab);
}

char	*found_path(char **envp, char *cmd)
{
	int		i;
	char	**tab;
	char	*namecmd;

	i = 0;
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	tab = split_path(envp);
	if (!tab)
		return (NULL);
	while (tab[i] != NULL)
	{
		namecmd = ft_strjoin_with_separator(tab[i], cmd);
		if (!namecmd)
			return (ft_free(tab), namecmd);
		if (access(namecmd, X_OK) == 0)
			return (ft_free(tab), namecmd);
		i++;
		free(namecmd);
	}
	return (ft_free(tab), NULL);
}
