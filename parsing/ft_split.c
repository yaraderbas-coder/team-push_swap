/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalqutob <dalqutob@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:28:43 by dalqutob          #+#    #+#             */
/*   Updated: 2026/11/14 13:08:54 by dalqutob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	count_word(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const **s, char c)
{
	char const	*start;
	int			len;
	char		*word;
	int			i;

	while (**s == c)
		(*s)++;
	if (!**s)
		return (NULL);
	start = *s;
	while (**s != '\0' && **s != c)
		(*s)++;
	len = *s - start;
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_result(char **result, int i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_word(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		result[i] = get_word(&s, c);
		if (!result[i])
		{
			free_result(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
