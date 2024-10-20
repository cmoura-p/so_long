/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 22:25:19 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_content(char *line, t_map *map, int n_line)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		return (1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '1')
			add_wall(n_line, i, map);
		else if (line[i] == 'P' && map->player_x < 1)
			add_player(n_line, i, map);
		else if (line[i] == 'C')
			add_gift(n_line, i, map);
		else if (line[i] == 'E' && map->exit < 1)
			add_exit(n_line, i, map);
		else if (line[i] == '0')
			add_floor(n_line, i, map);
		else
			return (1);
		i++;
	}
	if (line[i - 1] != '1')
		return (1);
	return (0);
}
