NAME			= cub3d
LIBFT 			= ./libft/libft.a
MLX				= ./mlx/libmlx_Linux.a
CC 				= cc

CC_FLAGS 		= -Wall -Werror -Wextra -I./include -I./libft/include -I./mlx #-g3 -fsanitize=address
MINILIBX_FLAGS	= -L./mlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

REMOVE 			= rm -rf

SRCDIR			= src
OBJDIR			= obj

SRCS			= $(SRCDIR)/game.c $(SRCDIR)/map.c $(SRCDIR)/map_parse.c
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
