/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:17:10 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/04 17:11:33 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*sec;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	sec = first -> next;
	first -> next = sec ->next;
	sec ->next = first;
	*stack = sec;
	return (1);
}

void	sa(t_stack **stack_a)
{
	if (swap_stack(stack_a))
		write (1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	if (swap_stack(stack_b))
		write (1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;

	a = swap_stack(stack_a);
	b = swap_stack(stack_b);
	if (a || b)
		write (1, "ss\n", 3);
}
