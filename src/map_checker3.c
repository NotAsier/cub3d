/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:02:14 by aarranz-          #+#    #+#             */
/*   Updated: 2024/11/25 13:56:18 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dump_map2(t_params *params, size_t k)
{
	size_t	i;
	size_t	j;

	i = k;
	j = 0;
	while (i >= params->raw_heigth)
	{	
		{
			params->map[j] = ft_strdup(params->raw[i]);
			i++;
			j++;
		}
	}

}