/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:59:56 by zwen              #+#    #+#             */
/*   Updated: 2018/03/30 17:05:01 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		p;
	int		*bytes;
	
	bytes = (int *)malloc(sizeof(*bytes) * 2049);
	p = 0;
	while (p < 2048)
	{
		bytes[p] = 0;
		p++;
	}

	if (argc == 2)
	{
		argv++;
		p = 0;
		while (**argv)
		{
			if (**argv == '+')
				bytes[p]++;
			else if (**argv == '-')
				bytes[p]--;
			else if (**argv == '>')
				p++;
			else if (**argv == '<')
				p--;
			else if (**argv == '[' && bytes[p] == 0)



			(*argv)++;
		}
	write(1, "\n", 1);
}
