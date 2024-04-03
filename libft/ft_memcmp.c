/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:06:43 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:49:42 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				count;
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;

	count = 0;
	ptr1 = s1;
	ptr2 = s2;
	while (count < n)
	{
		if (ptr1[count] == ptr2[count])
			count++;
		else if (ptr1[count] != ptr2[count])
			return (ptr1[count] - ptr2[count]);
	}
	return (0);
}
