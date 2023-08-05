/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:25:54 by shimakaori        #+#    #+#             */
/*   Updated: 2023/07/30 17:03:03 by asasada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
