/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:33:04 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:49:56 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	if (dst2 < src2)
	{
		while (len > 0)
		{
			*dst2++ = *src2++;
			len--;
		}
	}
	else if (dst2 > src2)
	{
		dst2 += len -1;
		src2 += len -1;
		while (len > 0)
		{
			*dst2-- = *src2--;
			len--;
		}
	}
	return (dst);
}
