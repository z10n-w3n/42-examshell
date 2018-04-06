/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 21:58:05 by zwen              #+#    #+#             */
/*   Updated: 2018/04/05 22:43:34 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int     main(int argc, char **argv)
{
	int		i;
	int		count;
	int		*index;

    if (argc == 2)
    {
        argv++;
		i = 0;
		count = 0;
		while ((*argv)[i])
		{
			if ((*argv)[i] == ' ')
				count++;
			i++;
		}
		index = (int *)malloc(sizeof(*index) * (count + 1));
		index[0] = 0;
		i = 0;
		count = 0;
		while ((*argv)[i])
		{
			if ((*argv)[i] == ' ')
				index[++count] = ++i;
			else
				i++;
		}
		while (count >= 0)
		{
			i = index[count--];
			while ((*argv)[i] && (*argv)[i] != ' ')
				write (1, *argv + i++, 1);
			if (count >= 0)
				write(1, " ", 1);
		}
		free(index);
	}
    write(1, "\n", 1);
    return (0);
}

