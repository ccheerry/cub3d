NAME			= cub3d
LIBFT 			= ./libft/libft.a
MLX				= ./mlx/libmlx_Linux.a
CC 				= cc

CC_FLAGS 		= -Wall -Werror -Wextra -I./include -I./libft/include -I./mlx #-g3 -fsanitize=address
MINILIBX_FLAGS	= -L./mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lz -lm

REMOVE 			= rm -rf

SRCDIR			= src
OBJDIR			= obj

SRCS 			= $(SRCDIR)/game.c $(SRCDIR)/map_parse.c \
					$(SRCDIR)/mem.c $(SRCDIR)/input.c $(SRCDIR)/raycast.c \
					$(SRCDIR)/render.c $(SRCDIR)/window.c \
					$(SRCDIR)/texture.c $(SRCDIR)/render_tex.c $(SRCDIR)/update_player.c \
					$(SRCDIR)/input_keys.c $(SRCDIR)/map_grid.c \
					$(SRCDIR)/map_surround.c $(SRCDIR)/map_player.c $(SRCDIR)/map_check.c \
					$(SRCDIR)/map_free.c $(SRCDIR)/map_validate.c $(SRCDIR)/map_elements.c \
					$(SRCDIR)/map_colors.c $(SRCDIR)/raycast_utils.c \
					$(SRCDIR)/enemies_parse.c $(SRCDIR)/enemies_utils.c \
					$(SRCDIR)/enemy_textures.c \
					$(SRCDIR)/img_utils.c \
					$(SRCDIR)/sprites_enemy.c $(SRCDIR)/sprites_utils.c \
					$(SRCDIR)/minimap.c $(SRCDIR)/minimap_utils.c \
					$(SRCDIR)/doors_parse.c \
					$(SRCDIR)/doors_update.c \
					$(SRCDIR)/doors_texture.c \
					$(SRCDIR)/mouse_cam.c \



OBJS			= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all:			${LIBFT} ${MLX} ${NAME}

${NAME}: $(OBJS)
				${CC} $(OBJS) ${LIBFT} ${CC_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
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
