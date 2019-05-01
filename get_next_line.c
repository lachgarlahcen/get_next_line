/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:43:39 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/16 18:46:33 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_the_line(char **s, char **line, int fd)
{
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		*line = ft_strsub(s[fd], 0, len);
		s[fd] = ft_strdup(s[fd] + len + 1);
	}
	else if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[256];
	char		buf[BUFF_SIZE + 1];
	int			p;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((p = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[p] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		s[fd] = ft_strjoin(s[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (p < 0)
		return (-1);
	else if (p == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (get_the_line(s, line, fd));
}
