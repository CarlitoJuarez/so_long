#include "so_long.h"

int on_destroy(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
    return (0);
}

void render_map(t_data *data)
{
    int i;
    int j;
    char **map;

    i = 0;
    map = (*data).map;
    while (i < count_this_2(data->map))
    {
        j = 0;
        while (j < count_this(data->map[0]))
        {
            if (map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], j * TILE_SIZE, i * TILE_SIZE);
            else if (map[i][j] == '0')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], j * TILE_SIZE, i * TILE_SIZE);
            else if (map[i][j] == '1')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], j * TILE_SIZE, i * TILE_SIZE);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], j * TILE_SIZE, i * TILE_SIZE);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4], j * TILE_SIZE, i * TILE_SIZE);
            j++;
        }
        i++;    
    }
}

int on_key_press(int keysym, t_data *data)
{
    if (keysym == XK_w)
        move_up(data);
    else if (keysym == XK_a)
        move_left(data);
    else if (keysym == XK_s)
        move_down(data);
    else if (keysym == XK_d)
        move_right(data);
    write(1, "MOVES: ", 7);
    return (ft_putnbr((*data).moves), write(1, "\n", 1), 1);
}

void    map_map(t_data *data)
{
    int tile_size;

    tile_size = TILE_SIZE;

    data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, ME, &tile_size, &tile_size);
    data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, EMPTY, &tile_size, &tile_size);
    data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &tile_size, &tile_size);
    data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, MYSTERY, &tile_size, &tile_size);
    data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &tile_size, &tile_size);
}

    // char *init_map[] = {
    // //   0123456789012
    //     "1111111111111", // 0
    //     "1P1E 1M1   11", // 1
    //     "1 11 1   1 M1", // 2
    //     "1      1  111",//  3
    //     "111111111 111",//  4
    //     "111  MM11 111",//  5
    //     "111111M   111",//  6
    //     "1111111111111",
    //     NULL
    // };

int main(int argc, char **argv)
{
    t_data data;
    char **map;
    
    if (argc == 2)
    {
        data.mystery = 0;
        data.moves = 0;
        map = create_map(0, argv[1], &data);
        update_map(map);
        data.map = map;
        if (!check_map(data))
        {
            printf("INVALID MAP!\n");
            return (1);
        }
        update_map(data.map);
        data.mlx_ptr = mlx_init();
        if (!data.mlx_ptr)
            return (1);
        printf("HURE\n");
        data.win_ptr = mlx_new_window(data.mlx_ptr, count_this(data.map[0]) * TILE_SIZE, count_this_2(data.map) * TILE_SIZE, "so_long");
        if (!data.win_ptr)
            return (free(data.mlx_ptr), 1);
        // load the tiles into the data struct
        map_map(&data);
        // creating a new image
        data.img.img_ptr = mlx_new_image(data.mlx_ptr, count_this(data.map[0]) * TILE_SIZE, count_this_2(data.map) * TILE_SIZE);
        if (!data.img.img_ptr)
            return (1);
        // Filling the img struct with data
        data.img.img_pixels_ptr = (int *)mlx_get_data_addr(data.img.img_ptr, &data.img.bits_pp, &data.img.line_len, &data.img.endian);
        // render_pixels(data);
        render_map(&data);
        // mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
        mlx_key_hook(data.win_ptr, &on_key_press, &data);
        mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
        mlx_loop(data.mlx_ptr);
    }
    return (0);
}
