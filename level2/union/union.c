/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:15:33 by zwen              #+#    #+#             */
/*   Updated: 2018/04/03 13:32:10 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_uniq(int *tab, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (tab[(int)s[i]] == 0)
		{
			tab[(int)s[i]] = 1;
			write(1, &s[i], 1);
		}
		i++;
	}
}

void	ft_union(char *s1, char *s2)
{
	int	tab[256] = {0};
	write_uniq(tab, s1);
	write_uniq(tab, s2);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
