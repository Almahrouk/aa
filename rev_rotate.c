/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dal-mahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:07:08 by dal-mahr          #+#    #+#             */
/*   Updated: 2024/12/03 10:07:10 by dal-mahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}
