/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:07:35 by sperron           #+#    #+#             */
/*   Updated: 2024/08/27 23:27:04 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

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

	infile = open(av[1], O_RDONLY);
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

int	outfile_child(int ci, char **av, t_pipex *nnod, t_pipex **pid)
{
	int	outfile;

	outfile = open(av[ci + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
