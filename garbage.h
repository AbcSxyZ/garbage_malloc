/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   garbage.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 19:44:25 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 10:44:01 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdlib.h>

/*
** Macro to use for allocation and free.
*/

# define MALLOC		garbage_malloc
# define FREE		garbage_free

/*
** Structure of the chained list to store each allocated element.
*/

typedef struct s_garblst	t_garblst;

struct		s_garblst
{
	void		*allocated;
	t_garblst	*next;
};

extern t_garblst	*g_garbage;

void		garbage_free(void *ptr);
void		*garbage_malloc(size_t size);
void		free_g_garbage_lst(void) __attribute__((destructor));

#endif
