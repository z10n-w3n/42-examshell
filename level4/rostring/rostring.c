/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:55:48 by zwen              #+#    #+#             */
/*   Updated: 2018/04/04 23:31:15 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	rostring(char *str)
{
	int		i;
	char	*first_word;

	i = 0;
	while (*str && is_space(*str))
		str++;
	while (*str && !is_space(*str) && ++i)
		str++;
	first_word = (char *)malloc(sizeof(*first_word) * (i + 1));
	if (first_word)
	{
		first_word[i] = '\0';
		str -= i;
		while (*str && !is_space(*str))
			*(first_word++) = *(str++);
		first_word -= i;
		while (*str)
		{
			while (is_space(*str))
				str++;
			while (!is_space(*str) && *str)
				write(1, str++, 1);
			if (!is_space(*(str - 1)))
				write(1, " ", 1);
		}
		while (*first_word)
			write(1, first_word++, 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rostring(argv[1]);
	write(1, "\n", 1);
}
