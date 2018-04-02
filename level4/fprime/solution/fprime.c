/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 00:45:32 by zwen              #+#    #+#             */
/*   Updated: 2018/04/02 01:09:00 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int n)
{
	int i;

	i = 2;
	while (i < n / i)
	{
		if (n % i == 0)
		{
			printf("%d*", i);
			fprime(n / i);
			return;	
		}
		i++;
	}
	printf("%d", n);
}

int		main(int argc, char **argv)
{
	int nbr;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		fprime(nbr);	 
	}
	printf("\n");
	return (0);
}
