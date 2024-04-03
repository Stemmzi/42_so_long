/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_vptr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:34:02 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 18:50:20 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_vptr_bonus(unsigned long n)
{
	char		*str;
	int			count;
	int			w;

	count = ft_print_string_bonus("0x");
	if (count == -1)
		return (-1);
	str = ft_hexa_bonus(n, 87);
	if (str == NULL)
		return (-1);
	w = count;
	count += ft_print_string_bonus(str);
	free(str);
	if (w > count)
		return (-1);
	return (count);
}
