NAME			= cub3d
LIBFT 			= ./libft/libft.a
MLX				= ./mlx/libmlx_Linux.a
CC 				= cc

CC_FLAGS 		= -Wall -Werror -Wextra -I./include -I./libft/include -I./mlx #-g3 -fsanitize=address
MINILIBX_FLAGS	= -L./mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lz -lm -lXfixes

REMOVE 			= rm -rf

SRCDIR			= src
OBJDIR			= obj

SRCS_CORE		= $(SRCDIR)/core/game.c $(SRCDIR)/core/mem.c $(SRCDIR)/core/window.c

SRCS_MAP		= $(SRCDIR)/map/map_parse.c $(SRCDIR)/map/map_grid.c \
				$(SRCDIR)/map/map_surround.c $(SRCDIR)/map/map_player.c \
				$(SRCDIR)/map/map_check.c $(SRCDIR)/map/map_free.c \
				$(SRCDIR)/map/map_validate.c $(SRCDIR)/map/map_elements.c \
				$(SRCDIR)/map/map_colors.c

SRCS_RENDER		= $(SRCDIR)/render/raycast.c $(SRCDIR)/render/raycast_utils.c \
				$(SRCDIR)/render/render.c $(SRCDIR)/render/render_tex.c \
				$(SRCDIR)/render/texture.c $(SRCDIR)/render/img_utils.c

SRCS_INPUT		= $(SRCDIR)/input/input.c $(SRCDIR)/input/input_keys.c \
				$(SRCDIR)/input/update_player.c

SRCS_BONUS		= $(SRCDIR)/bonus/enemies_parse.c $(SRCDIR)/bonus/enemies_utils.c \
				$(SRCDIR)/bonus/enemy_textures.c $(SRCDIR)/bonus/sprites_enemy.c \
				$(SRCDIR)/bonus/sprites_utils.c $(SRCDIR)/bonus/minimap.c \
				$(SRCDIR)/bonus/minimap_utils.c $(SRCDIR)/bonus/doors_parse.c \
				$(SRCDIR)/bonus/doors_update.c $(SRCDIR)/bonus/doors_texture.c \
				$(SRCDIR)/bonus/mouse_cam.c

SRCS			= $(SRCS_CORE) $(SRCS_MAP) $(SRCS_RENDER) $(SRCS_INPUT) $(SRCS_BONUS)

OBJS			= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all:			${LIBFT} ${MLX} ${NAME}

${NAME}: $(OBJS)
				${CC} $(OBJS) ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
				@mkdir -p $(dir $@)
				${CC} ${CC_FLAGS} -c $< -o $@

$(OBJDIR):
				mkdir -p $(OBJDIR)

${LIBFT}:
				make -C libft

${MLX}:
				-make -C mlx

clean:
				${REMOVE} $(OBJDIR)
				make clean -C libft
				-make clean -C mlx

fclean:			clean
				${REMOVE} ${NAME}
				make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
