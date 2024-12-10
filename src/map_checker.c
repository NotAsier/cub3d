/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:12:10 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/10 16:03:14 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dump_raw(t_params *params)
{
	int		fd;
	char	*result;
	int		i;

	result = NULL;
	fd = open(params->map_path, O_RDONLY);
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		params->raw_heigth++;
	}
	params->raw = malloc(sizeof(char *) * params->raw_heigth + 1);
	close(fd);
	fd = open(params->map_path, O_RDONLY);
	i = 0;
	while (1)
	{
		params->raw[i] = get_next_line(fd);
		
		if (!params->raw[i])
			break ;
		i++;
	}
}

void	cub_check(t_params *params)
{
	params->map_name = ft_strdup(ft_strrchr(params->map_path, '/') + 1);
	if ((ft_strlen(params->map_name) <= 4)
		|| ((params->map_name[ft_strlen(params->map_name) - 1] != 'b')
			|| (params->map_name[ft_strlen(params->map_name) - 2] != 'u')
			|| (params->map_name[ft_strlen(params->map_name) - 3] != 'c')
			|| (params->map_name[ft_strlen(params->map_name) - 4] != '.')))
		error("map extension not valid", params);
}

void	check_char_map(t_params *params, int k)
{
	int	i;
	int	j;
	bool	player_found;

	i = k;
	player_found = false;
	while (params->raw[i])
	{
		j = 0;
		while (params->raw[i][j])
		{
			if (params->raw[i][j] != '1'
			&& params->raw[i][j] != '0'
			&& (params->raw[i][j] != 'N')
			&& params->raw[i][j] != 'W'
			&& params->raw[i][j] != 'S'
			&& params->raw[i][j] != 'E'
			&& params->raw[i][j] != ' '
			&& params->raw[i][j] != '\n')
				error("characters in map are invalid", params);
			if (params->raw[i][j] == 'N' || params->raw[i][j] == 'W' || params->raw[i][j] == 'S' || params->raw[i][j] == 'E')
			{
				if (player_found == true)
					error("More than one player in map!", params);
				player_found = true;
			}
			j++;
		}
		i++;
	}
	if (!player_found)
		error("Less than one player! Empty map", params);
}

void	count_lines_len_map(t_params *params)
{
	int	i;

	i = 0;
	while (params->map[i])
	{
		if ((params->map[i][params->map_len] != '1')
			|| (params->map[i][params->map_len + 1] != '\n'
			&& params->map[i][params->map_len + 1] != '\0'))
			error("map char count in lines not valid", params);
		i++;
	}
}
