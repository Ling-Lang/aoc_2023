/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:39:44 by jkulka            #+#    #+#             */
/*   Updated: 2023/12/01 12:40:41 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char *ft_strncpy(char *src, char *dst)
{
	int i = 0;
	while(src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}

int get_line_count(int fd)
{
	int len = 1;
	char *tmp = get_next_line(fd);
	if(tmp == NULL)
		return 0;
	while(tmp != NULL)
	{
		tmp = get_next_line(fd);
		if(tmp == NULL)
			break;
		len++;
	}
	return (free(tmp), len);
}

char **read_map(char *path)
{
	char **map;
	char *line;
	int i = 0;
	int fd = open(path, O_RDONLY);
	int fd2 = open(path, O_RDONLY);
	if(fd <= 0)
        exit(1);
	map = malloc(sizeof(char *) * get_line_count(fd) + 1);
	if(!map)
		return NULL;
	line = get_next_line(fd2);
	if(!line)
		return (free(map), NULL);
	map[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	ft_strncpy(line, map[i]);
	i++;
	while (line != NULL)
	{
		line = get_next_line(fd2);
		if(!line)
			break;
		map[i] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
		// printf("\t%s", line);
		ft_strncpy(line, map[i]);
		i++;
	}
	map[i] = NULL;
	return(map);
}