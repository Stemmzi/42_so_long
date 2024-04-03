/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:15:23 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/29 21:37:49 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strprep(t_gnl *s1)
{
	char	*rline;
	size_t	len;

	if (s1->br < 1)
	{
		if (s1->line && s1->line[0] != '\0' && s1->br >= 0)
		{
			len = ft_strlen(s1->line);
			rline = ft_substr(s1->line, 0, len);
			if (rline == NULL)
				return (NULL);
			rline[len] = '\0';
			return (rline);
		}
		else
			return (NULL);
	}
	s1->nl = ft_strchr(s1->line, '\n');
	len = (ft_strlen(s1->line) - ft_strlen(s1->nl) + 1);
	rline = ft_substr(s1->line, 0, len);
	if (rline == NULL)
		return (NULL);
	rline[len] = '\0';
	return (rline);
}

static int	stradd_nl0(t_gnl *s1, char *buf, int fd)
{
	char	*temp;

	while ((s1->br > 0) && (!ft_strchr(s1->line, '\n')))
	{
		temp = ft_strjoin(s1->line, buf);
		if (!temp)
			return (1);
		free(s1->line);
		s1->line = temp;
		if (ft_strchr(s1->line, '\n'))
		{
			s1->nl = ft_strchr(buf, '\n');
			ft_memmove(buf, s1->nl + 1, ft_strlen(s1->nl));
			buf[ft_strlen(buf)] = '\0';
			return (0);
		}
		s1->br = read(fd, buf, BUFFER_SIZE);
		if (s1->br < 0)
			return (buf[0] = '\0', 0);
		buf[s1->br] = '\0';
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	t_gnl		s1;

	s1.line = NULL;
	s1.br = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (s1.line == NULL)
	{
		s1.line = (char *)malloc(sizeof(char));
		if (!s1.line)
			return (NULL);
		s1.line[0] = '\0';
	}
	if (stradd_nl0(&s1, buf, fd))
		return (free(s1.line), NULL);
	line = strprep(&s1);
	free(s1.line);
	return (line);
}
