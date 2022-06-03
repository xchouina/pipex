/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:41:13 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:36:19 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_of_args(char **argv)
{
	int	len;

	len = 0;
	while (argv[len] != NULL)
		len++;
	return (len);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**nmbs;

	stacks = NULL;
	if (argc < 2)
		return (0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	stacks->count_a = -1;
	stacks->count_b = -1;
	if (argc == 2)
		nmbs = ft_split(argv[1], ' ');
	if (argc > 2)
		nmbs = argv + 1;
	if (vibe_check(argc, &stacks, nmbs) == 0)
		return (0);
	while (++(stacks->count_a) < stacks->max)
		stacks->a[stacks->count_a].value = ft_atoi(nmbs[stacks->count_a]);
	stacks->count_a--;
	if (am_i_a_duplicate(stacks) == 0)
		return (error(stacks, argc, nmbs));
	manager(stacks);
	the_liberator(stacks, argc, nmbs);
}

int	vibe_check(int argc, t_stacks **stacks, char **nmbs)
{
	if (*nmbs == NULL)
	{
		the_liberator(*stacks, argc, nmbs);
		return (0);
	}
	if (am_i_an_integer(nmbs) == 0)
		return (error(*stacks, argc, nmbs));
	(*stacks)->max = len_of_args(nmbs);
	(*stacks)->a = malloc(sizeof(t_stack) * ((*stacks)->max + 50));
	if (!(*stacks)->a)
		return (0);
	(*stacks)->b = malloc(sizeof(t_stack) * ((*stacks)->max + 1));
	if (!(*stacks)->b)
		return (0);
	return (1);
}

void	the_liberator(t_stacks *stacks, int argc, char **nmbs)
{
	int	i;

	i = 0;
	if ((argc == 2) && (nmbs))
	{
		while (nmbs[i])
		{
			free(nmbs[i]);
			i++;
		}
		free(nmbs);
	}
	free(stacks->a);
	free(stacks->b);
	free(stacks);
}
