/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:43 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/24 01:27:32 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_input(t_game *game, int argc, char *argv[])
{
	size_t	len;

	len = ft_strlen(argv[1]);
	if (argc != 2)
	{
		game->my_error = "Error: Input has to be: \"./game <map.ber>\"\n";
		clean_exit(game);
	}
	if (len <= 4 || ft_strcmp(argv[1] + len - 4, ".ber") != 0)
	{
		game->my_error = "Error: Input file has to be \".ber\"\n";
		clean_exit(game);
	}
}

static void	check_success(t_game *game)
{
	if (game->player.x != game->map.exit_pos.x
		|| game->player.y != game->map.exit_pos.y)
	{
		ft_printf("Game closed\n");
		exit (EXIT_FAILURE);
	}
	ft_printf("Game Won - Congrats\n");
}

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	game.mlx = mlx_init(16, 16, "Your future gamedev!", false);
	if (!game.mlx)
		ft_mlx_error();
	check_input(&game, argc, argv);
	init_map(&game, argv);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_textures(game.textures);
	free_map(game.map.grid);
	free_array(&game, game.map.paths);
	check_success(&game);
	return (0);
}
