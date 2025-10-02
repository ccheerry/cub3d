NAME		:=	libft.a
CC			:=	cc
FLAGS		:=	-Wall -Wextra -Werror -Wpedantic
AR			:=	ar rcs
OBJDIR		:=	build
SRCS		:=	src/ctype/ft_isprint.c\
				src/ctype/ft_isxdigit.c\
				src/ctype/ft_isdigit.c\
				src/ctype/ft_isspace.c\
				src/ctype/ft_isalnum.c\
				src/ctype/ft_isascii.c\
				src/ctype/ft_isalpha.c\
				src/lst/ft_lstadd_back.c\
				src/lst/ft_lstnew.c\
				src/lst/ft_lstlast.c\
				src/lst/ft_lstiter.c\
				src/lst/ft_lstadd_front.c\
				src/lst/ft_lstclear.c\
				src/lst/ft_lstmap.c\
				src/lst/ft_lstdelone.c\
				src/lst/ft_lstsize.c\
				src/cstr/ft_s_isblob.c\
				src/cstr/ft_substr.c\
				src/cstr/ft_toupper.c\
				src/cstr/ft_strncmp.c\
				src/cstr/ft_strrchr.c\
				src/cstr/ft_strtrim.c\
				src/cstr/ft_strchr.c\
				src/cstr/ft_striteri.c\
				src/cstr/ft_split.c\
				src/cstr/ft_strlen.c\
				src/cstr/ft_strlcat.c\
				src/cstr/ft_strcmp.c\
				src/cstr/ft_strdup.c\
				src/cstr/ft_strmapi.c\
				src/cstr/ft_strnstr.c\
				src/cstr/ft_strlcpy.c\
				src/cstr/ft_isnumeric.c\
				src/cstr/ft_tolower.c\
				src/cstr/ft_strjoin.c\
				src/io/ft_printptr_fd.c\
				src/io/ft_putstr_fd.c\
				src/io/get_next_line.c\
				src/io/ft_printhex_fd.c\
				src/io/ft_fprintf.c\
				src/io/ft_putendl_fd.c\
				src/io/ft_putchar_fd.c\
				src/io/ft_printchar.c\
				src/io/ft_printunbr_fd.c\
				src/io/ft_putnbr_fd.c\
				src/io/ft_readline.c\
				src/io/ft_printstr.c\
				src/io/ft_printf.c\
				src/io/ft_fgetc.c\
				src/io/ft_printnbr_fd.c\
				src/alloc/ft_realloc.c\
				src/alloc/ft_alloc.c\
				src/alloc/ft_defer.c\
				src/alloc/ft_recalloc.c\
				src/alloc/ft_calloc.c\
				src/alloc/ft_free.c\
				src/alloc/ft_extend_zero.c\
				src/alloc/ft_arena.c\
				src/alloc/ft_extend.c\
				src/math/ft_pow_signed.c\
				src/math/ft_fabs.c\
				src/math/ft_pow.c\
				src/math/ft_q_sqrt.c\
				src/math/ft_round.c\
				src/tstr/ft_tstr_repeat.c\
				src/tstr/ft_tstr_strrchr.c\
				src/tstr/ft_tstr_new.c\
				src/tstr/ft_tstr_dup_cstr.c\
				src/tstr/ft_tstr_from_cstr.c\
				src/tstr/ft_tstr_insert.c\
				src/tstr/ft_tstr_trim.c\
				src/tstr/ft_tstr_borrow.c\
				src/tstr/ft_tstr_reserve.c\
				src/tstr/ft_tstr_free.c\
				src/tstr/ft_tstr_pushstr.c\
				src/tstr/ft_tstr_from_slice.c\
				src/tstr/ft_tstr_pop.c\
				src/tstr/ft_tstr_push.c\
				src/tstr/ft_tstr_instr.c\
				src/tstr/ft_tstr_clear.c\
				src/tstr/ft_tstr_fit.c\
				src/tstr/ft_tstr_clone.c\
				src/conv/ft_itoa_base.c\
				src/conv/ft_utoa_base.c\
				src/conv/ft_atod.c\
				src/conv/ft_atol.c\
				src/conv/ft_atof.c\
				src/conv/ft_atoi.c\
				src/conv/ft_atoul.c\
				src/conv/ft_itoa.c\
				src/conv/ft_atoi_base.c\
				src/mem/ft_memcpy.c\
				src/mem/ft_hash.c\
				src/mem/ft_memmove.c\
				src/mem/ft_memswap.c\
				src/mem/ft_memformat.c\
				src/mem/ft_memchr.c\
				src/mem/mem_helpers/__maxs.c\
				src/mem/mem_helpers/ft_memlk_r.c\
				src/mem/mem_helpers/ft_memw_bw.c\
				src/mem/mem_helpers/ft_bitcmp.c\
				src/mem/mem_helpers/ft_memw_fw.c\
				src/mem/mem_helpers/ft_memst_w.c\
				src/mem/mem_helpers/__hasz.c\
				src/mem/mem_helpers/__populate.c\
				src/mem/mem_helpers/__max.c\
				src/mem/mem_helpers/ft_memcm_r.c\
				src/mem/ft_memtake.c\
				src/mem/ft_memclone.c\
				src/mem/ft_membroadcast.c\
				src/mem/ft_memset.c\
				src/mem/ft_memcmp.c\
				src/mem/ft_bzero.c\
				src/mem/ft_memctz.c\
				src/vec/ft_vec_insert.c\
				src/vec/ft_vec.c\
				src/vec/ft_vec_reserve.c\
				src/vec/ft_vec_popmv.c\
				src/vec/ft_vec_get.c\
				src/vec/ft_vec_fit.c\
				src/vec/ft_vec_rev.c\
				src/vec/ft_vec_pop.c\
				src/vec/ft_vec_peek_last.c\
				src/vec/ft_vec_remove.c\
				src/vec/ft_vec_push.c\
				src/vec/ft_vec_free.c\
				src/vec/ft_vec_clear.c

