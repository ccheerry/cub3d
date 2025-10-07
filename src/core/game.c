/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:11:36 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 01:38:46 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** init_mlx:
**   Inicializa la MiniLibX y guarda el puntero en game->mlx.
**   Devuelve 1 si la inicialización fue correcta, 0 si falló.
*/
int	init_mlx(t_game *game)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		return (0);
	game->mlx = mlx;
	return (1);
}

/* game_init_enemies.c (si prefieres separarlo) */

int	game_init_enemies(t_game *g)
{
	if (!find_enemies(g))
	{
		ft_putstr_fd("Error\nfind_enemies failed\n", 2);
		return (0);
	}
	if (!load_enemy_textures(g))
	{
		ft_putstr_fd("Error\nload_enemy_textures failed\n", 2);
		return (0);
	}
	return (1);
}

int	game_init_doors(t_game *g)
{
	if (!find_doors(g))
	{
		ft_putstr_fd("Error\nfind_doors failed\n", 2);
		return (0);
	}
	if (!load_door_texture(g))
	{
		ft_putstr_fd("Error\nload_door_textures failed\n", 2);
		return (0);
	}
	return (1);
}

/*
** init_game:
**   Reserva e inicializa la estructura principal del juego.
**   - Inicializa MLX.
**   - Parsea el mapa (.cub) y carga texturas/colores.
**   - Ajusta la posición inicial del jugador al centro de la celda.
**   - Crea la ventana y entra en el bucle de eventos de MLX.
**   En caso de error, muestra mensaje y libera la memoria asociada.
*/
void	init_game(char *filename)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Error:\nMalloc failed\n", 2));
	game->map.colors.floor_r = -1;
	game->map.colors.floor_g = -1;
	game->map.colors.floor_b = -1;
	game->map.colors.ceiling_r = -1;
	game->map.colors.ceiling_g = -1;
	game->map.colors.ceiling_b = -1;
	if (!init_mlx(game))
		return (ft_putstr_fd("Error:\nMLX init failed\n", 2),
			free(game));
	if (!parse_map_file(filename, &game->map, game))
		return (ft_putstr_fd("Error:\nInvalid map\n", 2),
			free_mlx(game), free_map(&game->map), free(game));
	game->map.player.x += 0.5f;
	game->map.player.y += 0.5f;
	game_init_enemies(game);
	game_init_doors(game);
	if (!start_window(game))
		return (ft_putstr_fd("Error:\nWindow init failed\n", 2),
			free_map(&game->map), free_mlx(game), free(game));
	mlx_loop(game->mlx);
}

/*
** main:
**   Punto de entrada del programa. Verifica los argumentos y
**   lanza la inicialización del juego con el archivo .cub.
**   Devuelve 0 si la ejecución comienza correctamente, 1 si el
**   uso es incorrecto.
*/
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
