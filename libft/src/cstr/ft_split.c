/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:21 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstr.h"

static unsigned int	count_words(char *str, char set)
{
	unsigned int	iw;
	unsigned int	wc;

	iw = 0;
	wc = 0;
	while (*str)
	{
		if (!iw && *str != set)
		{
			iw = 1;
			wc++;
		}
		if (iw && *str == set)
			iw = 0;
		str++;
	}
	return (wc);
}

static char	*eat_literal(char *str, char set)
{
	int		i;
	char	*out;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	out = (char *)ft_alloc(i + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != set)
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

static int	fill_words(const char *str, char set, char **out)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != set)
		{
			out[j] = eat_literal((char *)str + i, set);
			if (!out[j])
				return (ft_free_array((void ***)&out), 0);
			j++;
			while (str[i] && str[i] != set)
				i++;
			continue ;
		}
		i++;
	}
	return (1);
}

char	**ft_split(const char *str, char set)
{
	char			**out;
	unsigned int	wc;

	if (!str)
		return (NULL);
	wc = count_words((char *)str, set);
	out = (char **)ft_alloc((wc + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	out[wc] = NULL;
	if (!fill_words(str, set, out))
		return (ft_free_array((void ***)&out), NULL);
	return (out);
}
