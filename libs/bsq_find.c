/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migriver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:20:39 by migriver          #+#    #+#             */
/*   Updated: 2019/07/31 01:40:59 by migriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <all.h>

void	bsq_expand_box(t_box *cb, t_map_info mi, t_obstacle **obs)
{
	while (cb.x + cb.size < mi.columns && cb.y + cb.size < mi.lines)
	{
		if (bsq_has_obstacle(&cb, obs))
		{
			cb.size--;
			break ;
		}
		cb.size++;
	}
	return ;
}

t_box	*bsq_find(char *map, t_map_info *mi, t_obstacle **obs)
{
	t_box	biggest;
	t_box	cb;
	int			i;

	biggest = new_box(mi.columns, mi.lines, 1);
	cb = new_box(0, 0, 1);
	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
			continue;
		bsq_expand_box(&cb, &mi, obs);
		if (cb.size > biggest.size ||
				(cb.size == biggest.size && cb.x < biggest.x && cb.y < biggest.y)
			biggest = cb;
	}
	return (biggest);
}

int		bsq_has_obstacle(t_box *cb, t_obstacle **obs)
{
	while (*obs != (void *)0)
	{
		if ((*obs)->x >= cb->x && (*obs)->x <= cb->x + c->size - 1 &&
				(*obs)->y >= cb->y && (*obs)->y <= cb->y + c->size - 1)
			return (1);
		*obs = *obs->next;
	}
	return (0);
}
