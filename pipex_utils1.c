/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:06:43 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/07 09:24:21 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(t_pipex *lst, int n)
{
	int	i;

	i = 0;
	if (n == 1)
	{
		write(2, "Command not found: ", 20);
		write(2, lst->cmd[0], ft_strlen(lst->cmd[0]));
		write(2, "\n", 1);
		while (lst->cmd[i])
			free(lst->cmd[i++]);
		free(lst->cmd);
	}
	if (n == 2)
	{
		write(2, "Invalid path.\n", 15);
	}
}

void	redirecting_1(t_pipex *lst)
{
	close(lst->pipefd[0]);
	dup2(lst->pipefd[1], 1);
	close(lst->pipefd[1]);
	dup2(lst->fdi, 0);
	close(lst->fdi);
	execve(lst->path, lst->cmd, NULL);
}

void	redirecting_2(t_pipex *lst)
{
	close(lst->pipefd[1]);
	dup2(lst->pipefd[0], 0);
	close(lst->pipefd[0]);
	dup2(lst->fdo, 1);
	close(lst->fdo);
	execve(lst->path, lst->cmd, NULL);
}

void	liberator(t_pipex *lst)
{
	int	i;

	i = -1;
	while (lst->paths[++i])
		free(lst->paths[i]);
	free(lst->paths);
	free(lst);
}

void	liberator_dos(t_pipex *lst)
{
	int	i;

	i = 0;
	while (lst->cmd[i] && lst->cmd)
		free(lst->cmd[i++]);
	free(lst->cmd);
	free(lst->path);
}
