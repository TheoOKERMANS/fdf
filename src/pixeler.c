/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixeler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:58:50 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/17 18:21:45 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	get_sr(int width, t_map *pm)
{
	static double	g_sr = 2147483647;

	if (g_sr == 2147483647)
	{
		g_sr = pm->height / cos(30 * 3.14159265 / 180);
		g_sr += pm->width * cos(30 * 3.14159265 / 180);
		g_sr = width / g_sr;
	}
	return (g_sr);
}

t_map	*init_pix_map(size_t w, size_t h, t_map *pm)
{
	t_map	*res;
	size_t	i;

	res = ft_calloc(1, sizeof(t_map));
	if (!res)
		return (NULL);
	res->width = w;
	res->height = h;
	res->maxHeight = h + (get_sr(w, pm) * cos(60 * 3.14159265 / 180))
			* get_uppoint(pm->height, pm->width) * 3;
	res->map = ft_calloc(1 + res->maxHeight, sizeof(int *));
	if (!res->map)
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while ((int)i < res->maxHeight)
	{
		res->map[i] = ft_calloc(w + 1, sizeof(int));
		if (!res->map[i])
			return (free_map(&res));
		i++;
	}
	return (res);
}

t_map	*pixelize_map(t_map *pm, size_t width, size_t height)
{
	t_map	*res;

	get_sr(width, pm);
	res = init_pix_map(width, height, pm);
	if (!res)
		return (res);
	init_point(res, pm);
	draw_all_line(res, pm);
	return (res);
}
