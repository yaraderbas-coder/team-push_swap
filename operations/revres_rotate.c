/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revres_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalqutob <dalqutob@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:00:51 by dalqutob          #+#    #+#             */
/*   Updated: 2026/11/07 12:57:15 by dalqutob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	revres_rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*before_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	before_last = *stack;
	last = (*stack)->next;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = first;
	*stack = last;
	return (1);
}

void	rra(t_stack **stc_a)
{
	if (revres_rotate_stack(stc_a))
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stc_b)
{
	if (revres_rotate_stack(stc_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stc_a, t_stack **stc_b)
{
	int	a;
	int	b;

	a = revres_rotate_stack(stc_a);
	b = revres_rotate_stack(stc_b);
	if (a || b)
		write(1, "rrr\n", 4);
}
