/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:06:58 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/11 13:17:23 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "../big_boi.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct stack
{
	int	value;
	int	index;
}		t_stack;

typedef struct stacks
{
	int		max;
	t_stack	*a;
	t_stack	*b;
	int		count_a;
	int		count_b;
	int		mid;
	int		chunky;
	int		chunk_max;
}		t_stacks;

int		len_of_args(char **argv);
int		vibe_check(int argc, t_stacks **stacks, char **nmbs);
void	the_liberator(t_stacks *stacks, int argc, char **nmbs);
int		am_i_an_integer(char **argv);
int		am_i_a_duplicate(t_stacks *stacks);
int		error(t_stacks *stacks, int argc, char **nmbs);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks, int RR);
void	rb(t_stacks *stacks, int RR);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks, int RRR);
void	rrb(t_stacks *stacks, int RRR);
void	rrr(t_stacks *stacks);
void	manager(t_stacks *stacks);
void	two(t_stacks *stacks);
void	four(t_stacks *stacks);
void	five(t_stacks *stacks);
void	find_me_the_smolls(t_stacks *stacks);
void	exclude_the_weak(t_stacks *stacks, int i, int o);
int		sorted(t_stacks *stacks);
int		looking_4_smallest(t_stacks *stacks);
void	indexing_nmbs(t_stacks *stacks, int n);
int		looking_from_top(t_stacks *stacks);
int		looking_from_bot(t_stacks *stacks);
int		biggest(t_stacks *stacks);
void	three(t_stacks *stacks);
int		case_one(t_stacks *stacks);
int		case_two(t_stacks *stacks);
int		case_three(t_stacks *stacks);
int		case_four(t_stacks *stacks);
void	ft_hundred(t_stacks *stacks);
void	go_away(t_stacks *stacks);
void	sorting_chunky(t_stacks *stacks);
int		chunk_check(t_stacks *stacks);
int		am_i_part_of_chunky(t_stacks *stacks, int i);
void	go_home(t_stacks *stacks);
void	rotating_stack_b(t_stacks *stacks);
int		best_chunky(t_stacks *stacks);

#endif
