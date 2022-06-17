/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:16:36 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/17 13:25:25 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Securiter calloc
Voir avec Eliot pour le valgrind
Norminette
Faire .h clean
Verifier qu'il n'y a pas de variable globale
*/

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
	void	*win1;
	void	*im1;
	t_vars	vars;

	pix = get_pix_map(argc, argv);
	if (pix)
	{
		mlx = mlx_init();
		if (!mlx)
			exit (1);
		win1 = mlx_new_window(mlx, 2400, 1200, "FDF");
		im1 = mlx_new_image(mlx, pix->height, pix->width);
		if (!im1 || !win1)
			exit(1);
		mlx_clear_window(mlx, win1);
		vars.mlx = mlx;
		vars.win = win1;
		vars.img = im1;
		fill_window(pix, &vars);
		mlx_loop(mlx);
		free_map(&pix);
	}
}
