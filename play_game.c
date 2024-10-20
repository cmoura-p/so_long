/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 22:43:58 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	play_game(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 17, 1L << 17, handle_window, data);
	mlx_hook(data->win, 22, 1L << 0, resize, data);
	mlx_loop(data->mlx);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_window(data);
	if (keycode == 119 || keycode == 65362)
		walk(data, data->map->player_y - 1, data->map->player_x);
	if (keycode == 97 || keycode == 65361)
		walk(data, data->map->player_y, data->map->player_x - 1);
	if (keycode == 115 || keycode == 65364)
		walk(data, data->map->player_y + 1, data->map->player_x);
	if (keycode == 100 || keycode == 65363)
		walk(data, data->map->player_y, data->map->player_x + 1);
	return (0);
}

int	resize(t_data *data, int width, int height)
{
	data->width = width;
	data->height = height;
	load_map(data);
	return (0);
}

void	walk(t_data *data, int next_y, int next_x)
{
	if (data->map->map[next_y][next_x] == '1')
		return ;
	data->map->moves++;
	ft_printf("Moves: %d\n", data->map->moves);
	if (data->map->map[next_y][next_x] == 'C')
	{
		data->map->collected++;
		data->map->map[next_y][next_x] = '0';
	}
	else if (data->map->map[next_y][next_x] == 'E')
	{
		if (data->map->collected == data->map->gift)
		{
			write(1, "Game Over!\n", 11);
			handle_window(data);
		}
	}
	data->map->player_y = next_y;
	data->map->player_x = next_x;
	load_map(data);
}
