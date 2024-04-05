/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:43 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/05 16:51:14 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	// mlx_set_setting(MLX_MAXIMIZED, true);
	game.mlx = mlx_init(64, 64, "Your future gamedev!", true);
	if (argc == 2)
	{
		create_map(&game, argv);
	}
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free(game.map);
	return (0);
}
