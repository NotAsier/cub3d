/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:55:57 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 13:54:46 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
void	dump_info(t_params *params)
{
	int	i;
	size_t	j;

	i = -1;
	while (params->raw[++i])
		{
			j = -1;
			while (++j <= ft_strlen(params->raw[i]))
			{
				if (params->raw[i][j] == 'N' && params->raw[i][j+1] == 'O'
				&& params->raw[i][j+1] == ' ')
					params->NO = ft_strdup(params->raw[i]); 
				/*else if(params->raw[i][j] == 'S' && params->raw[i][j++] == 'O'
				&& params->raw[i][j+1] == ' ')
					params->SO = ft_strdup(params->raw[i]);
				else if(params->raw[i][j] == 'E' && params->raw[i][j++] == 'A'
				&& params->raw[i][j+1] == ' ')
					params->EA = ft_strdup(params->raw[i]);
				else if(params->raw[i][j] == 'W' && params->raw[i][j++] == 'E'
				&& params->raw[i][j+1] == ' ')
					params->WE = ft_strdup(params->raw[i]);*/
			}
		}
}
void	player_position(t_params *params)
{
	int	i;
	size_t	j;

	i = -1;
	while (params->raw[++i])
		{
			j = -1;
			while (++j <= ft_strlen(params->raw[i]))
			{
				if (params->raw[i][j] == 'N' || params->raw[i][j] == 'S'
				 || params->raw[i][j] == 'E' || params->raw[i][j] == 'W')
				{
					params->player_x = j;
					params->player_y = i;
					params->player_pos = params->raw[i][j];
				}
			}
		}
}
