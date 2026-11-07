/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 10:40:44 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/07 13:52:53 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i + 1] == '\0')
			return (0);
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	parse_num(char *str, int *result)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	number = 0;
	if (!str || str[i] == '\0')
		return (0);
	sign = get_sign(str, &i);
	if (sign == 0)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		if (number > 2147483647L + (sign == -1))
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(number * sign);
	return (1);
}
