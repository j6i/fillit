/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgabelho <jgabelho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:17:28 by jgabelho          #+#    #+#             */
/*   Updated: 2019/01/05 18:11:21 by jgabelho         ###   ########.fr       */
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
	//while (solver == 0)
	//{
	mappie = map(size);
	if ((solver = place(mappie, minos, x, y)) == 0)
		return (0);
	return (1);
	//free(mappie);
	//size++;
	//}
}
