/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:33 by aarranz-          #+#    #+#             */
/*   Updated: 2024/12/10 15:41:05 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

typedef struct s_parameters
{
	int		fd;
	char	**raw;
	size_t	raw_heigth;
	size_t	longest;
	int		player_x;
	int		player_y;
	char	player_dir;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*C;
	char	*F;
	int		map_len;
	int		map_heigth;
	char	*map_path;
	char	*map_name;
	char	**map;
}			t_params;

typedef struct s_ff_list
{
	int		x;
	int		y;
	void	*next;
}	t_ff_list;

//------------------------------------------------------------------------------
//			PARSE MAP
//------------------------------------------------------------------------------
void	init(t_params *params);
void	check_fd(t_params *params);
void	error(char *message, t_params *params);
void	parse_map(t_params *params);
void	dump_raw(t_params *params);
void	cub_check(t_params *params);
void	player_position(t_params *params, char *str, int y);
void	dump_info(t_params *params);
void	dump_info2(t_params *params);
char 	*take_path(char *str,int nbr);
void	dump_map(t_params *params);
void	dump_map2(t_params *params, size_t k);
void	check_char_map(t_params *params, int k);
void	longest_line(t_params *params, int k);
bool	is_closed(t_params *params);
/*void	map_walls(t_params *params);
void	count_lines_len_map(t_params *params);
void	char_counter(t_params *params);
void	flood_fill(t_params *params, int y, int x);
void	filled_map_checker(t_params *params);
void	dump_filled_map(t_params *params);*/
//------------------------------------------------------------------------------
//			LEAKS CONTROL
//------------------------------------------------------------------------------
void	free_map(t_params *params);
int		red_cross(t_params *params);
//------------------------------------------------------------------------------
//			PRINT INFO
//------------------------------------------------------------------------------
void	print_info(t_params *params);

#endif // CUB3D_H