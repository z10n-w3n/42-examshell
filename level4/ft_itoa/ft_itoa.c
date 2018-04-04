/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:31:03 by zwen              #+#    #+#             */
/*   Updated: 2018/04/03 18:59:23 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	char	*a;
	char	*tmp;
	int		neg;

	i = 1;
	len = (nbr < 0) ? 2 : 1;
	neg = (nbr < 0) ? -1 : 1;
	while (nbr / i > 9 || nbr / i < -9)
	{
		i *= 10;
		len++;
	}
	a = (char *)malloc(sizeof(*a) * (len + 1));
	tmp = a;
	if (nbr < 0)
	{
		*tmp = '-';
		tmp++;
	}
	while (i > 0)
	{
		*tmp = '0' + (nbr / i) * neg;
		nbr = nbr % i;
		i /= 10;
		tmp++;
	}
	*tmp = '\0';
	return (a);
}
