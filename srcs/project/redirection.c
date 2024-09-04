/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:08:03 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 01:23:02 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"


int	file_to_pipe(char *file, t_ppx *ppx)
{
	int	file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (perror(file), close_pipe(ppx), close(file_fd), 0);
	dup2(file_fd, STDIN_FILENO);
	dup2(ppx->pipe_fd[1], STDOUT_FILENO);
	close_pipe(ppx);
	close(file_fd);
	return (1);
}
int	pipe_to_file(char *file, t_ppx *ppx)
{
	int	file_fd;

	file_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
		return (perror(file), close(file_fd), close_pipe(ppx), 0);
	dup2(ppx->pipe_fd[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close_pipe(ppx);
	close(file_fd);
	return (1);
}