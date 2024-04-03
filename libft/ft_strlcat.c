/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:38:07 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:50:53 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	slen = 0;
	dlen = 0;
	while (dst[dlen] != '\0' && dlen < dstsize)
		dlen++;
	i = dlen;
	while (src[slen] != '\0')
		slen++;
	if (dlen >= dstsize)
		return (dlen + slen);
	while (i < dstsize - 1 && src[i - dlen])
	{
		dst[i] = src[i - dlen];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (dlen + slen);
}
