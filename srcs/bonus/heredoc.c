/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:26:40 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 17:49:03 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static char	*creat_here_doc(int *file_fd)
{
	char	*name;
	char	*temp;
	int		i;

	i = 0;
	name = ft_strdup("here_doc");
	if (!name)
		return (NULL);
	while (access(name, F_OK) != -1)
	{
		temp = ft_strdup(name);
		free(name);
		if (!temp)
			return (NULL);
		name = ft_strjoin(temp, ft_itoa(i));
		free(temp);
		if (!name)
			return (NULL);
		i++;
	}
	*file_fd = open(name, O_CREAT, 0644);
	close(*file_fd);
	return (name);
}

static void	take_path_exec_here_doc(char **av, char **envp, char *name)
{
	t_ppx	*ppx;
	int		i;

	i = 5;
	ppx = NULL;
	if (ppx_add_back(&ppx, ppx_new(envp)) == -1)
		return ;
	if (pipe(ppx->pipe_fd) == -1)
		return (perror("ppx"));
	exec_child_first(ppx, av[3], name);
	while (av[i + 1])
		i = middle_cmd(&ppx, i, envp, av);
	exec_child_last(ppx, av[i - 1], av[i], true);
	close(ppx->pipe_fd[0]);
	close(ppx->pipe_fd[1]);
	while (i > 3)
	{
		wait(NULL);
		i--;
	}
	ppx_del(&ppx);
}

void	creat_here_doc_take_path_exec(char **av, char **envp)
{
	char	*name;
	char	*line;
	int		file_fd;

	write(2, "> ", 2);
	name = creat_here_doc(&file_fd);
	if (!name)
		return ;
	line = get_next_line(0);
	file_fd = open(name, W_OK, R_OK);
	while (line)
	{
		if (ft_strncmp(line, av[2], strlen(av[2])) == 0
			&& line[strlen(av[2])] == '\n')
			break ;
		write(2, "> ", 2);
		write(file_fd, line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(file_fd);
	take_path_exec_here_doc(av, envp, name);
	unlink(name);
	free(name);
}
