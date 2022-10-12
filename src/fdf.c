/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:16:36 by tokerman          #+#    #+#             */
/*   Updated: 2022/10/11 15:42:13 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free_map(vars->pix);
		exit(0);
	}
	return (0);
}

int	close_win_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->pix);
	exit(0);
	return (0);
}

void	fill_window(t_map *pix, t_vars *v)
{
	t_pos	img_size;

	img_size.x = 2000;
	img_size.y = 2000;
	color_map(v->img, img_size, pix, v->mlx);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 100, 100);
	mlx_hook(v->win, 2, 1L << 0, close_win, v);
	mlx_hook(v->win, 17, 1L << 0, close_win_cross, v);
}

int	main(int argc, char **argv)
{
	t_map	*pix;
	void	*mlx;
	t_vars	vars;

	pix = get_pix_map(argc, argv, 2000, 2000);
	if (pix)
	{
		mlx = mlx_init();
		if (!mlx)
			exit (1);
		vars.win = mlx_new_window(mlx, 2000, 1200, "FDF");
		vars.img = mlx_new_image(mlx, pix->height, pix->width);
		if (!vars.img || !vars.win)
			exit(1);
		mlx_clear_window(mlx, vars.win);
		vars.mlx = mlx;
		vars.pix = &pix;
		vars.argc = argc;
		vars.argv = argv;
		fill_window(pix, &vars);
		mlx_loop(mlx);
	}
}
