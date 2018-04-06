/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwen <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 00:55:44 by zwen              #+#    #+#             */
/*   Updated: 2018/04/05 17:37:31 by zwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		check_base(char c, int str_base)
{
	char	hex[16] = "0123456798abcdef";

	if (c <= 'F' && c >= 'A')
		c += 32;
	while (str_base >= 0)
	{
		if (hex[str_base] == c)
			return (str_base);
		str_base--;
	}
	return (str_base);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		res;
	int		neg;
	int		digit;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] =='\r' || str[i] == '\f')
		i++;
	neg = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	digit = check_base(str[i], str_base);
	while (digit != -1)
	{
		res = res * str_base + digit;
		i++;
		digit = check_base(str[i], str_base);
	}
	return (res * neg);
}

int		main(void)
{
	printf("%d \n", ft_atoi_base("-ffF", 16));
}
