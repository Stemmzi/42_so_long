/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:16:05 by sgeiger           #+#    #+#             */
/*   Updated: 2023/10/24 15:23:15 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t		size;
	char		*ptr;

	size = ft_strlen(s1);
	ptr = malloc(size + 1);
	if (ptr != NULL)
	{
		ft_strcpy(ptr, s1);
		return (ptr);
	}
	else
		return (NULL);
}
