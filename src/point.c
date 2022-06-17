/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:08:24 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/17 15:14:49 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	get_uppoint(int height, int width)
{
	if (height > width)
		return (0.8 * (double)height / 10);
	else
		return (0.8 * (double)width / 10);
}

t_pos	getpos_pixelmap(int x, int y, t_map *pm)
{
	t_pos	res;
	int		mi;
	int		l;

	mi = get_highest_num(pm);
	l = get_lowest_num(pm);
	res.y = (pm->height + y - x) * cos(30 * 3.14159265 / 180) * get_sr(0, NULL);
	res.x = (y + x) * get_sr(0, NULL) * cos(60 * 3.14159265 / 180);
	if (pm->map[x][y] > 0)
		res.x -= get_sr(0, NULL) * cos(60 * 3.14159265 / 180)
			* (get_uppoint(pm->height, pm->width)
				* (double)pm->map[x][y] / (double)mi);
	else if (pm->map[x][y] < 0)
		res.x += get_sr(0, NULL) * cos(60 * 3.14159265 / 180)
			* (get_uppoint(pm->height, pm->width)
				* (double)pm->map[x][y] / (double)l);
	res.x += (int)((get_sr(0, NULL) * cos(60 * 3.14159265 / 180))
			* get_uppoint(pm->height, pm->width));
	return (res);
}

void	init_point(t_map *res, t_map *pm)
{
	size_t	x;
	size_t	y;
	t_pos	pos;

	x = -1;
	while ((int)++x < pm->height)
	{
		y = -1;
		while ((int)++y < pm->width)
		{
			pos = getpos_pixelmap(x, y, pm);
			res->map[pos.x][pos.y] = pm->color[x][y];
		}
	}
}
