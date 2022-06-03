/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:42:26 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:57:46 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hundred(t_stacks *stacks)
{
	indexing_nmbs(stacks, looking_4_smallest(stacks));
	stacks->mid = stacks->max / 2;
	stacks->chunky = best_chunky(stacks);
	if (sorted(stacks) == 1)
		return ;
	go_away(stacks);
	go_home(stacks);
	if (sorted(stacks) == 1)
		return ;
	else
		ft_hundred(stacks);
}

void	go_away(t_stacks *stacks)
{
	while (stacks->count_a > 0)
	{
		sorting_chunky(stacks);
		stacks->chunky += best_chunky(stacks);
	}
	pb(stacks);
	if (stacks->b[0].index <= stacks->mid)
		rb(stacks, 0);
	else if (stacks->b[0].index < stacks->b[1].index)
		sb(stacks);
}

void	sorting_chunky(t_stacks *stacks)
{
	int	i;

	while (chunk_check(stacks))
	{
		i = -1;
		while (++i <= stacks->count_a && chunk_check(stacks))
		{
			if (am_i_part_of_chunky(stacks, 0))
			{
				pb(stacks);
				if (stacks->b[0].index <= stacks->mid)
					rb(stacks, 0);
				if (stacks->b[0].index < stacks->b[1].index)
					sb(stacks);
			}
			else
				ra(stacks, 0);
		}
	}
}

int	chunk_check(t_stacks *stacks)
{
	int	i;
	int	j;

	if (stacks->count_a <= 0)
		return (0);
	i = -1;
	j = 0;
	while (++i < stacks->count_a)
	{
		if (am_i_part_of_chunky(stacks, i))
			j++;
	}
	if (j == 0)
		return (0);
	return (1);
}

int	am_i_part_of_chunky(t_stacks *stacks, int i)
{
	if ((stacks->a[i].index <= stacks->mid + stacks->chunky)
		&& (stacks->a[i].index >= stacks->mid - stacks->chunky))
		return (1);
	else
		return (0);
}
