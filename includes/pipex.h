/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:35:34 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 05:54:17 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/lib.h"

typedef enum e_error_code
{
	ERR_FILE_NOT_FOUND,
	ERR_ARGS,
	ERR_PERMISSION_DENIED,
	ERR_CMD_NOT_FOUND,
	ERR_PIPE_FAILURE,
	ERR_FORK_FAILURE,
	ERR_UNKNOWN
}				t_error_code;

typedef struct s_ppx
{
	int				pipe_fd[2];
	char			**paths;
	char			**envp;
	struct s_ppx	*next;
	struct s_ppx	*prev;
}					t_ppx;

t_ppx	*ppx_new(char **envp);
int		ppx_add_back(t_ppx **pip, t_ppx *new);
void	ppx_del(t_ppx **ppx);
char	*find_path(char **paths, char *cmd);
void	close_pipe(t_ppx *ppx);
int		file_to_pipe(char *file, t_ppx *ppx);
int		pipe_to_file(char *file, t_ppx *ppx);
void	exec_child_first(t_ppx *ppx, char *cmd, char *file);
void	exec_child_last(t_ppx *ppx, char *cmd, char *file);
char	**find_paths(char **envp);
void	ft_free_strs(char **strs);
void	exec_child_first(t_ppx *ppx, char *cmd, char *file);
void	exec_child_last(t_ppx *ppx, char *cmd, char *file);
int		ppx_error(t_error_code code, char **av, int ac, char *cmd);
#endif