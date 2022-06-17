/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:46:36 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/09 17:43:56 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_color_ver(t_pos p1res, t_pos p2res, int x, t_map *res)
{
	double	c1;
	double	c2;
	double	p1pos;
	double	p2pos;
	int		color;

	if (res->map[p1res.x][p1res.y] == res->map[p2res.x][p2res.y])
		return (res->map[p2res.x][p2res.y]);
	p1pos = 1 - (double)(x - p1res.x) / (double)(p2res.x - p1res.x);
	p2pos = 1 - (double)(p2res.x - x) / (double)(p2res.x - p1res.x);
	c1 = ((res->map[p1res.x][p1res.y] >> 16)) * p1pos;
	c2 = ((res->map[p2res.x][p2res.y] >> 16)) * p2pos;
	color = ((int)(c1 + c2 + 0.5) << 16);
	c1 = ((res->map[p1res.x][p1res.y] >> 8) % 256) * p1pos;
	c2 = ((res->map[p2res.x][p2res.y] >> 8) % 256) * p2pos;
	color += ((int)(c1 + c2 + 0.5) << 8);
	c1 = ((res->map[p1res.x][p1res.y]) % 256) * p1pos;
	c2 = ((res->map[p2res.x][p2res.y]) % 256) * p2pos;
	color += ((int)(c1 + c2 + 0.5));
	return (color);
}

int	get_color_hor(t_pos p1res, t_pos p2res, int y, t_map *res)
{
	double	c1;
	double	c2;
	double	p1pos;
	double	p2pos;
	int		color;

	if (res->map[p1res.x][p1res.y] == res->map[p2res.x][p2res.y])
		return (res->map[p2res.x][p2res.y]);
	p1pos = 1 - (double)(y - p1res.y) / (double)(p2res.y - p1res.y);
	p2pos = 1 - (double)(p2res.y - y) / (double)(p2res.y - p1res.y);
	c1 = ((res->map[p1res.x][p1res.y] >> 16)) * p1pos;
	c2 = ((res->map[p2res.x][p2res.y] >> 16)) * p2pos;
	color = ((int)(c1 + c2 + 0.5) << 16);
	c1 = ((res->map[p1res.x][p1res.y] >> 8) % 256) * p1pos;
	c2 = ((res->map[p2res.x][p2res.y] >> 8) % 256) * p2pos;
	color += ((int)(c1 + c2 + 0.5) << 8);
	c1 = ((res->map[p1res.x][p1res.y]) % 256) * p1pos;
	c2 = ((res->map[p2res.x][p2res.y]) % 256) * p2pos;
	color += ((int)(c1 + c2 + 0.5));
	return (color);
}
