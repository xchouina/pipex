/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:43:08 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/03 15:54:26 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*lst;
	int		pid;

	if (ac != 5)
		return (0);
	lst = malloc(sizeof(t_pipex));
	initiation(lst, ac, av, env);
	pipe(lst->pipefd);
	if ((lst->fdi != -1) && (accessing(lst, 2) == 1))
	{
		pid = fork();
		if (pid == 0)
			redirecting_1(lst);
	}
	pid = fork();
	if ((pid == 0) && (accessing(lst, 3) == 1))
		redirecting_2(lst);
	close(lst->pipefd[1]);
	close(lst->pipefd[0]);
	liberator(lst);
}

void	initiation(t_pipex *lst, int ac, char **av, char **env)
{
	lst->ac = ac;
	lst->av = av;
	lst->env = env;
	lst->fdi = open(av[1], O_RDONLY);
	lst->fdo = open (av[4], O_TRUNC | O_CREAT | O_RDWR, 0777);
	finding_paths(lst);
}

int	accessing(t_pipex *lst, int n)
{
	int		yes_or_no;
	char	*cmd;
	int		i;

	ini_cmd(lst, n);
	cmd = ft_strjoin("/", lst->cmd);
	i = 0;
	while (lst->paths[i])
	{
		lst->path = ft_strjoin(lst->paths[i], cmd);
		yes_or_no = access(lst->path, X_OK);
		if (yes_or_no != -1)
		{
			free(cmd);
			free(lst->cmd);
			return (1);
		}
		i++;
	}
	free(cmd);
	free(lst->path);
	print_error(lst);
	return (0);
}

void	executing_cmd(t_pipex *lst)
{
	lst->args = malloc(sizeof(char **) * 1000);
	lst->args[0] = lst->path;
	lst->args[1] = lst->flags;
	lst->args[2] = NULL;
	free(lst->path);
	execve(lst->args[0], lst->args, NULL);
}

void	ini_cmd(t_pipex *lst, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lst->cmd = malloc(sizeof(char) * ft_strlen(lst->av[n]));
	lst->flags = malloc(sizeof(char) * ft_strlen(lst->av[n]));
	while ((lst->av[n][i] != ' ') && (lst->av[n][i]))
	{
		lst->cmd[i] = lst->av[n][i];
		i++;
	}
	lst->cmd[i] = '\0';
	if (!lst->av[n][i])
	{
		lst->flags = NULL;
		free(lst->flags);
		return ;
	}
	while (lst->av[n][++i])
	{
		lst->flags[j] = lst->av[n][i];
		j++;
	}
	lst->flags[i] = '\0';
}
