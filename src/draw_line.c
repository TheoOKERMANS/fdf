/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:45:21 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/10 15:24:29 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line_hor(t_map *res, t_pos p1, t_pos p2)
{
	double	x;
	int		y;
	double	func;

	y = p1.y;
	func = (double)(p2.x - p1.x) / (double)(p2.y - p1.y);
	while (++y < p2.y)
	{
		x = (double)(y - p1.y) *func;
		if (fmod(x, (double)1) > 0.5)
			x = (x / 1) + 1;
		else
			x = x / 1;
		res->map[(int)x + p1.x][y] = get_color_hor(p1, p2, y, res);
	}
}

void	draw_line_ver(t_map *res, t_pos p1, t_pos p2)
{
	int		x;
	double	y;
	double	func;
	t_pos	temp;

	if (p2.x < p1.x)
	{
		temp = p2;
		p2 = p1;
		p1 = temp;
	}
	x = p1.x;
	func = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	while (++x < p2.x)
	{
		y = (double)(x - p1.x) *func;
		if (fmod(y, (double)1) > 0.5)
			y = (y / 1) + 1;
		else
			y = y / 1;
		res->map[x][(int)y + p1.y] = get_color_ver(p1, p2, x, res);
	}
}

void	draw_line(t_map *res, t_map *pm, t_pos pm1, t_pos pm2)
{
	double	func;
	t_pos	p1;
	t_pos	p2;

	p1 = getpos_pixelmap(pm1.x, pm1.y, pm);
	p2 = getpos_pixelmap(pm2.x, pm2.y, pm);
	if (p2.y < p1.y)
	{
		p2 = p1;
		p1 = getpos_pixelmap(pm2.x, pm2.y, pm);
	}
	func = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	if (func > 1.0 || func < -1.0)
		draw_line_hor(res, p1, p2);
	else
		draw_line_ver(res, p1, p2);
}

void	draw_all_line(t_map *res, t_map *pm)
{
	int	x;
	int	y;

	x = 0;
	while (x < pm->height)
	{
		y = 0;
		while (y < pm->width)
		{
			if (y < pm->width - 1)
				draw_line(res, pm, new_pos(x, y), new_pos(x, y + 1));
			if (x < pm->height - 1)
				draw_line(res, pm, new_pos(x, y), new_pos(x + 1, y));
			y++;
		}
		x++;
	}
}
