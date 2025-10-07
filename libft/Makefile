NAME		:=	libft.a
CC			:=	cc
FLAGS		:=	-Wall -Wextra -Werror
AR			:=	ar rcs
OBJDIR		:=	build

# String
SRCS_CSTR	:=	src/cstr/ft_split.c\
				src/cstr/ft_strcmp.c\
				src/cstr/ft_strlen.c

# I/O
SRCS_IO		:=	src/io/ft_putstr_fd.c\
				src/io/get_next_line.c\
				src/io/ft_fgetc.c

# Memory allocation
SRCS_ALLOC	:=	src/alloc/ft_alloc.c\
				src/alloc/ft_calloc.c\
				src/alloc/ft_extend_zero.c\
				src/alloc/ft_free.c

# Memory manipulation
SRCS_MEM	:=	src/mem/ft_memclone.c\
				src/mem/ft_memcpy.c\
				src/mem/ft_memmove.c\
				src/mem/ft_memset.c

# Conversion
SRCS_CONV	:=	src/conv/ft_atoi.c

# String type (tstr)
SRCS_TSTR	:=	src/tstr/ft_tstr_free.c\
				src/tstr/ft_tstr_from_cstr.c\
				src/tstr/ft_tstr_clone.c\
				src/tstr/ft_tstr_clear.c\
				src/tstr/ft_tstr_push.c\
				src/tstr/ft_tstr_new.c

# Vector
SRCS_VEC	:=	src/vec/ft_vec.c\
				src/vec/ft_vec_free.c\
				src/vec/ft_vec_get.c\
				src/vec/ft_vec_push.c

SRCS		:=	$(SRCS_CSTR) $(SRCS_IO) $(SRCS_ALLOC) $(SRCS_MEM) $(SRCS_CONV) $(SRCS_TSTR) $(SRCS_VEC)

OBJS		:=	$(SRCS:src/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@ -Iinclude

$(NAME): $(OBJS)
	@$(AR) $@ $^

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
