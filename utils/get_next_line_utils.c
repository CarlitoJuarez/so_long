/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:40:23 by cjuarez           #+#    #+#             */
/*   Updated: 2024/08/28 10:40:26 by cjuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_this(char *str)
{
	if (str)
		free(str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

char	*ft_strchr(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

char	*ft_strjoin(char *buffer, char *content)
{
	size_t	content_len;
	char	*result;
	char	*result_ptr;
	char	*src;

	if (!buffer && !content)
		return (NULL);
	content_len = ft_strlen(content);
	if (!content_len && !ft_strlen(buffer))
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(buffer) + content_len + 1));
	if (!result)
		return (free(buffer), NULL);
	src = buffer;
	result_ptr = result;
	while (src && *src)
		*result_ptr++ = *src++;
	src = (char *)content;
	while (src && *src)
		*result_ptr++ = *src++;
	*result_ptr = '\0';
	free(buffer);
	return (result);
}
