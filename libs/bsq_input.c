/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:29:28 by afaura-v          #+#    #+#             */
/*   Updated: 2019/08/01 00:37:09 by migriver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <all.h>
#define BUF_SIZE 4096

ssize_t		bsq_get_file_size(char *filename)
{
	int		fd;
	int		sifd;
	ssize_t	ret;
	ssize_t	fsize;
	char	*buf;

	fd = 0;
	sifd = 0;
	if (filename[0] == '-' && filename[1] == '\0')
		sifd = open("-", O_CREAT | O_TRUNC | O_RDWR);
	else
		fd = open(filename, O_RDONLY);
	fsize = 0;
	buf = (char *)malloc(sizeof(char) * (BUF_SIZE));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (filename[0] == '-' && filename[1] == '\0')
			write(sifd, buf, ret);
		fsize += ret;
	}
	close(fd);
	close(sifd);
	free(buf);
	return (fsize);
}

char		*bsq_read_file(char *filename)
{
	int		fd;
	ssize_t	ret;
	ssize_t	fsize;
	char	*buf;

	fsize = bsq_get_file_size(filename) + 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (bsq_read_file_error("", filename, "open() error\n"));
	buf = (char*)malloc(sizeof(*buf) * fsize);
	ret = read(fd, buf, fsize);
	if (ret == -1)
		return (bsq_read_file_error("", filename, "read() error\n"));
	buf[ret] = '\0';
	close(fd);
	return (buf);
}

char		*bsq_read_file_error(char *value, char *filename, char *str)
{
	ft_puterror(1, filename);
	ft_puterror(1, ": ");
	ft_puterror(1, str);
	return (value);
}
