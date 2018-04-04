/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:08:49 by zwen              #+#    #+#             */
/*   Updated: 2018/04/03 21:14:53 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char 	*res;
	char	t[16] = "0123456789ABCDEF";
	int		i;
	int		len;

	i = 1;
	len = (base == 10 && value < 0) ? 2 : 1;
	while (value / i >= base || value / i <= -base)
	{
		i *= base;
		len++;
	}
	res = (char *)malloc(sizeof(*res) * (len + 1));
	res[len] = '\0';
	while (len > 0)
	{
		res[--len] = value % base < 0 ? t[-(value % base)] : t[value % base];
		value /= base;

	}
	res[0] = res[0] == '0' ? '-' : res[0];
	return (res);
}
