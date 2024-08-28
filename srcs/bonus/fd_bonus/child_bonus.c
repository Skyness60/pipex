/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:07:35 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 06:11:28 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

static int	fd_heredoc(t_pipex *new_nod)
{
	char	*itoa;
	int		fd;
	char	*heredoc_name;

	itoa = ft_itoa(new_nod->here_doc);
	if (itoa == NULL)
		return (-1);
	heredoc_name = ft_strjoin("here_doc", itoa);
	if (heredoc_name == NULL)
	{
		free(itoa);
		return (-1);
	}
	fd = open(heredoc_name, O_RDONLY);
	if (fd == -1)
	{
		free(itoa);
		free(heredoc_name);
		return (-1);
	}
	free(itoa);
	free(heredoc_name);
	return (fd);
}

static int	infile_check(int error)
{
	if (error == EACCES)
		return (2);
	if (error == ENOENT)
		return (1);
	return (0);
}

int	infile_child(char **av, t_pipex *node)
{
	int	infile;

	if (ft_strncmp(av[1], "here_doc", 9) != 0)
		infile = open(av[1], O_RDONLY);
	else
		infile = fd_heredoc(node);
	if (infile == -1)
	{
		close_pipe(node->fd);
		free(node);
		exit(infile_check(errno));
	}
	if (dup2(infile, STDIN_FILENO) == -1)
		return (-1);
	close(infile);
	if (dup2((node)->fd[1], STDOUT_FILENO) == -1)
		return (-1);
	return (close_pipe((node)->fd), 0);
}

int	fd_childs(t_pipex *node)
{
	if (dup2((node)->fd[1], STDOUT_FILENO) == -1)
		return (-1);
	close_pipe(node->fd);
	return (0);
}

int	outfile_child(int ci, char **av, t_pipex *nnod, t_pipex **pid)
{
	int	outfile;

	if (ft_strncmp(av[1], "here_doc", 9) != 0)
		outfile = open(av[ci + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		outfile = open(av[ci + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outfile == -1)
	{
		close_pipe((nnod)->fd);
		ft_ppxclear(pid);
		exit(4);
	}
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (-1);
	return (close(outfile), close_pipe((nnod)->fd), 0);
}
