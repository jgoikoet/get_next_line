/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:30:11 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/10/03 12:21:38 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*GET_NEXT_LINE*/
//int	main(void);
char	*get_next_line(int fd);
int		ft_line_jump(char *s);
char	*ft_jo(char *s, char *buf, int n);
int		ft_strlen(char *s);

/*GET_NEXT_LINE_UTILS*/
char	*ft_get_s(char *s);
char	*ft_clean_s(char *s);
char	*ft_final_clean(char *s, int k, int j);

#endif