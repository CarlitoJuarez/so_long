/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:42:20 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:42:57 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map && map[i] && map[i][j])
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

int	count_this(char *s)
{
	int	count;

	count = 0;
	while (s && s[count] && s[count] != '\n')
		count++;
	return (count);
}

int	count_this_2(char **arr)
{
	int	j;

	j = 0;
	while (arr && arr[j])
		j++;
	return (j);
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
