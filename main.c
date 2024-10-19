#include "./so_long.h"

int check_name_ber(char *filename)
{
    int     i;
    char    *file_ext;

    file_ext = filename + ft_strlen(filename) - 4;
    i = ft_strncmp(file_ext, ".ber", 4);
    return (i);

}
int main(int argc, char **argv)
{
    t_data  *data;

    if ((argc != 2) || (check_name_ber(argv[1])))
    {
        write(2, "Error\n", 6);
        write(2, "There is no valid file\n", 23);
        return (1);
    }
    data = ft_calloc(1, sizeof(t_data));
    start_data(data);
    if (!valid_board(argv[1], data))
    {
        write(2, "Error\n", 6);
        write(2, "The Board is invalid\n", 21);
        return (1);
    }
    data->mlx = mlx_init();
    // nao sei se preciso de height e width
	data->height = data->map->rows * 32;
	data->width = data->map->cols * 32;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	load_textures(data);
	load_map(data);
	play_game(data);
	return (0);
}

