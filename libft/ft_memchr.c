/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:06:51 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:49:30 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	int					i;

	i = 0;
	ptr = (unsigned char *)s;
	while (n > 0 && ptr[i] != (unsigned char)c)
	{
		n--;
		i++;
	}
	if (n == 0 || ptr == NULL)
		return (0);
	return ((void *)&(ptr[i]));
}
