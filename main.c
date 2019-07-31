/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:00:35 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/30 21:53:00 by afaura-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	char		*str;
	int			i;

	if (argc < 2)
	{
		str = ft_read_file("-");
		ft_putstr(str);
	}
	i = 0;
	while (++i < argc)
	{
		if (i != 1)
			ft_putstr("\n");
		if (argv[i][0] == '-' && argv[i][1] == 0)
			str = ft_read_file("-");
		else
			str = ft_read_file(argv[i]);
		ft_putstr(str);
	}
	return (0);
}
