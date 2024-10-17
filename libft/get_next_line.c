/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:27:30 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/10/17 19:53:12 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extract(char *str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = (char *)ft_calloc((i + 1), sizeof(char));
	s[i] = 0;
	while (i-- > 0)
		s[i] = str[i];
	return (s);
}

char	*get_next_line(int fd)
{
	static char	segment[BUFFER_SIZE + 1];

	auto char *piece = NULL;
	auto char *line = NULL;
	auto int size = 1;
	if (fd < 0)
		return (NULL);
	if (!segment[0])
		size = read(fd, segment, BUFFER_SIZE);
	while (size > 0)
	{
		piece = ft_extract(segment);
		line = ft_getjoin(line, piece);
		ft_getcpy(segment);
		if (ft_getchr(line, '\n'))
			return (line);
		size = read(fd, segment, BUFFER_SIZE);
	}
	if (size < 0)
	{
		if (line)
			free(line);
		line = NULL;
	}
	return (line);
}
/*
int	main(void)
{
	int		fd;
	int		flag;
	char	*line;
	flag = 1;
	fd = open("getnl0.txt", O_RDONLY);
	while (flag)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
			flag = 0;
	}
	close(fd);
	return (0);
}
 */
