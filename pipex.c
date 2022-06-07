/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:43:08 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/07 09:24:59 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*lst;

	if (ac != 5)
		return (0);
	lst = malloc(sizeof(t_pipex));
	lst->ac = ac;
	lst->av = av;
	lst->env = env;
	lst->fdi = open(av[1], O_RDONLY);
	lst->fdo = open (av[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	finding_paths(lst);
	pipe(lst->pipefd);
	forking(lst);
	closing_fds(lst);
}

void	forking(t_pipex *lst)
{
	int		pid1;
	int		pid2;
	int		temp;

	if ((lst->fdi != -1) && (accessing(lst, 2) == 1))
	{
		pid1 = fork();
		if (pid1 == 0)
			redirecting_1(lst);
		waitpid(pid1, &temp, 0);
		liberator_dos(lst);
	}
	if (accessing(lst, 3) == 1)
	{	
		pid2 = fork();
		if (pid2 == 0)
			redirecting_2(lst);
		liberator_dos(lst);
	}
}

void	closing_fds(t_pipex *lst)
{
	close(lst->pipefd[1]);
	close(lst->pipefd[0]);
	close(lst->fdi);
	close(lst->fdo);
	liberator(lst);
}

void	finding_paths(t_pipex *lst)
{
	int	i;

	i = 0;
	lst->path = NULL;
	while (lst->env[i] != NULL)
	{
		if (ft_strnstr(lst->env[i], "PATH=", 5) != NULL)
			lst->path = ft_strnstr(lst->env[i], "PATH=", 5);
		i++;
	}
	if (lst->path == NULL)
		print_error(lst, 2);
	lst->paths = ft_split(lst->path + 5, ':');
}

int	accessing(t_pipex *lst, int n)
{
	int		yes_or_no;
	char	*cmd;
	int		i;

	lst->cmd = ft_split(lst->av[n], ' ');
	cmd = ft_strjoin("/", lst->cmd[0]);
	i = 0;
	while (lst->paths[i])
	{
		lst->path = ft_strjoin(lst->paths[i], cmd);
		yes_or_no = access(lst->path, F_OK | X_OK);
		if (yes_or_no != -1)
		{
			free(cmd);
			return (1);
		}
		free(lst->path);
		i++;
	}
	free(cmd);
	print_error(lst, 1);
	return (0);
}
