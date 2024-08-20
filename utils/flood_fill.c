#include "../so_long.h"

t_point *find_elem_1(int count, t_data data, char c)
{
    int i;
    int j;
    int test;
    t_point *coord;

    i = 0;
    test = data.mystery - count;
    coord = malloc(sizeof(t_point) * 1);
    while (data.map[i])
    {
        j = 0;
        while (data.map[i][j])
        {
            if (data.map[i][j] == c && count == 0)
                return (coord->x = j, coord->y = i, coord);
            else if (data.map[i][j] == c)
                count--;
            j++;
        }
        i++;
    }
    return (coord);
}

int check_char(char c)
{
    if (c == 'c' || c == 'p' || c == 'o')
        return (1);
    return (0);
}

void mark(char **map, t_point cur, int *found)
{
    if (map[cur.y][cur.x] == 'E')
        *found = 1;
    else if (map[cur.y][cur.x] == 'C')
        map[cur.y][cur.x] = 'c';
    else if (map[cur.y][cur.x] == 'P')
        map[cur.y][cur.x] = 'p';
    else if (map[cur.y][cur.x] == '0')
        map[cur.y][cur.x] = 'o';
}

void fill(char **map, t_point cur, t_point size, int *found)
{
    t_point left;
    t_point right;
    t_point up;
    t_point down;
    
    left = {cur.x - 1, cur.y};
    right = {cur.x + 1, cur.y};
    up = {cur.x, cur.y - 1};
    down = {cur.x, cur.y + 1};
    if (cur.y < 0 || cur.y >= size.y || cur.x < 0
        || cur.x >= size.x || check_char(map[cur.y][cur.x])
        || *found == 1)
		return;
    mark(map, cur, found);
    fill(map, left, size, found);
    fill(map, right, size, found);
    fill(map, up, size, found);
    fill(map, down, size, found);
}

int flood_fill(t_data data)
{
    int found;
    int count;
    t_point size;
    t_point begin;

    count = data.mystery;
    begin = *find_elem_1(count, data, 'P');
    size.x = count_this_2(data.map);
    size.y = count_this(data.map[0]);
    found = 0;
    fill(data.map, begin, size, &found);
    free(begin);
    if (!found)
        return (0);
    while (count)
    {
        begin = *find_elem_1(count, data, 'C');
        fill(data.map, begin, size, &found);
        free(begin);
        if (!found)
            return (0);
        count--;
    }
    return (1);
}