OBJS		:=	build/ctype/ft_isprint.o\
				build/ctype/ft_isxdigit.o\
				build/ctype/ft_isdigit.o\
				build/ctype/ft_isspace.o\
				build/ctype/ft_isalnum.o\
				build/ctype/ft_isascii.o\
				build/ctype/ft_isalpha.o\
				build/lst/ft_lstadd_back.o\
				build/lst/ft_lstnew.o\
				build/lst/ft_lstlast.o\
				build/lst/ft_lstiter.o\
				build/lst/ft_lstadd_front.o\
				build/lst/ft_lstclear.o\
				build/lst/ft_lstmap.o\
				build/lst/ft_lstdelone.o\
				build/lst/ft_lstsize.o\
				build/cstr/ft_s_isblob.o\
				build/cstr/ft_substr.o\
				build/cstr/ft_toupper.o\
				build/cstr/ft_strncmp.o\
				build/cstr/ft_strrchr.o\
				build/cstr/ft_strtrim.o\
				build/cstr/ft_strchr.o\
				build/cstr/ft_striteri.o\
				build/cstr/ft_split.o\
				build/cstr/ft_strlen.o\
				build/cstr/ft_strlcat.o\
				build/cstr/ft_strcmp.o\
				build/cstr/ft_strdup.o\
				build/cstr/ft_strmapi.o\
				build/cstr/ft_strnstr.o\
				build/cstr/ft_strlcpy.o\
				build/cstr/ft_isnumeric.o\
				build/cstr/ft_tolower.o\
				build/cstr/ft_strjoin.o\
				build/io/ft_printptr_fd.o\
				build/io/ft_putstr_fd.o\
				build/io/get_next_line.o\
				build/io/ft_printhex_fd.o\
				build/io/ft_fprintf.o\
				build/io/ft_putendl_fd.o\
				build/io/ft_putchar_fd.o\
				build/io/ft_printchar.o\
				build/io/ft_printunbr_fd.o\
				build/io/ft_putnbr_fd.o\
				build/io/ft_readline.o\
				build/io/ft_printstr.o\
				build/io/ft_printf.o\
				build/io/ft_fgetc.o\
				build/io/ft_printnbr_fd.o\
				build/alloc/ft_realloc.o\
				build/alloc/ft_alloc.o\
				build/alloc/ft_defer.o\
				build/alloc/ft_recalloc.o\
				build/alloc/ft_calloc.o\
				build/alloc/ft_free.o\
				build/alloc/ft_extend_zero.o\
				build/alloc/ft_arena.o\
				build/alloc/ft_extend.o\
				build/math/ft_pow_signed.o\
				build/math/ft_fabs.o\
				build/math/ft_pow.o\
				build/math/ft_q_sqrt.o\
				build/math/ft_round.o\
				build/tstr/ft_tstr_repeat.o\
				build/tstr/ft_tstr_strrchr.o\
				build/tstr/ft_tstr_new.o\
				build/tstr/ft_tstr_dup_cstr.o\
				build/tstr/ft_tstr_from_cstr.o\
				build/tstr/ft_tstr_insert.o\
				build/tstr/ft_tstr_trim.o\
				build/tstr/ft_tstr_borrow.o\
				build/tstr/ft_tstr_reserve.o\
				build/tstr/ft_tstr_free.o\
				build/tstr/ft_tstr_pushstr.o\
				build/tstr/ft_tstr_from_slice.o\
				build/tstr/ft_tstr_pop.o\
				build/tstr/ft_tstr_push.o\
				build/tstr/ft_tstr_instr.o\
				build/tstr/ft_tstr_clear.o\
				build/tstr/ft_tstr_fit.o\
				build/tstr/ft_tstr_clone.o\
				build/conv/ft_itoa_base.o\
				build/conv/ft_utoa_base.o\
				build/conv/ft_atod.o\
				build/conv/ft_atol.o\
				build/conv/ft_atof.o\
				build/conv/ft_atoi.o\
				build/conv/ft_atoul.o\
				build/conv/ft_itoa.o\
				build/conv/ft_atoi_base.o\
				build/mem/ft_memcpy.o\
				build/mem/ft_hash.o\
				build/mem/ft_memmove.o\
				build/mem/ft_memswap.o\
				build/mem/ft_memformat.o\
				build/mem/ft_memchr.o\
				build/mem/mem_helpers/__maxs.o\
				build/mem/mem_helpers/ft_memlk_r.o\
				build/mem/mem_helpers/ft_memw_bw.o\
				build/mem/mem_helpers/ft_bitcmp.o\
				build/mem/mem_helpers/ft_memw_fw.o\
				build/mem/mem_helpers/ft_memst_w.o\
				build/mem/mem_helpers/__hasz.o\
				build/mem/mem_helpers/__populate.o\
				build/mem/mem_helpers/__max.o\
				build/mem/mem_helpers/ft_memcm_r.o\
				build/mem/ft_memtake.o\
				build/mem/ft_memclone.o\
				build/mem/ft_membroadcast.o\
				build/mem/ft_memset.o\
				build/mem/ft_memcmp.o\
				build/mem/ft_bzero.o\
				build/mem/ft_memctz.o\
				build/vec/ft_vec_insert.o\
				build/vec/ft_vec.o\
				build/vec/ft_vec_reserve.o\
				build/vec/ft_vec_popmv.o\
				build/vec/ft_vec_get.o\
				build/vec/ft_vec_fit.o\
				build/vec/ft_vec_rev.o\
				build/vec/ft_vec_pop.o\
				build/vec/ft_vec_peek_last.o\
				build/vec/ft_vec_remove.o\
				build/vec/ft_vec_push.o\
				build/vec/ft_vec_free.o\
				build/vec/ft_vec_clear.o

all: $(NAME)

$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@ -Iinclude

$(NAME): $(OBJS)
	@$(AR) $@ $^

install: all
	@sudo cp $(NAME) /usr/local/lib
	@sudo mkdir -p /usr/local/include/llv/
	@sudo cp include/* /usr/local/include/llv/

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

test: install test-mem test-cstr

re: fclean full all

.PHONY: all clean fclean re bonus install full
MAKEFLAGS += --no-print-directory
