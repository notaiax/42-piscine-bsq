/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaura-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:07:49 by afaura-v          #+#    #+#             */
/*   Updated: 2019/07/29 23:05:13 by migriver         ###   ########.fr       */
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

void				ft_putstr(char *str);

#endif
