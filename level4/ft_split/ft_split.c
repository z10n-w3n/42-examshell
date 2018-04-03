/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:42:05 by zwen              #+#    #+#             */
/*   Updated: 2018/04/03 15:03:08 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		count_word(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && is_space(*s))
			s++;
		if (*s)
			count++;
		while (*s && !is_space(*s))
			s++;
	}
	return (count);
}

char	*cp_word(char *s)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && !is_space(s[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && !is_space(s[i]))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	int		w_count;
	char	**words;
	int		i;

	w_count = count_word(str);
	words = (char **)malloc(sizeof(*words) * (w_count + 1));
	i = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			str++;
		if (*str)
		{
			words[i] = cp_word(str);
			i++;
		}
		while (*str && !is_space(*str))
			str++;
	}
	words[i] = NULL;
	return (words);
}
