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

#include <stdio.h>
#include <stdlib.h>
#include <all.h>

int		has_obstacle(t_square *cs, t_obstacle **obs)
{
	while (*obs != (void *)0)
	{
		if ((*obs)->x >= cs->x && (*obs)->x <= cs->x + c->size - 1 &&
				(*obs)->y >= cs->y && (*obs)->y <= cs->y + c->size - 1)
			return (1);
		*obs = *obs->next;
	}
	return (0);
}

t_square	*bsq_find(char *map, t_map_info mi, t_obstacle **obs)
{
	t_square	*biggest;
	t_square	*cs;
	int			i;

	biggest = new_square(0, 0, 0);
	cs = new_square(0, 0, 1);
	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
			continue;
		if (has_obstacle(cs, obs))
			;
	}
	return (biggest);
}
