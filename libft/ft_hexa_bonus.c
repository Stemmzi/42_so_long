/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:10:29 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 18:50:37 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hex_len(unsigned long n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (1);
	while (n / 16 > 0 && size < 17)
	{
		size++;
		n /= 16;
	}
	return (size);
}

char	*ft_hexa_bonus(unsigned long n, int flag)
{
	int		len;
	char	*ptr;

	len = hex_len(n);
	if (len == 17)
		len--;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15)
			ptr[len] = n % 16 + flag;
		else
			ptr[len] = n % 16 + 48;
		n /= 16;
		len--;
	}
	return (ptr);
}
