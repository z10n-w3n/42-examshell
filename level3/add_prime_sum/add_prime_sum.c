/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 08:39:52 by zwen              #+#    #+#             */
/*   Updated: 2018/04/03 10:33:07 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	is_prime(unsigned int n)
{
	unsigned int i;

	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / i)
		if (n % i++ == 0)
			return (0);
	return (n);
}

unsigned int	add_prime_sum(unsigned int n)
{
	unsigned int res;
	int i;

	i = 2;
	res = 0;
	while (i <= n)
	{
		res += is_prime(i);
		i++;
	}
	return (res);
}

void	ft_putnbr(unsigned int n)
{
	unsigned int	i;
	char			c;

	i = 1;
	while (n / i > 9)
		i *= 10;
	while (i > 0)
	{
		c = '0' + n / i;
		write(1, &c, 1);
		n %= i;
		i /= 10;
	}
}
int		main(int argc, char **argv)
{
	unsigned int	nbr;
	unsigned int	i;
	char			c;
	
	nbr = 0;
	i = 10;
	if (argc == 2)
	{
		argv++;
		while (**argv)
			nbr = (nbr * 10) + (*(*argv)++ - '0');
		nbr = add_prime_sum(nbr);
		ft_putnbr(nbr);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
