/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:51:31 by sgeiger           #+#    #+#             */
/*   Updated: 2024/03/11 18:41:58 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	uint_len(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	int		max;
	char	*ptr;

	len = uint_len(n);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	max = 0;
	while (len > max)
	{
		ptr[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (ptr);
}

int	ft_print_unsigned_bonus(unsigned int u)
{
	int		count;
	char	*str;

	str = ft_uitoa(u);
	if (str == NULL)
		return (-1);
	count = ft_print_string_bonus(str);
	free(str);
	if (count == -1)
		return (-1);
	return (count);
}
