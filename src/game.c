/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:11:36 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/08 20:15:38 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_game *game)
{
	(void)game;
	return (1);
}

int	load_textures(t_game *game)
{
	(void)game;
	return (1);
}

void	init_game(char *filename)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map_file(filename, &game.map))
	{
		ft_putstr_fd("Error:\nInvalid map\n", 2);
		free_map(&game.map);
		return ;
	}
	if (!init_mlx(&game))
	{
		ft_putstr_fd("Error:\nMLX init failed\n", 2);
		free_map(&game.map);
		return ;
	}
	if (!load_textures(&game))
	{
		ft_putstr_fd("Error:\nTexture loading failed\n", 2);
		free_map(&game.map);
		return ;
	}
	free_map(&game.map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <map.cub>\n", 2);
		return (1);
	}
	init_game(av[1]);
	return (0);
}
