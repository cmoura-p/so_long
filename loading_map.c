/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 18:48:24 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_data *data)
{
	int		i;
	int		j;

	data->sprites->walls = mlx_xpm_file_to_image(data->mlx,
			"./sprites/wall.xpm", &i, &j);
	data->sprites->floor = mlx_xpm_file_to_image(data->mlx,
			"./sprites/floor.xpm", &i, &j);
	data->sprites->player = mlx_xpm_file_to_image(data->mlx,
			"./sprites/player.xpm", &i, &j);
	data->sprites->gift = mlx_xpm_file_to_image(data->mlx,
			"./sprites/gift.xpm", &i, &j);
	data->sprites->exit = mlx_xpm_file_to_image(data->mlx,
			"./sprites/exit.xpm", &i, &j);
}

int	load_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->rows)
	{
		x = 0;
		while (x < data->map->cols)
		{
			put_image(data, data->map->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	put_image(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites->walls, x * 32, y * 32);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites->gift, x * 32, y * 32);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites->exit, x * 32, y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->sprites->floor, x * 32, y * 32);
	mlx_put_image_to_window(data->mlx, data->win,
		data->sprites->player, data->map->player_x * 32,
		data->map->player_y * 32);
}
