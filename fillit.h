/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:42:25 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/05 20:34:29 by mschroed         ###   ########.fr       */
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
}					t_mino;

t_mino				*mino_oc(char *file);
t_mino				*fnew_mino(void const *data, size_t size);
void				lst_append(t_mino **head, char *buf);
int					val_mino(t_mino *head);
char				**map(int size);
int					place(char **mappie, t_mino *minos, int x, int y);
t_mino				*cuty(t_mino *valid);
t_mino				*cutx(t_mino *valid);
int					solved(t_mino *minos);
int					mino_len(t_mino *lst);

#endif
