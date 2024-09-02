/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:42:53 by sperron           #+#    #+#             */
/*   Updated: 2024/09/01 00:19:29 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include "../export/printf/includes/ft_printf.h"
# include "../export/essential/essential.h"


typedef struct s_pipex
{
	int				cmd_i;
	int				cmd_fdr;
	int				cmd;
	int				status;
	int				fd[2];
	pid_t			pid;
	struct s_pipex	*next;
}					t_pipex;

/*Fonctions export*/
t_pipex	*ft_ppxnew(int cmd_i);
void	ft_ppxadd_back(t_pipex **pipex, t_pipex *new);
void	ft_ppxclear(t_pipex **pipex);

/*Free*/
void	ft_free(char **array);
/*Utils*/
char	*ft_strjoin_with_separator(char const *s1, char const *s2);
int		ft_tablen(char **tab);
int		exec(char **cmd, char *cmd_path, char **envp);
/*Path*/
char	*found_path(char **envp, char *cmd);
/*Wait*/
int		wait_childs(t_pipex **pipex, char **av, int *array);
/*Childs*/
int		first_child(int *cmd_i, t_pipex **pipex, char **av, char **envp);
int		second_child(int cmd_i, t_pipex **pipex, char **av, char **envp);
int		infile_child(char **av, t_pipex *node);
int		outfile_child(int ci, char **av, t_pipex *nnod, t_pipex **pid);
/*Clean*/
void	close_and_clear(int pipe[2], t_pipex **pipex);
void	clear_and_exit(t_pipex **pipex);
/*Pipe*/
void	close_pipe(int fd[2]);
void	syntax_error(char **av, int ac);

#endif