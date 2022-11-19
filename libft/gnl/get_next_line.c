/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:03:21 by yotsubo           #+#    #+#             */
/*   Updated: 2022/09/09 17:42:33 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define NUM_OF_FD 256
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*next_store(char *store)
{
	size_t	head;
	size_t	tail;
	char	*next_store;

	next_store = NULL;
	head = gnl_strclen(store, '\n') + 1;
	tail = gnl_strclen(store, '\0');
	if (head != 1)
		next_store = gnl_substr(store, head, tail - head);
	free(store);
	return (next_store);
}

char	*make_res(char *store)
{
	char	*res;
	size_t	res_size;

	res = NULL;
	if (gnl_strchr(store, '\n'))
		res_size = gnl_strclen(store, '\n') + 1;
	else
		res_size = gnl_strclen(store, '\0');
	res = gnl_substr(store, 0, res_size);
	return (res);
}

char	*store_line(int fd, char *store)
{
	ssize_t		read_size;
	static char	cut_out[BUFFER_SIZE + 1lu + 1];
	char		*tmp;

	read_size = 1;
	while (!(gnl_strchr(store, '\n')) && read_size > 0)
	{
		read_size = read(fd, cut_out, BUFFER_SIZE);
		if (read_size == -1)
			break ;
		cut_out[read_size] = '\0';
		tmp = gnl_strjoin(store, cut_out);
		free(store);
		store = tmp;
	}
	if (read_size == -1 || (store && !store[0] && read_size == 0))
	{
		free(store);
		return (NULL);
	}
	return (store);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*store;

	res = NULL;
	if (fd < 0 || fd > NUM_OF_FD || BUFFER_SIZE <= 0)
		return (NULL);
	store = store_line(fd, store);
	if (!store)
		return (NULL);
	res = make_res(store);
	if (!res)
	{
		free(store);
		return (NULL);
	}
	store = next_store(store);
	if (!store)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
/*
int main()
{
	int fd;
	char *line;
	
	fd = open("file/test.txt", O_RDONLY);
	while ((line = get_next_line(fd))> 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	while (1){};
	return (0);
}
*/
