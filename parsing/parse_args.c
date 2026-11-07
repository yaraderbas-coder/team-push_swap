/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 09:45:16 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/07 11:54:40 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	fill_stack_num(int *stack_num, char **argv)
{
	int	i;
	int	result;

	i = 1;
	while (argv[i])
	{
		if (!parse_num(argv[i], &result))
			return (0);
		stack_num[i - 1] = result;
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv)
{
	t_stack	*stack;
	int		*stack_num;

	if (argc <= 1)
		return (0);
	stack_num = malloc(sizeof(int) * (argc - 1));
	if (!stack_num)
		return (1);
	if (!fill_stack_num(stack_num, argv))
	{
		free(stack_num);
		return (1);
	}
	stack = create_stack(stack_num, argc - 1);
	free(stack_num);
	if (!stack)
		return (1);
	if (check_errors(stack))
	{
		free_stack(stack);
		return (1);
	}
	return (0);
}
