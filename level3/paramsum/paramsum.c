/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:06:31 by zwen              #+#    #+#             */
/*   Updated: 2018/04/05 11:52:53 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;
	int		rem;

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
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	(void)argv;
	ft_putnbr(argc - 1);
	return (0);
}
