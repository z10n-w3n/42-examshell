/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:49:30 by zwen              #+#    #+#             */
/*   Updated: 2018/04/05 11:03:23 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	int		rem;
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		rem = n % 10;
		c = '0' + rem;
		write(1, &c, 1);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

int		ft_atoi(char *str)
{
	int		res;

	res = 0;
	while (*str)
		res = res * 10 + *(str++) - '0';
	return (res);
}

int		main(int argc, char **argv)
{
	int		i;
	int		res;
	int		n;

	if (argc == 2)
	{
		i = 1;
		n = ft_atoi(argv[1]);
		while (i < 10)
		{
			res = n * i;
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(res);
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
