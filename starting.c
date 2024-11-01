/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/21 22:07:57 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter_field(char *ber)
{
	int		num_lin;
	char	segment;
	int		bytes_read;
	int		fd;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		return (0);
	num_lin = 0;
	bytes_read = read(fd, &segment, 1);
	if (bytes_read <= 0)
		return (0);
	while (bytes_read > 0)
	{
		if (segment == '\n')
			num_lin++;
		bytes_read = read(fd, &segment, 1);
	}
	if (bytes_read == 0 && segment != '\n')
		num_lin++;
	close(fd);
	return (num_lin);
}

void	start_data(t_data *data)
{
	data->sprites = ft_calloc(1, sizeof(t_sprites));
	data->map = ft_calloc(1, sizeof(t_map));
}

char	**start_lines(char **ber, t_map *map)
{
	int		i;
	int		num_lin;
	char	**line;
	int		fd;

	num_lin = counter_field(*ber);
	fd = open(*ber, O_RDONLY);
	if (fd < 0 || num_lin <= 0)
		return (NULL);
	line = ft_calloc(num_lin + 1, sizeof(char *));
	i = 0;
	line[i] = get_next_line(fd);
	while (i < num_lin)
	{
		if (!lastline(line, i, num_lin)
			&& (ft_strlen(line[0]) != ft_strlen(line[i])))
			return (free_map(line), NULL);
		i++;
		line[i] = get_next_line(fd);
	}
	map->cols = ft_strlen(line[0]) - 1;
	map->rows = num_lin;
	line[i] = NULL;
	close(fd);
	return (line);
}

int	start_map(t_map *map)
{
	int	i;

	map->map = ft_calloc(map->rows + 1, sizeof(char *));
	if (!map->map)
		return (1);
	i = 0;
	while (i < map->rows)
	{
		map->map[i] = ft_calloc(map->cols + 1, sizeof(char));
		i++;
	}
	map->map[i] = NULL;
	return (0);
}

int	lastline(char **line, int i, int nl)
{
	unsigned long	x;

	if (i == nl - 1)
	{
		x = ft_strlen(line[i]);
		if ((ft_strlen(line[0]) - 1 == x) && line[i][x - 1] != '\n')
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
