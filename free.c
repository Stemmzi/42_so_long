/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:33:53 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/22 01:20:49 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_textures tex)
{
	if (tex.path)
		mlx_delete_texture(tex.path);
	if (tex.wall)
		mlx_delete_texture(tex.wall);
	if (tex.collect)
		mlx_delete_texture(tex.collect);
	if (tex.exit_c)
		mlx_delete_texture(tex.exit_c);
	if (tex.exit_o)
		mlx_delete_texture(tex.exit_o);
	if (tex.player)
		mlx_delete_texture(tex.player);
}

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
}

void	clean_exit(t_game *game)
{
	free_textures(game->textures);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.grid)
		free_map(game->map.grid);
	if (game->my_error != NULL)
		write(STDOUT_FILENO, game->my_error, ft_strlen(game->my_error));
	else if (mlx_errno != 0)
		ft_mlx_error();
	else if (errno != 0)
		perror("Error");
	exit(EXIT_FAILURE);
}
