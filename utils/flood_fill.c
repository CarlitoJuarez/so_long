/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:34:27 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:35:06 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_point	find_elem_1(int count, t_data data, char c)
{
	int		i;
	int		j;
	int		test;
	t_point	coord;

	i = 0;
	test = data.mystery - count;
	if (c == 'P')
		test = 0;
	coord.y = 0;
	coord.x = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == c && test == 0)
				return (coord.x = j, coord.y = i, coord);
			else if (data.map[i][j] == c)
				test--;
			j++;
		}
		i++;
	}
	return (coord);
}

int	check_char(char c)
{
	if (c == 'c' || c == 'p' || c == 'o'
		|| c == '1' || c == 'E')
		return (1);
	return (0);
}

void	mark(char **map, t_point cur, int *found, char c)
{
	if (c == 'P')
	{
		if (map[cur.y + 1][cur.x] == 'E' || map[cur.y - 1][cur.x] == 'E'
			|| map[cur.y][cur.x + 1] == 'E' || map[cur.y][cur.x - 1] == 'E')
			*found = 1;
	}
	else if (c == 'C')
	{
		if (map[cur.y + 1][cur.x] == 'P' || map[cur.y - 1][cur.x] == 'P'
			|| map[cur.y][cur.x + 1] == 'P' || map[cur.y][cur.x - 1] == 'P')
			*found = 1;
	}
	if (*found == 1)
		return ;
	if (map[cur.y][cur.x] == 'C')
		map[cur.y][cur.x] = 'c';
	else if (map[cur.y][cur.x] == 'P')
		map[cur.y][cur.x] = 'p';
	else if (map[cur.y][cur.x] == '0')
		map[cur.y][cur.x] = 'o';
}

void	fill(char **map, t_point cur, char c, int *found)
{
	t_point	size;

	size.y = count_this_2(map);
	size.x = count_this(*map);
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || check_char(map[cur.y][cur.x])
		|| *found == 1)
		return ;
	mark(map, cur, found, c);
	fill(map, (t_point){cur.x - 1, cur.y}, c, found);
	fill(map, (t_point){cur.x + 1, cur.y}, c, found);
	fill(map, (t_point){cur.x, cur.y - 1}, c, found);
	fill(map, (t_point){cur.x, cur.y + 1}, c, found);
}

int	flood_fill(t_data data)
{
	int		found;
	int		count;
	t_point	begin;

	count = data.mystery;
	begin = find_elem_1(0, data, 'P');
	found = 0;
	fill(data.map, begin, 'P', &found);
	if (!found)
		return (0);
	while (count > 0)
	{
		update_map(data.map);
		begin = find_elem_1(count, data, 'C');
		found = 0;
		fill(data.map, begin, 'C', &found);
		if (!found)
			return (0);
		count--;
	}
	return (1);
}
