/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:18:10 by zwen              #+#    #+#             */
/*   Updated: 2018/04/05 09:33:44 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		pgcd(int a, int b)
{
	int big;
	int small;
	int rem;

	big = a > b ? a : b;
	small = a <= b ? a : b;
	rem = big % small;
	while (rem != 0)
	{
		big = small;
		small = rem;
		rem = big % small;
	}
	return (small);
}

int		main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d", pgcd(a, b));
	}
	printf("\n");
	return (0);
}
