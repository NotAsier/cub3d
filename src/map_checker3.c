/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:02:14 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/10 15:11:40 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ff_list	*c3d_lstnew(int y, int x)
{
	t_ff_list	*node;

	node = (t_ff_list *)malloc(sizeof(t_ff_list));
	if (node == NULL)
		return (NULL);
	node->x = x;
	node->y = y;
	node->next = NULL;
	return (node);
}

void	c3d_lstadd_front(t_ff_list **lst, t_ff_list *new)
{
	if (lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_ff_list	*c3d_lstlast(t_ff_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	c3d_lstadd_back(t_ff_list **lst, t_ff_list *new)
{
	t_ff_list	*node;

	node = c3d_lstlast(*lst);
	if (node)
		node->next = new;
	else
		c3d_lstadd_front(lst, new);
}

void	free_array(void **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

bool	check_x(char **map, int x, int y, t_params *params)
{
	if (y >= params->map_heigth - 1 || \
	(map[y + 1][x] != '1' && map[y + 1][x] != 'X'))
		return (false);
	if (y <= 0 || (map[y - 1][x] != '1' && map[y - 1][x] != 'X'))
		return (false);
	if (x >= (int)params->longest || (map[y][x + 1] != '1' && map[y][x + 1] != 'X'))
		return (false);
	if (x <= 0 || (map[y][x - 1] != '1' && map[y][x - 1] != 'X'))
		return (false);
	return (true);
}

bool	search_map(char **map, t_params *params)
{
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'X' && !check_x(map, x, y, params))
				return (false);
		}
	}
	return (true);
}

void	search_inner_floors(t_params *params, char **map, t_ff_list **positions)
{
	int			x;
	int			y;
	t_ff_list	*to_check;

	to_check = *positions;
	x = to_check->x;
	y = to_check->y;
	if (x > 0 && map[y][x - 1] != '1' && map[y][x - 1] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y, x - 1));
	if (x < (int)params->longest && map[y][x + 1] != '1' && map[y][x + 1] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y, x + 1));
	if (y > 0 && map[y - 1][x] != '1' && map[y - 1][x] != 'X')
		c3d_lstadd_back(positions, c3d_lstnew(y - 1, x));
	if (y < params->map_heigth - 1 && map[y + 1][x] != '1' && map[y + 1][x] != 'X')
	{
		printf("at %d %d == [%c]\n", x, y + 1, map[y + 1][x]);
		c3d_lstadd_back(positions, c3d_lstnew(y + 1, x));
	}
	map[y][x] = 'X';
	*positions = to_check->next;
	for (size_t i = 0; map[i]; i++)
	{
		printf("%s\n", map[i]);
	}
	printf("\n\n");
	free(to_check);
}

bool	is_closed(t_params *params)
{
	t_ff_list	*positions;
	char		**map_cpy;
	int			i;
	bool		retval;

	positions = c3d_lstnew(params->player_y, params->player_x);
	map_cpy = malloc((params->map_heigth + 1) * sizeof(char *));
	i = -1;
	while (++i < params->map_heigth)
		map_cpy[i] = ft_strdup(params->map[i]);
	map_cpy[i] = NULL;
	search_inner_floors(params, map_cpy, &positions);
	while (positions)
		search_inner_floors(params, map_cpy, &positions);
	retval = search_map(map_cpy, params);
	//free_array((void **)map_cpy);
	free(positions);
	return (retval);
}


void longest_line(t_params *params, int k)
{
	int i;
	int j;
	size_t line;

	i = k;
	line = 0;
	while (params->raw[i])
	{	
		j = 0;
		while (params->raw[i][j])
			j++;
		line = j;
		if(line > params->longest)
			params->longest = line;
		i++;
	}
}

void	dump_map2(t_params *params, size_t k)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = k;
	j = 0;
	params->map_heigth = params->raw_heigth - i;
	params->map = malloc(sizeof(char *) * params->map_heigth + 1);
	while (params->raw[i])
	{	
		player_position(params, params->raw[i], j);
		params->map[j] = malloc(sizeof(char) * (params->longest + 1));
		l = 0;
		while(l <= params->longest)
		{
			params->map[j][l] = '0';
			if (l <= ft_strlen(params->raw[i]) && params->raw[i][l] == '1')
				params->map[j][l] = '1';
			l++;
		}
		params->map[j][l + 1] = '\0';
		i++;
		j++;
	}
}
