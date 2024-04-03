/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:21:31 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:51:26 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	front;
	char	*ptr;

	len = ft_strlen(s1);
	front = 0;
	if (set[0] == '\0' || s1[0] == '\0')
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[front]) != 0)
		front++;
	while (ft_strrchr(set, s1[len - 1]) != 0)
		len--;
	ptr = ft_substr(s1, front, len - front);
	return (ptr);
}
