/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khagiwar <khagiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 19:53:36 by khagiwar          #+#    #+#             */
/*   Updated: 2021/02/18 00:32:33 by khagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>

typedef enum {
	error = -1,
	end = 0,
	normal = 1,
	ln = 2
}	t_gnl_status_code;

typedef struct	s_gnlist {
	struct s_gnlist		*next;
	char				*str;
	int					fd;
}				t_gnlist;

typedef struct	s_scanner {
	char		*buf;
	int			fd;
	ssize_t		rdsz;
}				t_scanner;

void			remove_gnlist(int fd, t_gnlist **head, t_gnlist *prev);
int				get_next_line(int fd, char **line);
int				ft_strdiv(t_gnlist **store, t_scanner *in, char **line);
void			*my_memccpy(void *dest, const void *src, int c, size_t n);
size_t			my_strlen(const char *s, int c);
int				ft_strjoinln(char **s1, char *s2, char **line_break);
char			*ft_strln(const char *s);
void			*my_memmove(void *dest, const void *src, size_t n);
int				ft_close(t_gnlist **store, char **line,
				t_scanner *in, int status);

#endif
