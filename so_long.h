/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:13:52 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/20 18:45:11 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

#define MLX_ERROR 1

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		exit;
	int		gift;
	int		collected;
	int		moves;
}	t_map;

typedef struct s_sprites
{
	void	*walls;
	void	*floor;
	void	*player;
	void	*gift;
	void	*exit;
}	t_sprites;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
    t_sprites	*sprites;
	t_map		*map;
}	t_data;


// checking.c
int     check_name_ber(char *filename);
int     board_invalid(char *ber, t_data *data);
int     check_wall(char *line);
int     check_map_content(char *line, t_map *map, int n_line);
int	    check_access(t_data *data);

// flowing.c
char    **copy_map(char **map, int rows);
int     is_acessible(t_data *data, char **temp_map, int x, int y);
int     aux_flow(t_data *data, char **temp_map, int x, int y);


// ending.c
void	destroy_sprites(t_data *data);
void    handle_close(t_data *data);
int     handle_window(t_data *data);
void    free_map(char **matrix);

// loading_map.c
void	load_sprites(t_data *data);
int     load_map(t_data *data);
void	put_image(t_data *data, char c, int x, int y);

// starting.c
int     counter_field(int fd);
void    start_data(t_data *data);
char    **start_lines(char **ber, t_map *map);
int	    start_map(t_map *map);

// utils.c
void	add_wall(int row, int col, t_map *map);
void	add_gift(int row, int col, t_map *map);
void	add_exit(int row, int col, t_map *map);
void	add_player(int row, int col, t_map *map);
void	add_floor(int row, int col, t_map *map);

// play_game.c
void	play_game(t_data *data);
int     key_press(int keycode, t_data *data);
int     resize(t_data *data, int width, int height);
void    walk(t_data *data, int next_y, int next_x);

#endif
