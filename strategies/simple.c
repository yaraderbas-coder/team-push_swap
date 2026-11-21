/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 11:19:22 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/21 15:06:16 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	find_min(t_stack *stack)
{
	t_stack	*current;
	int		pos;
	int		min_value;
	int		min_pos;

	if (stack == NULL)
		return (-1);
	current = stack;
	min_value = current -> value;
	pos = 0;
	min_pos = 0;
	while (current != NULL)
	{
		if (current -> value < min_value)
		{
			min_value = current -> value;
			min_pos = pos;
		}
		pos++;
		current = current ->next;
	}
	return (min_pos);
}

static void	move_min_to_top(t_stack **stack, int min_position)
{
	int	size;
	int	ra_count;
	int	rra_count;
	int	i;

	if (min_position == 0)
		return ;
	size = stack_size(*stack);
	ra_count = min_position;
	rra_count = size - min_position;
	i = 0;
	if (rra_count > ra_count)
	{
		while (i++ < ra_count)
			ra(stack);
	}
	else
	{
		while (i++ < rra_count)
			rra(stack);
	}
}

static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;

	min_pos = find_min(*stack_a);
	move_min_to_top(stack_a, min_pos);
	pb(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a != NULL)
		push_min_to_b(stack_a, stack_b);
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}
