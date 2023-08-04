/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:38:22 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/05 00:21:32 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int				loop_game(t_game *game);
static int		key_presshook(int keycode, t_game *game);
static int		key_releasehook(int keycode, t_game *game);
int				close_window(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Arguments need cubfile.");
	game = init_game(game);
	set_game(&game, argv[1]);
	mlx_hook(game.win, KeyPress, KeyPressMask, key_presshook, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_releasehook, &game);
	mlx_hook(game.win, ClientMessage, StructureNotifyMask, close_window, &game);
	mlx_loop_hook(game.mlx, &loop_game, &game);
	mlx_loop(game.mlx);
	close_window(&game);
	return (0);
}

int	loop_game(t_game *game)
{
	draw_wall(game);
	move_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.image, 0, 0);
	return (0);
}

static int	key_presshook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_window(game);
	else if (keycode == W_KEY)
		game->player.is_move_ns = 1;
	else if (keycode == S_KEY)
		game->player.is_move_ns = -1;
	else if (keycode == A_KEY)
		game->player.is_move_ew = -1;
	else if (keycode == D_KEY)
		game->player.is_move_ew = 1;
	else if (keycode == LEFT_KEY)
		game->player.is_turning = -1;
	else if (keycode == RIGHT_KEY)
		game->player.is_turning = 1;
	return (0);
}

static int	key_releasehook(int keycode, t_game *game)
{
	if (keycode == W_KEY || keycode == S_KEY)
		game->player.is_move_ns = 0;
	else if (keycode == A_KEY || keycode == D_KEY)
		game->player.is_move_ew = 0;
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		game->player.is_turning = 0;
	return (0);
}

int	close_window(t_game *game)
{
	free_map(&game->map);
	mlx_destroy_image(game->mlx, game->img.image);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
