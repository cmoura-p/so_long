/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 17:04:00 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_wall(int row, int col, t_map *map)
{
	map->map[row][col] = '1';
}

void	add_gift(int row, int col, t_map *map)
{
	map->map[row][col] = 'C';
	map->gift++;
}

void	add_exit(int row, int col, t_map *map)
{
	map->map[row][col] = 'E';
	map->exit++;
}

void	add_player(int row, int col, t_map *map)
{
	map->map[row][col] = 'P';
	map->player_x = col;
	map->player_y = row;
}

void	add_floor(int row, int col, t_map *map)
{
	map->map[row][col] = '0';
}
