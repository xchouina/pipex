/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:43:04 by xchouina          #+#    #+#             */
/*   Updated: 2022/06/03 15:45:05 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "big_boi/big_boi.h"

typedef struct lst
{
	int		ac;
	char	**av;
	char	**env;
	char	*path;
	char	**paths;
	char	*cmd;
	char	*flags;
	int		fdi;
	int		fdo;
	int		pipefd[2];
	char	**args;

}		t_pipex;

void	initiation(t_pipex *lst, int ac, char **av, char **env);
void	redirecting_1(t_pipex *lst);
void	redirecting_2(t_pipex *lst);
void	finding_paths(t_pipex *lst);
int		accessing(t_pipex *lst, int n);
void	executing_cmd(t_pipex *lst);
void	ini_cmd(t_pipex *lst, int n);
void	liberator(t_pipex *lst);
void	print_error(t_pipex *lst);
#endif
