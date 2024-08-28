/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 03:50:30 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 05:32:54 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

int	ft_ppxncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n < 1 || !s1)
		return (0);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	heredoc_creator(t_pipex	*node)
{
	int		i;
	int		fd_hd;
	char	*itoa;
	char	*hd_name;

	i = 0;
	fd_hd = open("here_doc0", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (fd_hd == -1)
	{
		i++;
		itoa = ft_itoa(i);
		if (itoa == NULL)
			return (-1);
		hd_name = ft_strjoin("here_doc", itoa);
		if (hd_name == NULL)
			return (free(itoa), -1);
		fd_hd = open(hd_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		free(itoa);
		free(hd_name);
	}
	node->here_doc = i;
	return (fd_hd);
}

int	if_here_doc(t_pipex	*node, char **argv)
{
	int		fd_hd;
	char	*next_line;
	char	*limiter;

	limiter = ft_strjoin(argv[2], "\n");
	if (limiter == NULL)
		return (-1);
	fd_hd = heredoc_creator(node);
	if (fd_hd == -1)
		return (free(limiter), -1);
	next_line = get_next_line(0);
	while (ft_ppxncmp(next_line, limiter, ft_strlen(limiter)) != 0)
	{
		if (next_line == NULL)
			break ;
		write(fd_hd, next_line, ft_strlen(next_line));
		free(next_line);
		next_line = get_next_line(0);
	}
	free(limiter);
	free(next_line);
	close(fd_hd);
	return (get_next_line(-1), 0);
}

void	check_heredoc(char **argv, t_pipex	*node)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		if (if_here_doc(node, argv) == -1)
		{
			free(node);
			exit(EXIT_FAILURE);
		}
	}
	return ;
}

