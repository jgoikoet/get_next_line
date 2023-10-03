/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:29:35 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/03 12:54:27 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_jo(char *s, char *buf, int n)
{
	int		i;
	int		j;
	char	*str;

	if (!s && n == 0)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s) + n + 1));
	i = 0;
	j = 0;
	if (s)
	{
		while (s[i])
			str[j++] = s[i++];
	}
	i = 0;
	while (i < n)
		str[j++] = buf[i++];
	str[j] = '\0';
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (str);
}

int	ft_line_jump(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			n;
	char		buf[BUFFER_SIZE + 1];
	char		*str;
	static char	*s = NULL;

	while (1)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			if (s)
			{
				free(s);
				s = NULL;
			}
			return (NULL);
		}
		buf[n] = '\0';
		if (n == 0 || n < BUFFER_SIZE)
			break ;
		if (ft_line_jump(buf))
			break ;
		s = ft_jo(s, buf, n);
	}
	return (s = ft_jo(s, buf, n), str = ft_get_s(s), s = (ft_clean_s(s)), str);
}

/* int	main(void)
{
	int	fd;
	char	*s;

	fd = open ("read_error.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	
} */
