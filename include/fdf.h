#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <math.h>
#include "../lib/libft/libft.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/minilibx/mlx_int.h"

typedef struct	s_map
{
	int	width;
	int	height;
	int	**map;
	int	**color;
	int	maxHeight;
}	t_map;

typedef struct	s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
	void	*img;
	t_map	**pix;
}	t_vars;

//color
int	get_color_ver(t_pos p1res, t_pos p2res, int x, t_map *res);
int	get_color_hor(t_pos p1res, t_pos p2res, int y, t_map *res);

//draw line
void	draw_line_hor(t_map *res, t_pos p1, t_pos p2);
void	draw_line_ver(t_map *res, t_pos p1, t_pos p2);
void	draw_line(t_map *res, t_map *pm, t_pos pm1, t_pos pm2);
void	draw_all_line(t_map *res, t_map *pm);

//fdf
int	close_win(int keycode, t_vars *vars);
int	close_win_cross(t_vars *vars);
void	fill_window(t_map *pix, t_vars *v);
int	main(int argc, char **argv);

//map manager 
void	*free_map(t_map **map);
int	color_map(void *im1, t_pos pos, t_map *pix, void *mlx);
t_map	*get_pix_map(int argc, char **argv);

//parsing
size_t	get_width(char *str);
int	init_map(t_map *res, t_list *int_tab, t_list *color);
void	free_int_tab(t_list	**int_tab);
t_map	*pars_file_in_map(int fd);


//pixeler
double	get_sr(int width, t_map *pm);
t_map	*init_pix_map(size_t w, size_t h, t_map *pm);
t_map	*pixelize_map(t_map *pm, size_t width, size_t height);

//point
double	get_uppoint(int height, int width);
t_pos	getpos_pixelmap(int x, int y, t_map *pm);
void	init_point(t_map *res, t_map *pm);

//pos
t_pos	new_pos(int x, int y);

//spl int tab
int	*line_into_int_tab(char **spl, int s);
int	*line_into_color_tab(char **spl, int s);
void	split_to_int_tab(t_list **int_tab, t_list **color, char *buf);

//utils
int	get_highest_num(t_map *pm);
int	get_lowest_num(t_map *pm);

#endif