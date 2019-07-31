/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:01:43 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/30 21:40:51 by afaura-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 4096

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_read_file(char *filename)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = (char*)malloc(sizeof(*buf) * (BUF_SIZE + 1));
	if (ft_strcmp(filename, "-") == 0)
		fd = 0;
	else
	{
		fd = open(filename, O_RDONLY);
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
