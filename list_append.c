/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 20:41:16 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/02 11:21:47 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <libft.h>

void	lst_append(t_mino **head, char *buf)
{
	t_mino	*new_mino;
	t_mino	*last;

	last = *head;
	new_mino = fnew_mino(buf, 21);
	if (*head == NULL)
	{
		*head = fnew_mino(buf, 21);
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_mino;
}
