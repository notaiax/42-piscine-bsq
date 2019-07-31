/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:00:35 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/31 00:08:30 by afaura-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <all.h>

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
		ft_putstr(str);
	}
	return (0);
}
