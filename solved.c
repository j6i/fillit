/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:17:28 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/06 11:01:16 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

int		solved(t_mino *minos)
{
	int		solver;
	int		size;
	char	**mappie;
	int		x;
	int		y;

	size = 2;
	solver = 0;
	x = 0;
	y = 0;
	while (solver == 0)
	{
		mappie = map(size);
		solver = place(mappie, minos, x, y);
		//free(mappie);
		size++;
	}
	return (1);
}
