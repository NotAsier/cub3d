/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:55:57 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/10 14:46:29 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info(t_params *params)
{
	int i = 0;
	
	/*while(params->raw[i])
	{
		printf("%s", params->raw[i]);
		i++;
	}
	printf("\n%c", params->player_pos);
	printf("\n%i", params->player_x);
	printf("\n%i", params->player_y);
	printf("\n%s", params->NO);
	printf("\n%s", params->SO);
	printf("\n%s", params->EA);
	printf("\n%s", params->WE);
	printf("\n%s", params->F);
	printf("\n%s", params->C);*/
	i = 0;
	while(params->map[i])
	{
		printf("%s\n", params->map[i]);
		i++;
	}
	printf("%ld\n", params->longest);
	printf("%d\n", params->map_heigth);
	
}


/*void	char_counter(t_params *params)
{
	int	i;
	int	j;

	i = -1;
	while (params->raw[++i])
	{
		j = -1;
		while (++j <= params->map)
		{
			if (params->raw[i][j] == 'P')
			{
				params->player_x = j;
				params->player_y = i;
			}
		}
	}
		//error("raw char counter not valid", params);
}*/

void	dump_map(t_params *params)
{
	size_t	i;
	size_t	j;
	size_t	info_line;

	info_line = 0;
	i = -1;
	while ((++i >= params->raw_heigth) || (info_line < 6))
	{
		j = -1;
		while (params->raw[i][++j] != '\0')
		{
			if ((params->raw[i][j] == 'N' && params->raw[i][j+1] == 'O'
			&& params->raw[i][j+2] == ' ') || (params->raw[i][j] == 'S'
			&& params->raw[i][j+1] == 'O' && params->raw[i][j+2] == ' ') 
			|| (params->raw[i][j] == 'E' && params->raw[i][j+1] == 'A'
			&& params->raw[i][j+2] == ' ') || (params->raw[i][j] == 'W' 
			&& params->raw[i][j+1] == 'E' && params->raw[i][j+2] == ' ')
			|| (params->raw[i][j] == 'C' && params->raw[i][j+1] == ' ')
			|| (params->raw[i][j] == 'F' && params->raw[i][j+1] == ' '))
				info_line++;					
		}
	}
	longest_line(params, i);
	dump_map2(params, i);
}


char *take_path(char *str, int nbr)
{
	char *trimed;

	trimed = ft_strtrim(str, " ");
	free(str);
	str = ft_strtrim(trimed + nbr, " \n");
	free(trimed);
	return(str);
}
void	dump_info(t_params *params)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (params->raw[++i])
		{
			j = -1;
			while (params->raw[i][++j] != '\0')
			{
				if (params->raw[i][j] == 'N' && params->raw[i][j+1] == 'O'
				&& params->raw[i][j+2] == ' ')
					params->NO = take_path(ft_strdup(params->raw[i]), 2); 
				else if(params->raw[i][j] == 'S' && params->raw[i][j+1] == 'O'
				&& params->raw[i][j+2] == ' ')
					params->SO = take_path(ft_strdup(params->raw[i]), 2);
				else if(params->raw[i][j] == 'E' && params->raw[i][j+1] == 'A'
				&& params->raw[i][j+2] == ' ')
					params->EA = take_path(ft_strdup(params->raw[i]), 2);
				else if(params->raw[i][j] == 'W' && params->raw[i][j+1] == 'E'
				&& params->raw[i][j+2] == ' ')
					params->WE = take_path(ft_strdup(params->raw[i]), 2);
			}
		}
}
void	dump_info2(t_params *params)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (params->raw[++i])
		{
			j = -1;
			while (params->raw[i][++j] != '\0')
			{
				if (params->raw[i][j] == 'C' && params->raw[i][j+1] == ' ')
					params->C = take_path(ft_strdup(params->raw[i]), 1); 
				else if(params->raw[i][j] == 'F' && params->raw[i][j+1] == ' ')
					params->F = take_path(ft_strdup(params->raw[i]), 1);
			}
		}
}

void	player_position(t_params *params, char *str, int y)
{
	size_t	i;

	i = -1;
	while (str[++i])
		{
			if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			{
				params->player_x = i;
				params->player_y = y;
				params->player_dir = str[i];
			}
		}
}
