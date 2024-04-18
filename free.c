/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:33:53 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/18 18:27:01 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int		count;

	count = 0;
	while (map[count] != NULL)
	{
		free(map[count]);
		count++;
	}
	free(map);
}

void	ft_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	ft_mlx_error(void)
{
	size_t		len;
	const char	*str;

	str = mlx_strerror(mlx_errno);
	len = ft_strlen(str);
	write(STDOUT_FILENO, &str, len);
	exit(EXIT_FAILURE);
}
