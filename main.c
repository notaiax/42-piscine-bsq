/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:00:35 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/31 01:43:28 by migriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <all.h>

void	bsq(char *map);
t_obstacle *preppend_obstacle(int x, int y, t_obstacle *next);

int		main(int argc, char **argv)
{
	char		*str;
	int			i;

	if (argc < 2)
	{
		str = bsq_read_file("-");
		ft_putstr(str);
	}
	i = 0;
	while (++i < argc)
	{
		if (i != 1)
			ft_putstr("\n");
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			str = bsq_read_file("-");
		else
			str = bsq_read_file(argv[i]);
		bsq(str);
	}
	return (0);
}

void	bsq(char *map)
{
	t_map_info	mi;
	t_obstacle	*obs;
	t_box *biggest;

	mi = new_map_info(9, '.', 'o', 'x');
	mi.columns = 28;

	obs = new_obstacle(11, 8);
	obs = preppend_obstacle(2, 8, obs);
	obs = preppend_obstacle(21, 7, obs);
	obs = preppend_obstacle(6, 7, obs);
	obs = preppend_obstacle(15, 5, obs);
	obs = preppend_obstacle(4, 4, obs);
	obs = preppend_obstacle(12, 2, obs);
	obs = preppend_obstacle(4, 1, obs);

	biggest = bsq_find(map, mi, &obs);
	printf("X: %d; Y: %d; Size: %d\n", biggest->x, biggest->y, biggest->size);
	return ;
}

t_obstacle *preppend_obstacle(int x, int y, t_obstacle *next)
{
	t_obstacle	*ns;

	ns = new_obstacle(x, y);
	ns->next = next;
	return (ns);
}
