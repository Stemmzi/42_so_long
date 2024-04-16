/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:45 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/17 00:28:43 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, char **argv)
{
	char	*line;
	char	*temp;
	char	*buf;
	int		fd;
	int		c;

	c = 0;
	fd = open(argv[1], O_RDONLY);
	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		temp = ft_strjoin(line, buf);
		free(buf);
		line = temp;
		buf = get_next_line(fd);
	}
	game->map.grid = ft_split(line, '\n');
	game->map.length = ft_strlen(game->map.grid[c]);
	while (game->map.grid[c] != NULL)
		c++;
	game->map.height = c;
	close(fd);
}

void	build_tile(t_game *game, char c, int x, int y)
{
	int			size;

	size = TILESIZE * SCALE;
	if (c == '0')
		mlx_image_to_window(game->mlx, game->path, size * x, size * y);
	if (c == '1')
		mlx_image_to_window(game->mlx, game->wall, size * x, size * y);
	if (c == 'C')
	{
		mlx_image_to_window(game->mlx, game->path, size * x, size * y);
		mlx_image_to_window(game->mlx, game->collect, size * x, size * y);
		game->collect_count++;
	}
	if (c == 'E')
		mlx_image_to_window(game->mlx, game->exit_c, size * x, size * y);
	if (c == 'P')
	{
		mlx_image_to_window(game->mlx, game->path, size * x, size * y);
		game->player.x = x;
		game->player.y = y;
	}
}

int	build_map(t_game *game)
{
	int	x;
	int	y;
	int	size;

	x = 0;
	y = 0;
	size = TILESIZE * SCALE;
	while (y < game->map.height)
	{
		while (x < game->map.length)
		{
			build_tile(game, game->map.grid[y][x], x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(game->mlx, game->player.skin,
		game->player.x * size, game->player.y * size);
	game->player.moves = 0;
	return (0);
}

int	init_map(t_game *game, char *argv[])
{
	int	y;
	int	size;

	y = 0;
	size = TILESIZE * SCALE;
	game->map.grid = (char **)malloc(sizeof(char *));
	load_map(game, argv);
	check_map(game);
	load_textures(game);
	build_map(game);
	mlx_set_window_size(game->mlx, game->map.length * size,
		game->map.height * size);
	return (0);
}
