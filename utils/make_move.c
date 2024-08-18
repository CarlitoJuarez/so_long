#include "../so_long.h"

void find_elem(int **coord, t_data data, char c, int alrdy)
{
    int i;
    int j;
    int count;

    count = data.mystery - alrdy;
    if (alrdy == -1)
        count = 0;
    i = 0;
    while (data.map[i])
    {
        j = 0;
        printf("COUNT: %d\n", count);
        while (data.map[i][j])
        {
            printf("J: %d\n", j);
            printf("I: %d\n", i);
            if (data.map[i][j] == c && count == 0)
            {
                (*coord)[0] = i;
                (*coord)[1] = j;
                printf("HERE_____%d | %d\n",(*coord)[0], (*coord)[1]);
                return ;
            }
            else if (data.map[i][j] == c)
                count--;
            j++;
        }
        i++;
    }
}

void move_up(t_data *data)
{
    int *coord;

    coord = malloc(sizeof(int) * 2);
    coord[0] = 0;
    coord[1] = 0;
    find_elem(&coord, *data, 'P', -1);
    if (data->map[coord[0] - 1][coord[1]] == '1')
        return ;
    else if (data->map[coord[0] - 1][coord[1]] == 'E' && data->mystery)
        return ;
    else if (data->map[coord[0] - 1][coord[1]] == 'E')
    {
        data->moves++;
        on_destroy(data);
    }
    else
    {
        if (data->map[coord[0] - 1][coord[1]] == 'M')
            data->mystery--;
        data->map[coord[0]][coord[1]] = ' ';
        data->map[coord[0] - 1][coord[1]] = 'P'; 
        data->moves++;
        render_map(data);
    }
}

void move_left(t_data *data)
{
    int *coord;

    coord = malloc(sizeof(int) * 2);
    coord[0] = 0;
    coord[1] = 0;
    find_elem(&coord, *data, 'P', -1);
    if (data->map[coord[0]][coord[1] - 1] == '1')
        return ;
    else if (data->map[coord[0]][coord[1] - 1] == 'E' && data->mystery)
        return ;
    else if (data->map[coord[0]][coord[1] - 1] == 'E')
    {
        data->moves++;
        on_destroy(data);
    }
    else
    {
        if (data->map[coord[0]][coord[1] - 1] == 'M')
            data->mystery--;
        data->map[coord[0]][coord[1]] = ' ';
        data->map[coord[0]][coord[1] - 1] = 'P';
        data->moves++;
        render_map(data);
    }
}

void move_down(t_data *data)
{
    int *coord;

    coord = malloc(sizeof(int) * 2);
    coord[0] = 0;
    coord[1] = 0;
    find_elem(&coord, *data, 'P', -1);
    if (data->map[coord[0] + 1][coord[1]] == '1')
        return ;
    else if (data->map[coord[0] + 1][coord[1]] == 'E' && data->mystery)
        return ;
    else if (data->map[coord[0] + 1][coord[1]] == 'E')
    {
        data->moves++;
        on_destroy(data);
    }
    else
    {
        if (data->map[coord[0] + 1][coord[1]] == 'M')
            data->mystery--;
        data->map[coord[0]][coord[1]] = ' ';
        data->map[coord[0] + 1][coord[1]] = 'P'; 
        data->moves++;
        render_map(data);
    }
}

void move_right(t_data *data)
{
    int *coord;

    coord = malloc(sizeof(int) * 2);
    coord[0] = 0;
    coord[1] = 0;
    find_elem(&coord, *data, 'P', -1);
    if ((data)->map[coord[0]][coord[1] + 1] == '1')
        return ;
    else if ((data)->map[coord[0]][coord[1] + 1] == 'E' && (data)->mystery)
        return ;
    else if ((data)->map[coord[0]][coord[1] + 1] == 'E')
    {
        data->moves++;
        on_destroy(data);
    }
    else
    {
        if ((data)->map[coord[0]][coord[1] + 1] == 'M')
            (data)->mystery--;
        (*data).map[coord[0]][coord[1]] = ' ';
        (*data).map[coord[0]][coord[1] + 1] = 'P';
        data->moves++;
        render_map(data);
    }
    printf("hi\n");
}
