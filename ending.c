/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 22:29:54 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_sprites(t_data *data)
{
	if (data->sprites->walls)
		mlx_destroy_image(data->mlx, data->sprites->walls);
	if (data->sprites->floor)
		mlx_destroy_image(data->mlx, data->sprites->floor);
	if (data->sprites->player)
		mlx_destroy_image(data->mlx, data->sprites->player);
	if (data->sprites->gift)
		mlx_destroy_image(data->mlx, data->sprites->gift);
	if (data->sprites->exit)
		mlx_destroy_image(data->mlx, data->sprites->exit);
}

void	handle_close(t_data *data)
{
	get_next_line(-1);
	if (!data)
		return ;
	if (data->map)
	{
		if (data->map->map)
			free_map(data->map->map);
		free(data->map);
	}
	if (data->sprites)
		free(data->sprites);
	free(data);
}

int	handle_window(t_data *data)
{
	destroy_sprites(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	handle_close(data);
	exit(0);
}

void	free_map(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	if (matrix)
	{
		i = 0;
		while (matrix[i])
		{
			free(matrix[i]);
			matrix[i] = NULL;
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}
