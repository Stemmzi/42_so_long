/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:42:32 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:49:01 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	size;

	size = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size);
}

static int	int_negative(char *ptr, int n)
{
	int	max;

	if (n == -2147483648)
	{
		ptr[0] = '-';
		ptr[1] = '2';
		n = 147483648;
		max = 2;
	}
	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
		max = 1;
	}
	return (max);
}

char	*ft_itoa(int n)
{
	int		len;
	int		max;
	char	*ptr;

	len = int_len(n);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	max = 0;
	if (n < 0)
	{
		max = int_negative(ptr, n);
		if (max == 2)
			n = -147483648;
		n *= -1;
	}
	while (len > max)
	{
		ptr[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (ptr);
}
