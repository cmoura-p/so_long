#include <stdlib.h>
#include "./minilibx-linux/mlx.h"

#define WIN_WID 800
#define WIN_HEI 400
#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int handle_window(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit (0);
    return (0);
}
int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
        return(handle_window(data));
    return (0);
}

int change_color(t_data data)
{
    int color = 0xFF0000;
    mlx_string_put(data.mlx_ptr, data.win_ptr, 150, 150, color, "Mudando a  C O R");
    if (color == 0xFF0000)
        color = 0x00FF00;
    else if (0x00FF00)
        color = 0x0000FF;
}
int main(void)
{
    t_data  data;

    /* data = (t_data *)malloc(sizeof(data));
    if (data == NULL)
        return (MLX_ERROR); */
    data.mlx_ptr = mlx_init();
    if (data.mlx_ptr == NULL)
    {
        //free(data);
        return (MLX_ERROR);
    }
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WID, WIN_HEI, "B E A U T I F U L");
    if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (MLX_ERROR);
    }
    mlx_hook(data.win_ptr, 2, 1L << 0, key_press, &data);
    mlx_hook(data.win_ptr, 17, 0, handle_window, &data);
    mlx_loop_hook(data.mlx_ptr, change_color, &data);
    mlx_loop(data.mlx_ptr);
}

// para compilar sem make, para pequenos testes, usando a minilibx
// gcc main.c -Lminilibx-linux -lmlx -lX11 -lXext -lbsd
