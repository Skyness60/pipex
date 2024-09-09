/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:08:03 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 09:16:56 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	file_to_pipe(char *file, t_ppx *ppx)
{
	int	file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		return (perror(file), close_pipe(ppx), 0);
	dup2(file_fd, STDIN_FILENO);
	dup2(ppx->pipe_fd[1], STDOUT_FILENO);
	close_pipe(ppx);
	close(file_fd);
	return (1);
}

int	pipe_to_file(char *file, t_ppx *ppx, bool heredoc)
{
	int	file_fd;

	if (heredoc == true)
		file_fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		file_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
		return (perror(file), close_pipe(ppx), 0);
	dup2(ppx->pipe_fd[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close_pipe(ppx);
	close(file_fd);
	return (1);
}

void	pipe_to_pipe(int pipe_fd_1[2], int pipe_fd_2[2], t_ppx *ppx)
{
	dup2(pipe_fd_1[0], STDIN_FILENO);
	dup2(pipe_fd_2[1], STDOUT_FILENO);
	close_pipe(ppx);
}
