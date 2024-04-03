/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:59:46 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:51:22 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	safe;

	count = 0;
	safe = -1;
	while (s[count] != '\0')
	{
		if (s[count] == (char)c)
			safe = count;
		count++;
	}
	if (safe >= 0)
		return ((char *)s + safe);
	if (s[count] == (char)c)
		return ((char *)s + count);
	return (0);
}
