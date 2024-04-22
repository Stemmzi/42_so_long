/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:45 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/22 19:07:32 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_map_values(t_game *game, char *line)
{
	int	c;

	c = 0;
	game->map.grid = ft_split(line, '\n');
	free(line);
	if (!game->map.grid)
		clean_exit(game);
	game->map.length = ft_strlen(game->map.grid[c]);
	while (game->map.grid[c] != NULL)
		c++;
	game->map.height = c;
}

void	load_map(t_game *game, char **argv)
{
	char	*line;
	char	*temp;
	char	*buf;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		clean_exit(game);
	line = (char *)malloc(sizeof(char));
	if (!line)
		clean_exit(game);
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		temp = ft_strjoin(line, buf);
		free(line);
		free(buf);
		if (!temp)
			clean_exit(game);
		line = temp;
		buf = get_next_line(fd);
	}
	set_map_values(game, line);
	close(fd);
}

static void	build_tile(t_game *game, char c, int x, int y)
{
	int			size;

	size = TILESIZE * SCALE;
	if (c == '0')
		ft_mlx_image_to_window(game, game->path, size * x, size * y);
	if (c == '1')
		ft_mlx_image_to_window(game, game->wall, size * x, size * y);
	if (c == 'C')
	{
		ft_mlx_image_to_window(game, game->path, size * x, size * y);
		ft_mlx_image_to_window(game, game->collect, size * x, size * y);
		game->collect_count++;
	}
	if (c == 'E')
		ft_mlx_image_to_window(game, game->exit_c, size * x, size * y);
	if (c == 'P')
	{
		ft_mlx_image_to_window(game, game->path, size * x, size * y);
		game->player.x = x;
		game->player.y = y;
	}
}

void	build_map(t_game *game)
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
	ft_mlx_image_to_window(game, game->player.skin,
		game->player.x * size, game->player.y * size);
	game->player.moves = 0;
}

void	init_map(t_game *game, char *argv[])
{
	int	size;
	int	width;
	int	height;

	size = TILESIZE * SCALE;
	width = 0;
	height = 0;
	load_map(game, argv);
	check_map(game);
	init_imgs(game);
	build_map(game);
	mlx_get_monitor_size(0, &width, &height);
	if (game->map.length * size > width || game->map.height * size > height)
	{
		game->my_error = "Map is larger than monitor size\n";
		clean_exit(game);
	}
	mlx_set_window_size(game->mlx, game->map.length * size,
		game->map.height * size);
	mlx_set_window_pos(game->mlx, width / 2 - game->map.length * size / 2,
		height / 2 - game->map.height * size / 2);
}
