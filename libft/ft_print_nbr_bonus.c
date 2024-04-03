/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:14:58 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 18:50:27 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr_bonus(int n)
{
	int		count;
	char	*str;

	str = ft_itoa(n);
	if (str == NULL)
		return (-1);
	count = ft_print_string_bonus(str);
	free(str);
	if (count == -1)
		return (-1);
	return (count);
}
