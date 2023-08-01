/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:52:02 by shimakaori        #+#    #+#             */
/*   Updated: 2022/11/09 12:08:19 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_save(char *save, int fd);
static char	*get_line(char *save);
static char	*get_save_end(char *save);

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > BUF_MAX)
		return (NULL);
	line = NULL;
	if (!save)
	{
		save = gnl_strdup("");
		if (!save)
			return (NULL);
	}
	save = get_save(save, fd);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = get_save_end(save);
	return (line);
}

static char	*get_save(char *save, int fd)
{
	int		filesize;
	char	*buf;

	filesize = 1;
	buf = gnl_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (gnl_strchr(save, '\n') == NULL && filesize != 0)
	{
		filesize = read(fd, buf, BUFFER_SIZE);
		if (filesize == -1)
		{
			free(save);
			free(buf);
			return (NULL);
		}
		buf[filesize] = '\0';
		save = gnl_strjoin(save, buf);
	}
	free (buf);
	return (save);
}

static char	*get_line(char *save)
{
	size_t	i;
	char	*line;

	i = 0;
	if (save[0] == '\0')
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
		i++;
	line = gnl_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		line[i] = save[i];
		if (save[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (line);
}

static char	*get_save_end(char *save)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (gnl_strlen(save) == i)
	{
		free(save);
		return (NULL);
	}
	if (save[i] == '\n')
		i++;
	tmp = gnl_strdup(&save[i]);
	if (!tmp)
		return (NULL);
	free(save);
	return (tmp);
}

// int	main(int argc, char *argv[])
// {
// 	int		index;
// 	int		fd;
// 	char	*receiver;

// 	if (argc < 2)
// 		fd = STDIN_FILENO;		
// 	else
// 		fd = open(argv[1], O_RDONLY);	
// 	//close(fd);
// 	receiver = NULL;
// 	index = 0;
// 	while (1)
// 	{
// 		receiver = get_next_line(fd);
// 		if (!receiver)
// 		{
// 			printf("EOF or ERROR\n");
// 			break ;
// 		}
// 		printf("[%d]%s", index, receiver);
// 		index ++;
// 		free(receiver);
// 	}
// 	system("leaks -q a.out");
// 	close(fd);
// }
