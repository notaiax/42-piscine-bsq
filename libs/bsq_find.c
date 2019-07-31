/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migriver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:20:39 by migriver          #+#    #+#             */
/*   Updated: 2019/07/31 16:41:30 by migriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <all.h>

void	bsq_expand_box(t_box *cb, t_map_info *mi)
{
	while (cb->x + cb->size < mi->columns && cb->y + cb->size < mi->lines)
	{
		if (bsq_has_obstacle(cb, mi))
		{
			cb->size--;
			break ;
		}
		cb->size++;
	}
	return ;
}

t_box	bsq_find(char *map, t_map_info *mi)
{
	t_box	biggest;
	t_box	cb;
	int		i;

	biggest = bsq_new_box(mi->columns, mi->lines, 1);
	cb = bsq_new_box(0, 0, 1);
	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
			continue;
		bsq_expand_box(&cb, mi);
		printf("X: %d; Y: %d; Size: %d\n", cb.x, cb.y, cb.size);
		if (cb.size > biggest.size ||
				(cb.size == biggest.size &&
				cb.x < biggest.x && cb.y < biggest.y))
			biggest = cb;
	}
	return (biggest);
}

int		bsq_has_obstacle(t_box *cb, t_map_info *mi)
{
	t_obstacle *obs;

	obs = mi->obstacles;
	while (obs != (void *)0)
	{
		if (obs->x >= cb->x && obs->x <= cb->x + cb->size - 1 &&
				obs->y >= cb->y && obs->y <= cb->y + cb->size - 1)
			return (1);
		obs = obs->next;
	}
	return (0);
}