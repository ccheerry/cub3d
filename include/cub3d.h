/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:10:02 by acerezo-          #+#    #+#             */
/*   Updated: 2025/10/07 17:05:20 by acerezo-         ###   ########.fr       */
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

# ifndef CUB3D_MATH_FALLBACK
#  define CUB3D_MATH_FALLBACK

double	cos(double x);
double	sin(double x);
double	tan(double x);
double	atan(double x);
double	fabs(double x);
double	floor(double x);
double	atan2(double y, double x);
double	sqrt(double x);

# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WINDOW_WIDTH 1600
# define WINDOW_HEIGHT 900
# define TEXTURE_SIZE 64
# define FOV 60
# define PLAYER_RADIUS 0.30f   /* previously 0.25f -> keeps you further from walls */
# define WALL_PADDING  0.05f   /* extra margin to prevent wall clipping */
# define NEAR_CLIP     0.50f   /* minimum distance clipping in raycast */

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17
# define MASK_KEYPRESS 1
# define MASK_KEYRELEASE 2
# define MASK_STRUCT 131072

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

/* === Sprites / Enemies === */
# ifndef ENEMY_FRAMES
#  define ENEMY_FRAMES 4
# endif
# ifndef ANIM_TPF
#  define ANIM_TPF 8
# endif
# ifndef SPRITE_KEYCOLOR
#  define SPRITE_KEYCOLOR 0x00FF00FF
# endif

/* === Minimap === */
# ifndef MM_TILE
#  define MM_TILE 10
# endif
# ifndef MM_W_TILES
#  define MM_W_TILES 20
# endif
# ifndef MM_H_TILES
#  define MM_H_TILES 20
# endif
# ifndef MM_PAD
#  define MM_PAD 8
# endif

# ifndef MM_COLOR_WALL
#  define MM_COLOR_WALL 0x00444444
# endif
# ifndef MM_COLOR_FLOOR
#  define MM_COLOR_FLOOR 0x00999999
# endif
# ifndef MM_COLOR_PLAYER
#  define MM_COLOR_PLAYER 0x0000FF00
# endif
# ifndef MM_COLOR_ENEMY
#  define MM_COLOR_ENEMY 0x00FF0000
# endif

/* === Doors === */
# ifndef DOOR_PROX
#  define DOOR_PROX 1.2f
# endif
# ifndef DOOR_HYST
#  define DOOR_HYST 0.3f
# endif
# ifndef DOOR_SPEED
#  define DOOR_SPEED 0.08f
# endif

/* === Mouse look === */
# ifndef MOUSE_SENS
#  define MOUSE_SENS 0.10f/* degrees per pixel */
# endif
# ifndef MOUSE_MAX_STEP
#  define MOUSE_MAX_STEP 20/* max pixels per event */
# endif
# ifndef MOUSE_DEAD
#  define MOUSE_DEAD 2/* dead zone in pixels */
# endif

typedef struct s_mouse
{
	int		enabled;
	int		last_x;
	int		last_y;
}	t_mouse;

typedef struct s_door
{
	int		x;
	int		y;
	float	t;/* 0.0 closed -> 1.0 open */
}	t_door;

typedef struct s_vbuf
{
	int		idx[256];
	int		x0[256];
	int		x1[256];
	int		y0[256];
	int		y1[256];
	float	perp[256];
}	t_vbuf;

typedef struct s_proj
{
	int	sx0;
	int	sx1;
	int	sy0;
	int	sy1;
}	t_proj;

typedef struct s_col
{
	int	x0;
	int	y0;
	int	y1;
	int	w;
	int	h;
}	t_col;

typedef struct s_colbounds
{
	int	start;
	int	end;
	int	line_height;
}	t_colbounds;

typedef struct s_drawctx
{
	int		start;
	int		end;
	int		line_height;
	int		side;
	float	dirx;
	float	diry;
	float	hitx;
	float	hity;
	int		is_door;
}	t_drawctx;

typedef struct s_texloop
{
	int		start;
	int		end;
	int		side;
	int		texx;
	int		line_height;
}	t_texloop;

typedef struct s_bounds
{
	int	minx;
	int	maxx;
	int	miny;
	int	maxy;
}	t_bounds;

typedef struct s_move
{
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	float	nx;
	float	ny;
}	t_move;

