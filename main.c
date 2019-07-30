/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: am <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:23:35 by am                #+#    #+#             */
/*   Updated: 2019/07/29 20:33:55 by afaura-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 4096

char	*read_file(int argc, char **argv)
{
	int 	fd;
	char	*buf;
	int 	ret;

	fd = 0;
	buf = (char*)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (argc == 2)
		fd = open(argv[1], O_RDONLY)
		if (fd == -1)
		{
			write(2, "open() error", 12);
			return (1);
		}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		write(2, "read() error", 12);
		return (1);
	}
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		write(2, "close() error", 13);
		return (1);
	}
	return (buf);
}

int		main(int argc, char argv**)
{
	char	*str;
	
	str = read_file(argc, argv);
	putstr(str);

	return (0);
}
