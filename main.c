#include <stdlib.h>
#include "./minilibx-linux/mlx.h"
#include "./so_long.h"

#define WIN_WID 800
#define WIN_HEI 400
#define MLX_ERROR 1

int handle_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit (0);
    return (0);
}
int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
        return(handle_window(data));
    return (0);
}

int change_color(t_data *data)
{
    mlx_string_put(data->mlx, data->win, 300, 200, data->color, "T R Y I N G  Mudanca de  C O R");
    if (data->color == 0xFF0000)
        data->color = 0x00FF00;
    else if (data->color == 0x00FF00)
        data->color = 0x0000FF;
    else
        data->color = 0xFF0000;
    return (0);
}
int main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    data.color = 0xFF0000;
    if (data.mlx == NULL)
    {
        return (MLX_ERROR);
    }
    data.win = mlx_new_window(data.mlx, WIN_WID, WIN_HEI, "B E A U T I F U L");
    if (data.win == NULL)
    {
        mlx_destroy_display(data.mlx);
        free(data.mlx);
        return (MLX_ERROR);
    }
    mlx_hook(data.win, 2, 1L << 0, key_press, &data);
    mlx_hook(data.win, 17, 0, handle_window, &data);
    mlx_loop_hook(data.mlx, change_color, &data);
    mlx_loop(data.mlx);
}

// para compilar sem make, para pequenos testes, usando a minilibx
// gcc main.c -Lminilibx-linux -lmlx -lX11 -lXext -lbsd
