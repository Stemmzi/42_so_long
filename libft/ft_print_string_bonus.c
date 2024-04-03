/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:26:40 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 18:50:25 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_string_bonus(char *str)
{
	int	count;

	count = 6;
	if (str == NULL)
	{
		count = write(1, "(null)", count);
		return (count);
	}
	count = ft_strlen(str);
	count = write(1, str, count);
	return (count);
}
