#include "so_long.h"

int valid_board(char *ber, t_data *data)
{
	char	**line;
	int		i;

	line = start_lines(&ber, data->map);
    if (!line)
        return (1);
    i = start_map(data->map);
    if (i != 0)
        return (1);
    if (check_wall(line[0]) || check_wall(line[data->map->rows -1]))
		return (1);
    i = 1;
	while (line[i])
	{
		if (check_map_content(line[i], data->map, i))
			return (1);
		i++;
	}
    // o angu de carocota aqui
	//if (data->map->player_x < 1 || data->map->exit < 1
	//	|| data->map->collectibles < 1 || check_reachable(data))
	//	return (1);
	//free_array(line);
	return (0);
}
