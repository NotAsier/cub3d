/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:56:58 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 14:16:14 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_splited(char **splited)
{
	int	i;

	i = -1;
	while (splited && splited[++i])
		free(splited[i]);
	free(splited);
}

int	red_cross(t_params *params)
{
	free_map(params);
	exit(0);
	return (0);
}

void	free_map(t_params *params)
{
	free(params->map_path);
	free(params->map_name);
	free_splited(params->raw);
	free_splited(params->map);
}

void	win(t_params *params)
{
	write(1, "YOU WIN!", 8);
	free_map(params);
	exit(0);
}
