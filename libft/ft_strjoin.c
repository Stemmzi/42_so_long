/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:34:26 by sgeiger           #+#    #+#             */
/*   Updated: 2023/10/30 13:10:20 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	max_len;

	max_len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(max_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, max_len + 1);
	ft_strlcat(ptr, s2, max_len + 1);
	return (ptr);
}
