/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:07:49 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/31 00:01:35 by afaura-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_map_info
{
	int		lines;
	int		columns;
	char	empty;
	char	obstacle;
	char	full;
}				t_map_info;

typedef struct	s_obstacle
{
	int					x;
	int					y;
	struct s_obstacle	*next;
}				t_obstacle;

typedef struct	s_box
{
	int x;
	int y;
	int size;
}				t_box;

char			*bsq_read_file(char *filename);
char			*bsq_read_file_error(char *value, char *filename, char *str);

#endif
