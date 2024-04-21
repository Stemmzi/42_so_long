/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:43 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/22 01:22:29 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	mlx_set_setting(MLX_MAXIMIZED, true);
	game.mlx = mlx_init(16, 16, "Your future gamedev!", true);
	if (!game.mlx)
		ft_mlx_error();
	if (argc != 2)
	{
		game.my_error = "Error: Input has to be: \"./game <map.ber>\"\n";
		clean_exit(&game);
	}
	init_map(&game, argv);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map.grid);
	free_textures(game.textures);
	return (0);
}
