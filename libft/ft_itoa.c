/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:03:36 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/10 20:47:46 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	n1;
	char	*str;
	int		i;

	n1 = n;
	i = ft_calclen(n1);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n1 < 0)
	{
		n1 *= -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	while (n1)
	{
		str[i--] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (str);
}
