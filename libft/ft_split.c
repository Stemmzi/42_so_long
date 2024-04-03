/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:16 by sgeiger           #+#    #+#             */
/*   Updated: 2024/01/24 19:50:32 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(const char *s, char c)
{
	int	count;
	int	word_count;
	int	flag;

	count = 0;
	word_count = 0;
	flag = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c && flag == 0)
		{
			word_count++;
			flag = 1;
		}
		else if (s[count] == c && flag == 1)
		{
			flag = 0;
		}
		count++;
	}
	return (word_count);
}

static int	get_start(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c)
			return (count);
		count++;
	}
	return (count);
}

static int	get_len(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
			return (count);
		count++;
	}
	return (count);
}

static char	**free_mem(char **s, int count)
{
	while (count >= 0)
	{
		free(s[count]);
		count--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		words;
	int		arrcount;
	int		start;
	int		len;

	arrcount = 0;
	start = 0;
	words = get_word_count(s, c);
	ptr = malloc((words + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (words > 0)
	{
		start = start + get_start(s + start, c);
		len = get_len(s + start, c);
		ptr[arrcount] = ft_substr(s, start, len);
		if (ptr[arrcount] == NULL)
			return (free_mem(ptr, arrcount));
		arrcount++;
		start = start + len + 1;
		words--;
	}
	ptr[arrcount] = NULL;
	return (ptr);
}
