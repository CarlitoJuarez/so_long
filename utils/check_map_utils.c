#include "../so_long.h"

int is_(char c)
{
    if (c == '0' || c == 'C' || c == 'P')
        return (1);
    return (0);
}

int is_1(char c)
{
    if (c == '.' || c == ',' || c == 'p')
        return (1);
    return (0);
}

int is_2(char c)
{
    if (c == '.' || c == ',' || c == 'p')
        return (1);
    return (0);
}

int is_4(char c)
{
    if (c == 'C')
        return (1);
    return (0);
}

int is_3(char c)
{
    if (c == ':' || c == ';' || c == 'p')
        return (1);
    return (0);

}