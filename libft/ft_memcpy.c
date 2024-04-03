/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:38:19 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:49:47 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	count = 0;
	if (ptr_dst == NULL && ptr_src == NULL)
		return (NULL);
	while (count < n)
	{
		ptr_dst[count] = ptr_src[count];
		count++;
	}
	return (dst);
}
