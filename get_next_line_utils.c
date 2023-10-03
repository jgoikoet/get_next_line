/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:13:39 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/03 12:44:45 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_final_clean(char *s, int k, int j)
{
	int		i;
	char	*str;

	i = 0;
	if (j > 0)
	{
		i = 0;
		str = (char *) malloc (sizeof(char) * (j + 1));
		while (s[k])
			str[i++] = s[k++];
		str[i] = '\0';
		return (free(s), s = NULL, str);
	}
	else
		return (free(s), s = NULL, NULL);
}

char	*ft_clean_s(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (free(s), s = NULL, NULL);
	if (!ft_line_jump(s))
		return (NULL);
	i = 0;
	while (s[i] != '\n')
		i++;
	i++;
	k = i;
	j = 0;
	while (s[i++] != '\0')
		j++;
	str = ft_final_clean(s, k, j);
	return (str);
}

char	*ft_get_s(char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (free (s), s = NULL, NULL);
	if (!ft_line_jump(s))
		return (s);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *) malloc (sizeof(char) * (i + 2));
	i = 0;
	while (s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = s[i];
	str[i + 1] = '\0';
	return (str);
}
