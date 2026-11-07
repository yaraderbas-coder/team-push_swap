/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalqutob <dalqutob@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:45:16 by dalqutob          #+#    #+#             */
/*   Updated: 2026/11/07 12:23:05 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_stack **stc_a)
{
	if (rotate_stack(stc_a))
		write(1, "ra\n", 3);
}

void	rb(t_stack **stc_b)
{
	if (rotate_stack(stc_b))
		write(1, "rb\n", 3);
}

void	rr(t_stack **stc_a, t_stack **stc_b)
{
	int	a;
	int	b;

	a = rotate_stack(stc_a);
	b = rotate_stack(stc_b);
	if (a || b)
		write(1, "rr\n", 3);
}
