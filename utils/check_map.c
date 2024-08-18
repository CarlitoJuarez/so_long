#include "../so_long.h"

int is_(char c)
{
    if (c == ' ' || c == 'M' || c == 'P')
        return (1);
    return (0);
}

int is_1(char c)
{
    if (c == '.' || c == ',' || c == 'p')
        return (1);
    return (0);
}

int check_end(int *cur, char **map)
{
    if (map[cur[0]][cur[1] + 1] == 'E')
        return (1);
    else if (map[cur[0] + 1][cur[1]] == 'E')
        return (1);
    else if (map[cur[0]][cur[1] - 1] == 'E')
        return (1);
    else if (map[cur[0] - 1][cur[1]] == 'E')
        return (1);
    return (0);
}


int check_move_1(int *from, int *cur, char **map)
{
    // int *from;
    // int *cur;

    // from = *from_;
    // cur = *cur_;
    // printf("2FROM: %d | %d\n", from[0], from[1]);
    // printf("2 TO: %d | %d\n", cur[0], cur[1]);
    printf("2\n");
    if (map[cur[0]][cur[1]] == 'M')
        map[cur[0]][cur[1]] = ',';
    if (map[cur[0]][cur[1]] == 'P')
        map[cur[0]][cur[1]] = 'p';
    if (is_(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("UP\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    else if (is_(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("LEFT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("DOWN\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("RIGHT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    return (0);
}
// void update_both(int *from, int *cur, int y, int x)
// {
//     int i;
//     int j;

//     i = cur[0];
//     j = cur[1];
//     if (!y && x)


// }

int check_move(int *from, int *cur, char **map)
{
    // int *from;
    // int *cur;

    // from = *from_;
    // cur = *cur_;
    if (map[cur[0]][cur[1]] == 'M')
        map[cur[0]][cur[1]] = ',';
    if (map[cur[0]][cur[1]] == 'P')
        map[cur[0]][cur[1]] = 'p';
    printf("1\n");
    if (is_(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("RIGHT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    else if (is_(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("DOWN\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("LEFT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("UP\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    return (0);
}

int check_move_2(int *from, int *cur, char **map)
{
    // int *from;
    // int *cur;

    // from = *from_;
    // cur = *cur_;
    if (map[cur[0]][cur[1]] == 'M')
        map[cur[0]][cur[1]] = ',';
    if (map[cur[0]][cur[1]] == 'P')
        map[cur[0]][cur[1]] = 'p';
    printf("3\n");
    if (is_1(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("RIGHT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    else if (is_1(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("DOWN\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_1(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("LEFT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_1(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("UP\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    return (0);
}
int check_move_3(int *from, int *cur, char **map)
{
    // int *from;
    // int *cur;

    // from = *from_;
    // cur = *cur_;
    if (map[cur[0]][cur[1]] == 'M')
        map[cur[0]][cur[1]] = ',';
    if (map[cur[0]][cur[1]] == 'P')
        map[cur[0]][cur[1]] = 'p';
    printf("4\n");
    if (is_1(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("RIGHT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    else if (is_1(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("DOWN\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_1(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("LEFT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_1(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("UP\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    return (0);
}

int try_right(int *from, int *cur, char **map, int *tries)
{
    int i;

    i = 0;
    printf("_____________TRIES: %d\n", *tries);
    printf("FROM: %d | %d\n", from[0], from[1]);
    printf("  TO: %d | %d\n", cur[0], cur[1]);
    if (check_end(cur, map))
        return (1);
    (*tries)--;
    if (check_move(from, cur, map) && *tries > 0)
    {
        if (map[from[0]][from[1]] != 'M' && map[from[0]][from[1]] != ',' && map[from[0]][from[1]] != 'p')
            map[from[0]][from[1]] = '.';
        i += try_right(from, cur, map, tries);
    }
    else if (check_move_1(cur, from, map) && *tries > 0)
    {
        if (map[from[0]][from[1]] != 'M' && map[from[0]][from[1]] != ',' && map[from[0]][from[1]] != 'p')
            map[from[0]][from[1]] = '.';
        i += try_right(cur, from, map, tries);
    }
    else if (check_move_2(from, cur, map) && *tries > 0)
    {
        i += try_right(from, cur, map, tries);
    }
    else if (check_move_3(cur, from, map) && *tries > 0)
    {
        i += try_right(cur, from, map, tries);
    }
    else
        return (0);
    return (i);
}

int real_check (char **map, t_data data)
{
    int *coord;
    int *coord1;
    int tries;

    coord = malloc(sizeof(int) * 2);
    coord1 = malloc(sizeof(int) * 2);
    coord[0] = 0;
    coord[1] = 0;
    coord1[0] = 0;
    coord1[1] = 0;
    find_elem(&coord, data, 'P', -1);
    coord1[0] = coord[0];
    coord1[1] = coord[1];
    tries = 300;
    if (try_right(coord1, coord, map, &tries))
        return (1);
    return (0);
}

int real_check_2 (char **map, t_data data)
{
    int *coord;
    int *coord1;
    int count;
    int tries;

    coord = malloc(sizeof(int) * 2);
    coord1 = malloc(sizeof(int) * 2);
    coord[0] = 0;
    coord[1] = 0;
    coord1[0] = 0;
    coord1[1] = 0;
    count = data.mystery;
    while (count)
    {
        printf("----------------COUNT: %d\n", count);
        find_elem(&coord, data, 'M', count);
        coord1[0] = coord[0];
        coord1[1] = coord[1];
        tries = 300;
        if (try_right(coord1, coord, map, &tries))
            count--;
        else
            return (0);
    }
    return (1);
}

int check_count(char **map)
{
    int i;
    int j;
    int player_exit;

    i = 0;
    player_exit = 0;
    if (!map)
        return (0);
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P' || map[i][j] == 'E')
                player_exit++;
            j++;
        }
        i++;
    }
    if (player_exit != 2)
        return (0);
    return (1);
}

int shape(char **map)
{
    int rows;
    int columns;
    int test;

    test = 0;
    rows = 0;
    while (map[rows])
    {
        if (rows == 0)
        {
            columns = 0;
            while (map[rows][columns])
                columns++;
        }
        else
        {
            test = 0;
            while (map[rows][test])
                test++;
            if (test != columns)
                return (0);
        }
        rows++;
    }        
    return (1);
}

int wall(char **map)
{
    int i;
    int test;

    i = -1;
    test = -1;
    while (map[0][++test])
    {
        if (map[0][test] != '1')
            return (0);
    }
    while (map[++i])
    {
        if (map[i][test - 1] != '1')
            return (0);
    }
    while (map[i - 1][--test])
    {
        if (map[i - 1][test] != '1')
            return (0);
    }
    while (--i >= 0)
    {
        if (map[i][0] != '1')
            return (0);
    }
    return (1);
}

int check_map(t_data data)
{
    if (!(data.mystery))
        return (0);
    if (!(check_count(data.map)))
        return (0);
    if (!shape(data.map))
        return (0);
    if (!wall(data.map))
        return (0);
    if (!real_check(data.map, data))
        return (0);
    printf("YES\n");
    update_map(data.map);
    if (!real_check_2(data.map, data))
        return (0);
    printf("APPROVED!\n");
    return (1);
}