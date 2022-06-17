/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spl_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:22:28 by tokerman          #+#    #+#             */
/*   Updated: 2022/06/15 16:58:48 by tokerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	*line_into_int_tab(char **spl, int s)
{
	int		*res;
	int		i;

	res = NULL;
	if (s == 0)
		return (NULL);
	res = ft_calloc(s + 1, sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	while (i < s)
	{
		res[i] = ft_atoi((const char *)spl[i]);
		i++;
	}
	return (res);
}

int	*line_into_color_tab(char **spl, int s)
{
	int		*res;
	int		i;

	res = NULL;
	if (s == 0)
		return (NULL);
	res = ft_calloc(s + 1, sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	while (i < s)
	{
		if (ft_strnstr((const char *)spl[i], "0x", ft_strlen(spl[i])) == NULL)
			res[i] = (255 << 16) + (255 << 8) + 255;
		else
			res[i] = hex_to_int(ft_strnstr((const char *)spl[i],
						"0x", ft_strlen(spl[i])) + 2);
		i++;
	}
	return (res);
}

void	split_to_int_tab(t_list **int_tab, t_list **color, char *buf)
{
	char	**spl;
	size_t	s;
	size_t	i;

	spl = ft_split(buf, ' ');
	s = 0;
	while (spl && spl[s] != NULL)
		s++;
	ft_lstadd_back(int_tab, ft_lstnew(line_into_int_tab(spl, s)));
	ft_lstadd_back(color, ft_lstnew(line_into_color_tab(spl, s)));
	i = 0;
	while (spl[i] != NULL)
		free(spl[i++]);
	free(spl);
}
