/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:13:08 by sperron           #+#    #+#             */
/*   Updated: 2024/08/28 06:40:30 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex_bonus.h"

int	exec(char **cmd, char *cmd_path, char **envp)
{
	if (execve(cmd_path, (char *const *)cmd, (char *const *)envp) == -1)
		return (-1);
	return (0);
}
