/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:55:22 by yotsubo           #+#    #+#             */
/*   Updated: 2022/09/05 15:55:24 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

ssize_t	ft_strclen(const char *str, char c);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c);

char	*next_store(char *store);

char	*make_res(char *store);

char	*store_line(int fd, char *store);

char	*get_next_line(int fd);

#endif
