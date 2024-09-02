/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:27:44 by sperron           #+#    #+#             */
/*   Updated: 2024/09/01 20:31:14 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void ft_free_pipex(t_pipex **pipex)
{
    t_pipex *temp;

    while (*pipex)
    {
        temp = *pipex;
        *pipex = (*pipex)->next;
        free(temp);
    }
}

int main(int ac, char **av, char **envp)
{
    t_pipex *pipex;
    int cmd_i;
    int cmd;
    int s;

    if (ac < 5)
        return (syntax_error(av, ac), 2);
    pipex = NULL;
    cmd_i = 2;
    if (ft_strncmp(av[1], "here_doc", 9) == 0)
        cmd_i++;
    cmd = first_child(&cmd_i, &pipex, av, envp);
    if (cmd == 2 || cmd == 3)
        exit(cmd);
    while (cmd_i < (ac - 2))
    {
        if (middle_child(&cmd_i, &pipex, av, envp) == -1)
            exit(EXIT_FAILURE);
    }
    if (second_child(cmd_i, &pipex, av, envp) == -1)
        exit(EXIT_FAILURE);
    if (ft_strncmp(av[1], "here_doc", 9) == 0)
        del_heredoc((pipex));
    s = wait_childs(&pipex, av);
    ft_ppxclear(&pipex);
    exit(s);
    return (0);
}