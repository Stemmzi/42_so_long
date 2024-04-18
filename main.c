/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:54:43 by sgeiger           #+#    #+#             */
/*   Updated: 2024/04/18 18:24:44 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	update(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// }

int	main(int argc, char *argv[])
{
	t_game	game;

	mlx_set_setting(MLX_MAXIMIZED, true);
	game.mlx = mlx_init(64, 64, "Your future gamedev!", true);
	if (!game.mlx)
		ft_mlx_error();
	if (argc == 2)
		init_map(&game, argv);
	mlx_key_hook(game.mlx, key_hook, &game);
	// mlx_loop_hook(game.mlx, update, &game);

	mlx_loop(game.mlx);

	mlx_terminate(game.mlx);
	free(game.map.grid);
	return (0);
}
