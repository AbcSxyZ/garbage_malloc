/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   garbage_alloc.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 19:46:00 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 22:23:01 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "garbage.h"

t_garblst		*g_garbage = NULL;

/*
** garbage_destructor:
**
** Destructor function to free the entire chained list of allocated memory
** whenver the programm is over.
*/

void		garbage_destructor(void)
{
	free_g_garbage_lst();
}

/*
** free_g_garbage_lst:
**
** Iterate over each g_garbage node to free the entire list.
** Set the g_garbage variable to NULL.
*/

void		free_g_garbage_lst(void)
{
	t_garblst	*next_garb;

	while (g_garbage)
	{
		next_garb = g_garbage->next;
		free(g_garbage);
		g_garbage = next_garb;
	}
	g_garbage = NULL;
}

/*
** garbage_free:
**
** Free a given pointer. Remove the allocated
** pointer of the g_garbage list.
*/

void		garbage_free(void *ptr)
{
	t_garblst	*prev_garb;
	t_garblst	*curr_garb;

	prev_garb = NULL;
	curr_garb = g_garbage;
	while (curr_garb && curr_garb->allocated != ptr)
	{
		prev_garb = curr_garb;
		curr_garb = curr_garb->next;
	}
	if (!curr_garb)
		return ;
	if (prev_garb)
		prev_garb->next = curr_garb->next;
	else
		g_garbage = g_garbage->next;
	free(curr_garb);
}

/*
** garbage_malloc:
**
** Allocated a single pointer of the given size.
** Store the new allocated pointer in the g_garbage list.
*/

void		*garbage_malloc(int size)
{
	t_garblst	*garb_item;

	if (!(garb_item = (t_garblst *)malloc(sizeof(t_garblst) + size)))
		return (NULL);
	garb_item->allocated = garb_item + 1;
	garb_item->next = g_garbage;
	g_garbage = garb_item;
	return (garb_item + 1);
}
