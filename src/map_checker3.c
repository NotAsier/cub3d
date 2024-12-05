/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:02:14 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/05 12:47:28 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	dump_map2(t_params *params, size_t k)
{
	size_t	i;
	size_t	j;

	i = k;
	j = 0;
	params->map = malloc(sizeof(char *) * (params->raw_heigth - i) + 1);
	while (params->raw[i])
	{	
		{
			params->map[j] = ft_strdup(params->raw[i]);
			i++;
			j++;
		}
	}
}
