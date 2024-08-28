/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:56:22 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:00:24 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# define TILE_SIZE 50
# define BUFFER_SIZE 5

# define WALL "./assets/wall.xpm"
# define EMPTY "./assets/empty.xpm"
# define ME "./assets/me.xpm"
# define EXIT "./assets/exit.xpm"
# define MYSTERY "./assets/mystery.xpm"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];

	char	**map;
	int		mystery;
	int		moves;

}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// MAIN

int		on_destroy(t_data *data);
void	render_map(t_data *data);

// CHECK MAP

void	check_file(char *file);

int		check_map(t_data *data);

// CREATE MAP

char	**create_map(int fd, char *file);

// FLOOD FILL

int		flood_fill(t_data data);

// GNL

char	*get_next_line(int fd);

// GNL UTILS

void	free_this(char *str);

size_t	ft_strlen(char const *str);

char	*ft_strchr(char const *str, int c);
char	*ft_strjoin(char *s1, char *s2);

// Make Move

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

// Utils 1

void	update_map(char **map);

int		count_this(char *s);
int		count_this_2(char **arr);
int		ft_putnbr(int num);

// Utils 2

void	set_data(t_data *data, char **argv);
void	free_close_exit(char **map, char *s, int fd, char *err_msg);
char	last_char(char *s);

int		count_close_fd(int fd);
int		on_destroy(t_data *data);

#endif
