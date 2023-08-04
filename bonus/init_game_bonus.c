/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:25:54 by shimakaori        #+#    #+#             */
/*   Updated: 2023/08/04 23:58:06 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

t_game	init_game(t_game game)
{
	game = (t_game){0};
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		error_exit("Failed to init mlx");
	game.win = mlx_new_window(game.mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	if (game.win == NULL)
		error_exit("Failed to create window");
	return (game);
}
