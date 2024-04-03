/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:57:21 by sgeiger           #+#    #+#             */
/*   Updated: 2023/10/25 16:13:15 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int i)
{
	int	size;

	size = 1;
	while (i / 10 != 0)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

static int	ft_nbr_is_positive(int n, int size, int fd)
{
	int	count;
	int	calc;

	while (0 < size)
	{
		count = 0;
		calc = n;
		while (count < size - 1)
		{
			calc = calc / 10;
			count++;
		}
		calc = calc % 10;
		ft_putchar_fd(calc + '0', fd);
		size--;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	size;

	size = ft_intlen(n);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 0)
		n = ft_nbr_is_positive(n, size, fd);
}
