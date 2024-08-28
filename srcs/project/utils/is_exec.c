/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:13:08 by sperron           #+#    #+#             */
/*   Updated: 2024/08/22 15:13:21 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/pipex.h"

int	exec(char **cmd, char *cmd_path, char **envp)
{
	if (execve(cmd_path, cmd, envp) == -1)
		return (-1);
	return (0);
}
