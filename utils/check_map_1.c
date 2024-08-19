#include "../so_long.h"


void mark_3(char **map, int *coord)
{
    if (map[coord[0]][coord[1]] == '.')
        map[coord[0]][coord[1]] = ':';
    else if (map[coord[0]][coord[1]] == ',')
        map[coord[0]][coord[1]] = ';';
    else if (map[coord[0]][coord[1]] == 'p')
        map[coord[0]][coord[1]] = '*';
}

void mark(char **map, int *coord)
{
    if (map[coord[0]][coord[1]] == '0')
        map[coord[0]][coord[1]] = '.';
    else if (map[coord[0]][coord[1]] == 'M')
        map[coord[0]][coord[1]] = ',';
    else if (map[coord[0]][coord[1]] == 'P')
        map[coord[0]][coord[1]] = 'p';
}

void mark_4(char **map, int *coord)
{
    if (map[coord[0]][coord[1]] == 'C')
        map[coord[0]][coord[1]] = ',';
}


int check_move(int *from, int *cur, char **map)
{
    printf("1\n");
    if (is_(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("\n\nRIGHT\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    else if (is_(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("\n\nDOWN\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("\n\nLEFT\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("\n\nUP\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    return (0);
}

int check_move_1(int *from, int *cur, char **map)
{
    printf("2\n"); 
    if (is_(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("\n\nUP\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    else if (is_(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("\n\nLEFT\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("\n\nDOWN\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("\n\nRIGHT\n\n");
        mark(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    return (0);
}

int check_move_2(int *from, int *cur, char **map)
{
    printf("3\n");
    if (is_1(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("\n\nRIGHT\n\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    else if (is_1(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("\n\nDOWN\n\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_1(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("\n\nLEFT\n\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_1(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("\n\nUP\n\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    return (0);
}

int check_move_3(int *from, int *cur, char **map)
{
    printf("4\n");
    if (is_1(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("UP\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    else if (is_1(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("LEFT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_1(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("DOWN\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_1(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("RIGHT\n");
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    return (0);
}

int check_move_4(int *from, int *cur, char **map)
{
    printf("1\n");
    if (is_4(map[cur[0]][cur[1] + 1]) && from[1] != cur[1] + 1)
    {
        printf("\n\nRIGHT\n\n");
        mark_4(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[1] += 1, 1);
    }
    else if (is_4(map[cur[0] + 1][cur[1]]) && from[0] != cur[0] + 1)
    {
        printf("\n\nDOWN\n\n");
        mark_4(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[0] += 1, 1);
    }
    else if (is_4(map[cur[0]][cur[1] - 1]) && from[1] != cur[1] - 1)
    {
        printf("\n\nLEFT\n\n");
        mark_4(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[1] -= 1, 1);
    }
    else if (is_4(map[cur[0] - 1][cur[1]]) && from[0] != cur[0] - 1)
    {
        printf("\n\nUP\n\n");
        mark_4(map, cur);
        return (from[0] = cur[0], from[1] = cur[1], cur[0] -= 1, 1);
    }
    return (0);
}


