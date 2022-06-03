/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:06:43 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/03 15:57:58 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	finding_paths(t_pipex *lst)
{
	int	i;

	i = 0;
	while (lst->env[i] != NULL)
	{
		if (ft_strnstr(lst->env[i], "PATH=", 5) != NULL)
			lst->path = ft_strnstr(lst->env[i], "PATH=", 5);
		i++;
	}
	lst->paths = ft_split(lst->path + 5, ':');
}

void	print_error(t_pipex *lst)
{
	write(2, "Command not found: ", 20);
	write(2, lst->cmd, ft_strlen(lst->cmd));
	write(2, "\n", 1);
	free(lst->cmd);
}

void	redirecting_1(t_pipex *lst)
{
	close(lst->pipefd[0]);
	dup2(lst->pipefd[1], 1);
	close(lst->pipefd[1]);
	dup2(lst->fdi, 0);
	close(lst->fdi);
	executing_cmd(lst);
	// free(lst->args[0]);
	// free(lst->args[1]);
	// free(lst->args);
}

void	redirecting_2(t_pipex *lst)
{
	close(lst->pipefd[1]);
	dup2(lst->pipefd[0], 0);
	close(lst->pipefd[0]);
	dup2(lst->fdo, 1);
	close(lst->fdo);
	executing_cmd(lst);
	// free(lst->args[0]);
	// free(lst->args[1]);
	// free(lst->args);
}

void	liberator(t_pipex *lst)
{
	int	i;

	i = -1;
	while (lst->paths[++i])
		free(lst->paths[i]);
}
