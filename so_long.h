#ifndef SO_LONG_FH
# define SO_LONG_FH

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <stdarg.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# define TILE_SIZE 50
# define BUFFER_SIZE 10

# define WALL "./assets/wall.xpm"
# define EMPTY "./assets/empty.xpm"
# define ME "./assets/me.xpm"
# define EXIT "./assets/exit.xpm"
# define MYSTERY "./assets/mystery.xpm"


typedef struct s_img
{
    void    *img_ptr;
    int    *img_pixels_ptr;

    int     bits_pp;
    int     endian;
    int     line_len;
}   t_img;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *textures[5];

    char    **map;
    int     mystery;
    int     moves;

    t_img   img;
}   t_data;

typedef struct s_point
{
    int x;
    int y;
} t_point;

// Make Move

void    move_up(t_data *data);
void    move_down(t_data *data);
void    move_left(t_data *data);
void    move_right(t_data *data);
void    find_elem(int **coord, t_data data, char c, int alrdy);

// Utils 1

char    **create_map(int fd, char *file, t_data *data);

int     count_this(char *s);
int     count_this_2(char **arr);

int     ft_putnbr(int num);


// CHECK MAP

void update_map(char **map);

int check_map(t_data data);

int flood_fill(t_data data);


// CHECK MAP 1

int check_move(int *from, int *cur, char **map);
int check_move_1(int *from, int *cur, char **map);
int check_move_2(int *from, int *cur, char **map);
int check_move_3(int *from, int *cur, char **map);
int check_move_4(int *from, int *cur, char **map);

void mark(char **map, int *coord);

// CHECK MAP UTILS

int     is_(char c);
int     is_1(char c);
int     is_4(char c);
int     is_3(char c);

void mark_3(char **map, int *coord);

// MAIN

int     on_destroy(t_data *data);
void    render_map(t_data *data);

// GNL

char	*get_next_line(int fd);

// GNL UTILS

char	*ft_strchr(char const *str, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char const *src);
char	*ft_strjoin(char *buffer, const char *content);
size_t	ft_strlen(char const *str);



#endif