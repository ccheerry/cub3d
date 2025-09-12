/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:10:02 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/10 18:44:14 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "lft.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define TEXTURE_SIZE 64
# define FOV 60

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_textures;

typedef struct s_colors
{
	int	floor_r;
	int	floor_g;
	int	floor_b;
	int	ceiling_r;
	int	ceiling_g;
	int	ceiling_b;
}	t_colors;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	char	orientation;
}	t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_player	player;
	t_colors	colors;
	t_textures	textures;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	t_map		map;
	int			tex_width;
	int			tex_height;
}	t_game;

bool	parse_map_file(char *filename, t_map *map, t_game *game);
bool	is_valid_line(char *line);
bool	parse_elements(char *line, t_map *map, t_game *game);
bool	validate_textures(t_map *map);
void	init_game(char *filename);
void	free_map(t_map *map);
int		init_mlx(t_game *game);

#endif
