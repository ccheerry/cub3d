/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acerezo- <acerezo-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:13:41 by acerezo-          #+#    #+#             */
/*   Updated: 2025/09/02 19:54:31 by acerezo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc.h"

static t_arena	*ft_init_arena(size_t size)
{
	size_t	total_size;
	t_arena	*arena;

	arena = ft_alloc(sizeof(t_arena));
	if (!arena)
		return (NULL);
	total_size = __max_s(size * 2, DEFAULT_ARENA_SIZE);
	arena->pool = ft_alloc(total_size);
	if (!arena->pool)
		return (NULL);
	arena->size = total_size;
	arena->offset = 0;
	arena->next = NULL;
	return (arena);
}

static void	*ft_manage_req(t_arena *arena, size_t size)
{
	void	*base;
	void	*aligned;
	size_t	padding;

	base = (t_u8 *)arena->pool + arena->offset + sizeof(void *);
	aligned = (void *)(((t_uptr)base + (DEF_ALIGN - 1)) & ~(DEF_ALIGN - 1));
	padding = (t_u8 *)aligned - (t_u8 *)base;
	if (arena->offset + padding + size > arena->size)
	{
		if (!arena->next)
			arena->next = ft_init_arena(size);
		if (!arena->next)
			return (NULL);
		return (ft_manage_req(arena->next, size));
	}
	arena->offset += padding + size;
	return (aligned);
}

void	*ft_arena(size_t size)
{
	static t_arena	*arena;
	static t_arena	*current;

	if (!size)
		return (NULL);
	if (!arena)
	{
		arena = ft_init_arena(size);
		ft_free_arena(arena);
		current = arena;
	}
	if (!arena)
		return (NULL);
	while (current->next)
		current = current->next;
	return (ft_manage_req(current, size));
}

void	ft_free_arena(t_arena *arena)
{
	static t_arena	*store;
	t_arena			*current_arena;
	t_arena			*next_arena;
	void			*t;

	if (arena)
	{
		store = arena;
		atexit((void (*)(void))ft_free_arena);
		return ;
	}
	if (!store)
		return ;
	current_arena = store;
	while (current_arena)
	{
		next_arena = current_arena->next;
		t = current_arena->pool;
		if (current_arena->pool)
			ft_free(&t);
		t = current_arena;
		ft_free(&t);
		current_arena = next_arena;
	}
	store = NULL;
}
