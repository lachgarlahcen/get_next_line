/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:58:58 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/12 13:13:48 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		index_of_next(char const *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;
	int		e;

	if (!s || !c ||
			!(tab = (char **)malloc(sizeof(char *) * (ft_calcd(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i - 1] == c && i != 0) || (i == 0 && s[i] != c))
		{
			j = index_of_next(s, i, c);
			e = ft_strlen(ft_strsub(s, i, (j - i)));
			tab[k] = (char *)malloc(e + 1);
			ft_memcpy(tab[k++], ft_strsub(s, i, (j - i)), e + 1);
			i = j;
		}
		i++;
	}
	tab[k] = NULL;
	return (tab);
}
