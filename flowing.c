/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flowing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 22:32:23 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_access(t_data *data)
{
	int		x;
	int		y;
	char	**map_aux;

	y = 0;
	x = 0;
	map_aux = copy_map(data->map->map, data->map->rows);
	if (!map_aux)
		return (1);
	if (aux_flow(data, map_aux, x, y))
		return (1);
	return (0);
}

char	**copy_map(char **map, int rows)
{
	char	**map_aux;
	int		i;

	map_aux = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map_aux)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_aux[i] = ft_strdup(map[i]);
		if (!map_aux[i])
		{
			while (i >= 0)
			{
				free(map_aux[i]);
				i--;
			}
			return (NULL);
		}
		i++;
	}
	map_aux[i] = NULL;
	return (map_aux);
}

int	is_acessible(t_data *data, char **map_aux, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map->cols || y >= data->map->rows)
		return (0);
	if (map_aux[y][x] == '1')
		return (0);
	if (map_aux[y][x] == 'P')
		return (1);
	map_aux[y][x] = '1';
	if (is_acessible(data, map_aux, x + 1, y)
		|| is_acessible(data, map_aux, x - 1, y)
		|| is_acessible(data, map_aux, x, y + 1)
		|| is_acessible(data, map_aux, x, y - 1))
		return (1);
	return (0);
}

int	aux_flow(t_data *data, char **map_aux, int x, int y)
{
	while (map_aux[y])
	{
		x = 0;
		while (map_aux[y][x])
		{
			if (map_aux[y][x] == 'E' || map_aux[y][x] == 'C')
			{
				if (!is_acessible(data, map_aux, x, y))
					return (free_map(map_aux), 1);
				free_map(map_aux);
				map_aux = copy_map(data->map->map, data->map->rows);
			}
			x++;
		}
		y++;
	}
	free_map(map_aux);
	return (0);
}
