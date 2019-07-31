/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:07:49 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/31 01:05:33 by migriver         ###   ########.fr       */
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

t_box			bsq_itoxy(int i, int columns);
char			*bsq_read_file(char *filename);
char			*bsq_read_file_error(char *value, char *filename, char *str);
t_map_info		new_map_info(int lines, char empty, char obstacle, char full);
t_obstacle		*new_obstacle(int x, int y);
t_box			new_box(int x, int y, int size);
int			bsq_xytoi(t_box box);

#endif
