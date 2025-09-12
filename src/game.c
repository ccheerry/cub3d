/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:11:36 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/12 17:52:55 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_game *game)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	game->mlx = mlx;
	return (1);
}

void	init_game(char *filename)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error:\nMalloc failed\n", 2);
		return ;
	}
	if (!init_mlx(game))
	{
		ft_putstr_fd("Error:\nMLX init failed\n", 2);
		ft_free((void **)&game);
		return ;
	}
	if (!parse_map_file(filename, &game->map, game))
	{
		ft_putstr_fd("Error:\nInvalid map\n", 2);
		free_map(&game->map);
		ft_free((void **)&game);
		return ;
	}
	ft_printf("Map loaded!\n");
	ft_printf("Map size: %dx%d\n", game->map.width, game->map.height);
	ft_printf("Floor color: RGB(%d, %d, %d)\n",
		game->map.colors.floor_r, game->map.colors.floor_g,
		game->map.colors.floor_b);
	ft_printf("Ceiling color: RGB(%d, %d, %d)\n",
		game->map.colors.ceiling_r, game->map.colors.ceiling_g,
		game->map.colors.ceiling_b);
	ft_printf("Map grid:\n");
	for (int i = 0; i < game->map.height; i++)
		ft_printf("%s", game->map.grid[i]);
	free_map(&game->map);
	ft_free((void **)&game);
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
