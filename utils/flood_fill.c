#include "../so_long.h"

t_point *find_elem_1(char **map, char c)
{
    int i;
    int j;
    t_point *coord;

    i = 0;
    coord = malloc(sizeof(t_point) * 1);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                return (coord->x = j, coord->y = i, coord);
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

void fill(char **map, t_point cur, t_point size, int *found)
{
    t_point left = {cur.x - 1, cur.y};
    t_point right = {cur.x + 1, cur.y};
    t_point up = {cur.x, cur.y - 1};
    t_point down = {cur.x, cur.y + 1};


    if (cur.y < 0 || cur.y >= size.y || cur.x < 0
    || cur.x >= size.x || check_char(map[cur.y][cur.x])
    || *found == 1)
		return;
    if (map[cur.y][cur.x] == 'E')
        *found = 1;
    else if (map[cur.y][cur.x] == 'C')
        map[cur.y][cur.x] = 'c';
    else if (map[cur.y][cur.x] == 'P')
        map[cur.y][cur.x] = 'p';
    else if (map[cur.y][cur.x] == '0')
        map[cur.y][cur.x] = 'o';
    fill(map, left, size, found);
    fill(map, right, size, found);
    fill(map, up, size, found);
    fill(map, down, size, found);
}

int flood_fill(t_data data)
{
    int found;
    t_point size;
    t_point begin;

    begin = *find_elem_1(data.map, 'P');
    size.x = count_this_2(data.map);
    size.y = count_this(data.map[0]);
    found = 0;
    fill(data.map, begin, size, &found);
    if (found)
        return (1);
    return (0);
}