/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:30:41 by aarranz-          #+#    #+#             */
/*   Updated: 2024/05/02 14:15:07 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_params *params)
{
	params->fd = 0;
	params->raw = NULL;
	params->raw_heigth = 0;
	params->player_x = 0;
	params->player_y = 0;
	params->NO = NULL;
	params->SO = NULL;
	params->WE = NULL;
	params->EA = NULL;
	params->C = NULL;
	params->F = NULL;
	params->map_len = 0;
	params->map_heigth = 0;
	params->map_path = NULL;
	params->map_name = NULL;
	params->map = NULL;
}

void	check_fd(t_params *params)
{
	char	*res;

	res = NULL;
	params->fd = open(params->map_path, O_RDONLY);
	res = get_next_line(params->fd);
	if (!res || ft_strlen(res) < 3 || res[0] == '\n')
	{
		close(params->fd);
		error("file can't open", params);
	}
	free(res);
	close(params->fd);
}

void	error(char *message, t_params *params)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_map(params);
	exit(0);
}

void	parse_map(t_params *params)
{
	int i = 0;

	cub_check(params);
	check_fd(params);
	dump_raw(params);
	dump_info(params);
	player_position(params);
	while(params->raw[i])
	{
		printf("%s", params->raw[i]);
		i++;
	}
	printf("\n%c", params->player_pos);
	printf("\n%i", params->player_x);
	printf("\n%i", params->player_y);
	printf("\n%s", params->NO);
	/*printf("\n%s", params->SO);
	printf("\n%s", params->EA);
	printf("\n%s", params->WE);*/
		
		
	/*
	check_char_map(params);
	map_walls(params);
	count_lines_len_map(params);
	char_counter(params);
	*/
}

int	main(int argc, char **argv)
{
	t_params	*params;

	if (argc != 2)
		return (-1);
	params = malloc(sizeof(t_params));
	init(params);
	params->map_path = ft_strdup(argv[1]);
	parse_map(params);
	return (0);
}
