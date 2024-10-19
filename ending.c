#include "so_long.h"

int handle_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit (0);
    return (0);
}