typedef struct s_ray
{
	float	dirx;
	float	diry;
	int		mapx;
	int		mapy;
	float	sdx;
	float	sdy;
	float	ddx;
	float	ddy;
	int		stepx;
	int		stepy;
	int		side;
	float	perp;
	float	hitx;
	float	hity;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_enemy
{
	float	x;
	float	y;
}	t_enemy;

typedef struct s_anim
{
	t_img	frames[ENEMY_FRAMES];
	int		cur;
	int		ticks;
}	t_anim;

typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	bool	esc;
}	t_keys;

typedef struct s_textures
{
	t_string	north_path;
	t_string	south_path;
	t_string	east_path;
	t_string	west_path;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
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
	t_vec		grid;
	int			width;
	int			height;
	t_player	player;
	t_colors	colors;
	t_textures	textures;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		frame;
	t_map		map;
	int			tex_width;
	int			tex_height;
	t_keys		keys;
	float		move_speed;
	float		rot_speed;
	float		zbuf[WINDOW_WIDTH]; /* z-buffer per column */
	t_enemy		*enemies;
	int			enemy_count;
	t_anim		enemy_anim;
	int			frame_tick;
	t_door		*doors;
	int			door_count;
	t_img		door_tex;
	t_mouse		mouse;
}	t_game;

bool	is_valid_line(char *line);
bool	parse_elements(char *line, t_map *map, t_game *game);
bool	validate_textures(t_map *map);
void	free_map(t_map *map);
void	free_mlx(t_game *game);
int		apply_color(t_map *map, char *key, char *value);

int		start_window(t_game *game);
int		on_key_press(int keycode, t_game *game);
int		on_key_release(int keycode, t_game *game);
int		on_close(t_game *game);
int		render_frame(t_game *game);
void	update_player(t_game *game);
int		load_texture(t_game *g, t_img *dst, const char *path);
t_img	*pick_wall_texture(t_game *g, int side, float dirx, float diry);
void	draw_column_textured(t_game *g, int x, const t_drawctx *ctx);
void	put_pixel(t_img *img, int x, int y, int color);
int		blocked_at(t_map *m, float x, float y, float r);
double	compute_ray_angle(t_game *g, int x);
void	compute_bounds(float perp, t_colbounds *b);

/* map_parse.c */
bool	parse_map_file(char *filename, t_map *map, t_game *game);

/* map_grid.c */
int		push_map_line(t_map *map, char *cstr_line);
int		read_map_lines_loop(int fd, t_map *map);
void	clear_grid_strings(t_map *map);
bool	parse_map_grid(int fd, t_map *map, char *first_line);

/* map_surround.c */
int		is_map_line(char *line);
bool	is_map_surrounded(t_map *map);

/* map_player.c */
bool	find_player(t_map *map);

/* map_check.c */
bool	all_elements_present(t_map *map);

/* raycast_utils.c */
int		cell_blocks(t_map *m, int mx, int my);
void	advance_dda_step(t_ray *r);
void	finalize_hit(t_game *g, t_ray *r);
void	cast_one_column(t_game *g, int x);

int		find_enemies(t_game *g);
int		load_enemy_textures(t_game *g);
void	render_enemies(t_game *g);
int		img_px(const t_img *t, int x, int y);
void	put_pixel(t_img *img, int x, int y, int color);

void	minimap_render(t_game *g);
void	mm_pix(t_game *g, int x, int y, int c);
void	mm_square(t_game *g, int ox, int oy, int c);
char	mm_cell(t_game *g, int tx, int ty);

void	enemy_anim_tick(t_game *g);
void	sort_by_dist(int *idx, float *dist, int n);
void	project_calc(t_proj *p, double a, double fov, float perp);
void	pe_norm_angle(double *a);
int		dsc_calc_tx(int x, t_col *col, t_img *tex);

void	fill_len(t_string *row, size_t *len);
void	set_enemy(t_enemy *e, size_t x, size_t y);
void	fill_row_enemies(t_string *row, size_t y, t_enemy *list, int *i);

/* doors */
int		find_doors(t_game *g);
void	update_doors(t_game *g);
int		load_door_texture(t_game *g);
int		is_door_closed_cell(t_game *g, int mx, int my);

void	mouse_init(t_game *g);
int		mouse_move_hook(int x, int y, t_game *g);

#endif
