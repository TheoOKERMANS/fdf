/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:17:40 by tokerman          #+#    #+#             */
/*   Updated: 2022/10/11 15:43:44 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

size_t	get_width(char *str)
{
	size_t	res;
	char	**spl;
	size_t	i;

	spl = ft_split(str, ' ');
	res = 0;
	while (spl[res] != NULL && spl[res][0] != '\n')
		res++;
	i = 0;
	while (spl[i] != NULL)
		free(spl[i++]);
	free(spl);
	return (res);
}

int	init_map(t_map *res, t_list *int_tab, t_list *color)
{
	size_t	i;
	t_list	*temp;
	t_list	*temp_c;

	res->map = ft_calloc(ft_lstsize(int_tab) + 1, sizeof(int *));
	res->color = ft_calloc(ft_lstsize(color) + 1, sizeof(int *));
	if (!res->map || !res->color)
		return (0);
	res->height = ft_lstsize(int_tab);
	temp = int_tab;
	temp_c = color;
	i = 0;
	while (temp != NULL && temp_c != NULL)
	{
		res->map[i] = temp->content;
		res->color[i] = temp_c->content;
		temp = temp->next;
		temp_c = temp_c->next;
		i++;
	}
	return (1);
}

void	free_int_tab(t_list	**int_tab)
{
	t_list	*temp;

	while (*int_tab != NULL)
	{
		temp = (*int_tab)->next;
		free((*int_tab));
		(*int_tab) = temp;
	}
}

t_map	*pars_file_in_map(int fd)
{
	char	*buf;
	t_map	*res;
	t_list	*int_tab;
	t_list	*color;

	res = ft_calloc(1, sizeof(t_map));
	if (!res)
		return (NULL);
	res->width = -1;
	int_tab = NULL;
	color = NULL;
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		if (res->width == -1)
			res->width = get_width(buf);
		split_to_int_tab(&int_tab, &color, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	if (init_map(res, int_tab, color) == 0)
		free_map(&res);
	free_int_tab(&int_tab);
	free_int_tab(&color);
	return (res);
}
