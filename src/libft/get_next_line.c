/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:38:40 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/02 20:06:46 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_take_line(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_hold_line(char *temp)
{
	char	*str;
	int		i;
	int		z;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_strlen(temp) - i + 1));
	if (!str)
		return (NULL);
	i++;
	z = 0;
	while (temp[i])
		str[z++] = temp[i++];
	str[z] = '\0';
	free(temp);
	return (str);
}

char	*ft_read_line_and_save(int fd, char *temp)
{
	char	*buffer;
	int		count_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	count_bytes = 1;
	while (!gnl_strchr(temp, '\n') && count_bytes != 0)
	{
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count_bytes] = '\0';
		temp = gnl_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	temp = ft_read_line_and_save(fd, temp);
	if (!temp)
		return (NULL);
	line = ft_take_line(temp);
	temp = ft_hold_line(temp);
	return (line);
}
