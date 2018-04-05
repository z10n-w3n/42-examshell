/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:13:02 by zwen              #+#    #+#             */
/*   Updated: 2018/04/05 16:42:14 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		is_lower(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	return (0);
}

int		is_upper(char c)
{
	if (c <= 'Z' && c>= 'A')
		return (1);
	return (0);
}

void	str_capitalizer(char *str)
{
	int i;

	if (is_lower(str[0]))
		str[0] -= 32;
	write(1, &str[0], 1);
	i = 0;
	while (str[++i])
	{
		if (is_space(str[i - 1]) && is_lower(str[i]))
			str[i] -= 32;
		else if (!is_space(str[i - 1]) && is_upper(str[i]))
			str[i] += 32;
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	while (*(++argv))
		str_capitalizer(*argv);
	if (argc == 1)
		write(1, "\n", 1);
	return (0);
}
