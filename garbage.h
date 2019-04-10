/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   garbage.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 19:44:25 by simrossi     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 22:22:22 by simrossi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdlib.h>

typedef struct s_garblst	t_garblst;

struct		s_garblst
{
	void		*allocated;
	t_garblst	*next;
};

extern t_garblst	*g_garbage;

void		garbage_free(void *ptr);
void		*garbage_malloc(int size);
void		garbage_destructor(void) __attribute__((destructor));
void		free_g_garbage_lst(void);

#endif
