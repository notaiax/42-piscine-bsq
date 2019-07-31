/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migriver <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:49:21 by migriver          #+#    #+#             */
/*   Updated: 2019/07/31 00:55:04 by migriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <all.h>

t_box		bsq_itoxy(int i, int columns)
{
	t_box nb;

	nb = new_box(0, 0, 1);
	nb.x = i % columns;
	nb.y = i / columns;
	return (nb);
}

t_box		new_box(int x, int y, int size)
{
	t_box nb;

	nb.x = x;
	nb.y = y;
	nb.size = size;
	return (nb);
}

t_map_info	new_map_info(int lines, char empty, char obstacle, char full)
{
	t_map_info	nmi;

	nmi.lines = lines;
	nmi.columns = 0;
	nmi.empty = empty;
	nmi.obstacle = obstacle;
	nmi.full = full;
	return (nmi);
}

t_obstacle	*new_obstacle(int x, int y)
{
	t_obstacle	*no;

	no = (t_obstacle *)malloc(sizeof(t_obstacle));
	no->x = x;
	no->y = y;
	no->next = (void *)0;
	return (no);
}

int		bsq_xytoi(t_box box)
{
	return (box.x + box.y * box.x);
}