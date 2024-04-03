/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:12:23 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 18:50:39 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flag_hashtag(va_list args, t_flag *s1, char c)
{
	int				count;
	unsigned int	j;

	s1->i_flag = 2;
	count = 0;
	j = va_arg(args, unsigned int);
	if (j <= 0)
		count = write(1, "0", 1);
	else if (c == 'x')
	{
		count = write(1, "0x", 2);
		count += ft_print_hexa_bonus(j, 87);
	}
	else if (c == 'X')
	{
		count = write(1, "0X", 2);
		count += ft_print_hexa_bonus(j, 55);
	}
	return (count);
}

static int	flag_spaceplus(va_list args, t_flag *s1, char c, char flag)
{
	int	count;
	int	i;

	count = 0;
	if (c == 's')
		count += ft_print_string_bonus(va_arg(args, char *));
	else
	{
		i = va_arg(args, int);
		if (i >= 0)
		{
			if (flag == ' ')
				count = write(1, " ", 1);
			else if (flag == '+')
				count = write(1, "+", 1);
		}
		count += ft_print_nbr_bonus(i);
	}
	s1->i_flag = 2;
	return (count);
}

int	ft_flags_bonus(va_list args, char flag, t_flag *s1, const char *ptr)
{
	int				count;
	char			c;

	c = ptr[1];
	count = 0;
	if (flag == '#')
		count = flag_hashtag(args, s1, c);
	else if (flag == ' ' || flag == '+')
		count = flag_spaceplus(args, s1, c, flag);
	return (count);
}
