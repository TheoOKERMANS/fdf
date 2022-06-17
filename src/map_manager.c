/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:34:10 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/17 20:06:40 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	*free_map(t_map **map)
{
	int	y;

	if ((*map)->map != NULL)
	{
		y = 0;
		while ((*map)->map[y] != NULL)
			free((*map)->map[y++]);
		free((*map)->map);
	}
	if ((*map)->color != NULL)
	{
		y = 0;
		while ((*map)->color[y] != NULL)
			free((*map)->color[y++]);
		free((*map)->color);
	}
	free((*map));
	return (NULL);
}

int	color_map(void *im1, t_pos pos, t_map *pix, void *mlx)
{
	t_pos			loop;
	int				dec;
	int				color;
	unsigned char	*ptr;

	loop.y = pos.y;
	while (loop.y--)
	{
		ptr = (unsigned char *)((t_img *)im1)->data + loop.y
			* ((t_img *)im1)->size_line;
		loop.x = pos.x;
		while (loop.x--)
		{
			color = mlx_get_color_value(mlx, pix->map[loop.y][loop.x]);
			dec = 4;
			while (dec--)
				*(ptr + loop.x * 4 + dec) = ((unsigned char *)(&color))[dec];
		}
	}
	return (1);
}

t_map	*get_pix_map(int argc, char **argv, int h, int w)
{
	int		fd;
	t_map	*map;
	t_map	*pix;

	if (argc != 2)
		return (NULL);
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])) == NULL)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
		map = pars_file_in_map(fd);
	else
		return (NULL);
	close(fd);
	if (!map)
		return (NULL);
	pix = pixelize_map(map, h, w);
	free_map(&map);
	get_sr(2147483647, NULL);
	return (pix);
}
