/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:42:25 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 18:46:07 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# define MINO_SIZE 26

typedef struct		s_mino
{
	struct s_mino	*next;
	size_t			size;
	char			**crd;
	int				id;
}					t_mino;

typedef struct		s_map
{
	char			**map;
	int				size;
}					t_map;

t_mino				*mino_oc(char *file);
t_mino				*fnew_mino(void const *data, size_t size);
void				lst_append(t_mino **head, char *buf);
int					val_mino(t_mino *head);
char				**map(int size);
int					place(t_map *mappie, t_mino *minos, int x, int y);
int					solved(t_mino *minos);
int					mino_len(t_mino *lst);
t_mino				*cuter(t_mino *valid, int id);
int					piece_reset(t_map *mappie, t_mino *mino, int x, int y);
int					placer(t_map *mappie, t_mino *mino, int x, int y);
int					map_check(t_map *mappie, t_mino *mino);
t_map				*map_new(int size);
void				printn2d(char **s, size_t num);

#endif
