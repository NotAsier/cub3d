/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:21:27 by aarranz-          #+#    #+#             */
/*   Updated: 2024/03/26 13:58:49 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *s, int fd)
{
	char	*buf;
	int		r;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r = 1;
	while (gnl_strchr(s, '\n') == NULL && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[r] = '\0';
		s = gnl_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*change_the_static(char *s)
{
	char	*news;
	size_t	i;
	size_t	l;

	l = 0;
	while (s[l] != '\n' && s[l] != '\0')
		l++;
	if (gnl_strlen(s) == l)
	{
		free(s);
		return (NULL);
	}
	news = (char *)malloc((gnl_strlen(s) - l + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	i = 0;
	while (s[l++])
	{
		news[i] = s[l];
		i++;
	}
	news[i] = '\0';
	free(s);
	return (news);
}

char	*get_line(char *res)
{
	char	*line;
	size_t	l;
	size_t	i;

	l = 0;
	if (res[0] == '\0')
		return (NULL);
	while (res[l] != '\n' && res[l] != '\0')
		l++;
	if (res[l] == '\n')
		l++;
	line = (char *)malloc(sizeof(char) * l + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(s, fd);
	if (s == NULL)
		return (NULL);
	buf = get_line(s);
	s = change_the_static(s);
	return (buf);
}

/*int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");
	printf("%s", get_next_line(fd));
	printf("------\n");


	close(fd);
}*/
