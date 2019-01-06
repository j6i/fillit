/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 14:18:36 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 10:58:12 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"
#include <stdlib.h>

t_mino	*fnew_mino(void const *buf, size_t size)
{
	t_mino	*big_boyo;

	if ((big_boyo = malloc(sizeof(*big_boyo))) == 0)
		return (NULL);
	if (buf == 0)
	{
		big_boyo->crd = 0;
		big_boyo->size = 0;
	}
	else
	{
		if ((big_boyo->crd = malloc(size)) == 0)
			return (0);
		big_boyo->crd = ft_strsplit(buf, '\n');
	}
	big_boyo->next = NULL;
	return (big_boyo);
}
