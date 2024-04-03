/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:00:20 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:48:21 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	full;

	full = count * size;
	ptr = malloc(full);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, full);
		return (ptr);
	}
	else
		return (NULL);
}
