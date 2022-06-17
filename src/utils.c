/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:09:30 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/09 18:05:07 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_highest_num(t_map *pm)
{
	static int	res = 2147483647;
	int			i;
	int			j;

	if (res == 2147483647)
	{
		i = 0;
		j = 0;
		res = 0;
		while (i < pm->height)
		{
			j = 0;
			while (j < pm->width)
			{
				if (res < pm->map[i][j])
					res = pm->map[i][j];
				j++;
			}
			i++;
		}
	}
	return (res);
}

int	get_lowest_num(t_map *pm)
{
	static int	res = 2147483647;
	int			i;
	int			j;

	if (res == 2147483647)
	{
		i = 0;
		j = 0;
		while (i < pm->height)
		{
			j = 0;
			while (j < pm->width)
			{
				if (res > pm->map[i][j])
					res = pm->map[i][j];
				j++;
			}
			i++;
		}
	}
	return (res);
}
