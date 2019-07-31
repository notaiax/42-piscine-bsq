/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:01:43 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/30 19:03:06 by afaura-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 4096

char	*read_file(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*buf;

	fd = 0;
	buf = (char*)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "open() error\n", 13);
			return ("");
		}
	}
	ret = read(fd, buf, BUF_SIZE);
	if (ret == -1)
	{
		write(2, "read() error\n", 13);
		return ("");
	}
	buf[ret] = '\0';
	close(fd);
	return (buf);
}
