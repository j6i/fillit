/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mino_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:51:56 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 10:31:10 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

t_mino	*mino_cpy(int fd)
{
	int		ret;
	char	*buf;
	t_mino	*head;

	buf = ft_strnew(21);
	head = NULL;
	while ((ret = read(fd, buf, 21)) == 21)
	{
		lst_append(&head, buf);
		ft_strclr(buf);
	}
	if (ret == 20)
	{
		if (head == NULL)
			head = fnew_mino(buf, 20);
		else
			lst_append(&head, buf);
	}
	ft_strdel(&buf);
	if (ret != 20)
		return (0);
	return (head);
}

t_mino	*mino_oc(char *file)
{
	int		fd;
	t_mino	*mino_lst;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	if ((mino_lst = mino_cpy(fd)) == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (mino_lst);
}
