#include "../so_long.h"

static char	*create_substring(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str)
		return (free(str), NULL);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (*(str + i) == '\n')
		i++;
	new_str = (char *)malloc((ft_strlen(str) - i) + 1);
	if (!new_str)
		return (NULL);
	while (*(str + i))
		*(new_str + j++) = *(str + i++);
	*(new_str + j) = '\0';
	if (!*new_str)
		return (free(str), free(new_str), NULL);
	free(str);
	return (new_str);
}

static char	*read_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || *str == '\0')
		return (NULL);
	while (*(str + i) && *(str + i) != '\n')
		i++;
	if (*(str + i) == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (*(str + i) && *(str + i) != '\n')
	{
		*(line + i) = *(str + i);
		i++;
	}
	if (*(str + i) == '\n')
	{
		*(line + i) = *(str + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}

void	check_buf(char *buf)
{
	if (buf)
		free(buf);
}

char	*get_next_line(int fd)
{
	char		*read_content;
	int			read_bytes;
	static char	*read_buffer;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (check_buf(read_buffer), NULL);
	read_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_content)
		return (NULL);
	while (!(ft_strchr(read_buffer, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, read_content, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(read_content), free(read_buffer), read_buffer = NULL, NULL);
		*(read_content + read_bytes) = '\0';
		read_buffer = ft_strjoin(read_buffer, read_content);
	}
	free(read_content);
	read_content = read_line(read_buffer);
	read_buffer = create_substring(read_buffer);
	return (read_content);
}
// int main(void)
// {
//     int     fd;
//     char    *line;

//     // Open a file in read-only mode
//     fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (EXIT_FAILURE);
//     }

//     // Read and print each line from the file
//     line = get_next_line(fd);
//     while (line != NULL)
//     {
//         printf("%s", line);
//         free(line); // Free the line after printing
//         line = get_next_line(fd); // Read the next line
//     }

//     // Close the file
//     close(fd);
//     return (EXIT_SUCCESS);
// }