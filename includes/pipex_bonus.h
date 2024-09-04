/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:35:34 by sperron           #+#    #+#             */
/*   Updated: 2024/09/04 17:19:46 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../lib/lib.h"

typedef enum e_error_code
{
	ERR_FILE_NOT_FOUND,
	ERR_ARGS,
	ERR_PERMISSION_DENIED,
	ERR_CMD_NOT_FOUND,
	ERR_PIPE_FAILURE,
	ERR_FORK_FAILURE,
	ERR_HEREDOC,
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
int		pipe_to_file(char *file, t_ppx *ppx, bool heredoc);
void	exec_child_first(t_ppx *ppx, char *cmd, char *file);
void	exec_child_last(t_ppx *ppx, char *cmd, char *file, bool heredoc);
char	**find_paths(char **envp);
void	ft_free_strs(char **strs);
void	exec_child_midle(t_ppx *ppx, char *cmd);
int		ppx_error(t_error_code code, char **av, int ac, char *cmd);
int		middle_cmd(t_ppx **ppx, int i, char **envp, char **av);
void	creat_here_doc_take_path_exec(char **av, char **envp);
void	pipe_to_pipe(int pipe_fd_1[2], int pipe_fd_2[2], t_ppx *ppx);
t_ppx	*last_pip(t_ppx *ppx);
#endif