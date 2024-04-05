/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:45 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/05 16:50:18 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_line(t_game *game, char *line)
{
	static int	y;
	int			x;
	int			len;

	x = 0;
	len = ft_strlen(line);
	while (x < len)
	{
		if (line[x] == '0')
		{
			build_space(game->mlx, x, y);
		}
		if (line[x] == '1')
		{
			build_wall(game->mlx, x, y);
		}
		// if (line[x] == 'C')
		// 	build_collectible(line, x);
		// if (line[x] == 'E')
		// 	build_exit(line, x);
		if (line[x] == 'P')
			build_player(game, game->mlx, x, y);
		x++;
	}
	mlx_set_window_size(game->mlx, 64 * 13, 64 * 5);
	y++;
}

int	create_map(t_game *game, char *argv[])
{
	char	*line;
	int		fd;
	int		c;

	c = 0;
	game->map = (char **)malloc(sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		game->map[c] = line;
		build_line(game, line);
		c++;
	}
	game->map[c] = NULL;
	c = 0;
	close(fd);
	return (0);
}
