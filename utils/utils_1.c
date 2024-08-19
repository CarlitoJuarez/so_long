#include "../so_long.h"

void    update_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'c')
                map[i][j] = 'C';
            else if (map[i][j] == 'o')
                map[i][j] = '0';
            else if (map[i][j] == 'p')
                map[i][j] = 'P';
            j++;
        }
        i++;
    }
}

int count_this(char *s)
{
    int count;

    count = 0;
    while (s[count] && s[count] != '\n')
        count++;
    printf("COUNT1: %d\n", count);
    return (count);
}

int count_this_2(char **arr)
{
    int j;

    j = 0;
    while (arr[j])
        j++;
    printf("J:%d\n", j);
    return (j);
}

int count_this_3(int fd)
{
    char *line;
    int count;

    line = get_next_line(fd);
    count = 0;
    while (line)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}

int count_this_4(char *s, t_data *data)
{
    int count;

    count = 0;
    while (s[count] && s[count] != '\n')
    {
        if (s[count] == 'C')
            data->mystery++;
        count++;
    }
    return (count);
}

int open_this(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (EXIT_FAILURE);
    }
    return (fd);
}

char **create_map(int fd, char *file, t_data *data)
{
    int i;
    int j;
    int count;
    char **map;
    char *line;
    
    fd = open_this(file);
    count = count_this_3(fd);
    printf("COUNT: %d\n", count);
    map = malloc(sizeof(char *) * (count + 1));
    map[count] = 0;
    i = 0;
    fd = open_this(file);
    while (--count + 1)
    {
        line = get_next_line(fd);
        printf("LINE: %s$\n", line);
        map[i] = malloc(sizeof(char) * count_this_4(line, data) + 1);
        if (!map[i])
            return (NULL);
        map[i++][count_this(line)] = 0;
        j = 0;
        while (line[j] && line[j] != '\n')
        {
            map[i - 1][j] = line[j];
            j++;
        }
    }
    return (close(fd), map);
}
void	rec_func_2(int n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		rec_func_2(n / 10);
		rec_func_2(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	rec_func_2(n);
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}