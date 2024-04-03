/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:44:58 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:51:17 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	count;
	size_t			needle_len;

	count = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (haystack[count] != '\0' && count + needle_len <= len)
	{
		if (ft_strncmp(haystack + count, needle, needle_len) == 0)
			return ((char *)haystack + count);
		count++;
	}
	return (0);
}
