/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:46:43 by sgeiger           #+#    #+#             */
/*   Updated: 2024/02/18 18:50:12 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(va_list args, char format, t_flag *s1, const char *ptr)
{
	int		print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_print_char_bonus(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_string_bonus(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_vptr_bonus(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr_bonus(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned_bonus(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_print_hexa_bonus(va_arg(args, unsigned int), 87);
	else if (format == 'X')
		print_len += ft_print_hexa_bonus(va_arg(args, unsigned int), 55);
	else if (format == '%')
		print_len += ft_print_char_bonus('%');
	else if (format == ' ' || format == '#' || format == '+')
		print_len += ft_flags_bonus(args, format, s1, ptr);
	if (print_len < 0)
		return (-1);
	return (print_len);
}

static int	ft_printf_helper(va_list args, t_flag s1, int len, const char *ptr)
{
	int	w;

	while (*ptr != '\0')
	{
		s1.i_flag = 0;
		w = len;
		if (*ptr == '%')
		{
			ptr++;
			len += ft_format(args, *ptr, &s1, ptr);
		}
		else
			len += ft_print_char_bonus(*ptr);
		if (w > len)
			return (-1);
		if (s1.i_flag == 0)
			ptr += 1;
		else
			ptr += s1.i_flag;
	}
	return (len);
}

int	ft_printf(const char *ptr, ...)
{
	int		print_len;
	va_list	vlist;
	t_flag	s1;

	print_len = 0;
	s1.i_flag = 0;
	va_start(vlist, ptr);
	print_len += ft_printf_helper(vlist, s1, print_len, ptr);
	va_end(vlist);
	return (print_len);
}
