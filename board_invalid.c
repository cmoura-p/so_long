/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 22:27:41 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	board_invalid(char *ber, t_data *data)
{
	char	**line;
	int		i;

	line = start_lines(&ber, data->map);
	if (!line)
		return (free_map(line), 1);
	i = start_map(data->map);
	if (i != 0)
		return (free_map(line), 1);
	if (check_wall(line[0]) || check_wall(line[data->map->rows -1]))
		return (free_map(line), 1);
	i = 0;
	while (line[i])
	{
		if (check_map_content(line[i], data->map, i))
			return (free_map(line), 1);
		i++;
	}
	if (data->map->player_x < 1 || data->map->exit < 1 || data->map->gift < 1)
		return (free_map(line), 1);
	if (check_access(data))
		return (free_map(line), 1);
	free_map(line);
	return (0);
}
