/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:02:40 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/06 21:24:26 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"
#include <stdlib.h>

void	usage(void)
{
	ft_putstr("usage: fillit input_file\n");
	exit (-1);
}

int		error(void)
{
	ft_putstr("error\n");
	exit (-1);
}

int		main(int argc, char **argv)
{
	t_mino	*minos;

	if (argc == 2)
	{
		if ((minos = mino_oc(argv[1])) == 0)
			return (error());
		if (val_mino(minos) == -1)
			return (error());
		if (solved(minos) == 0)
			return (error());
	}
	else
		usage();
	return (0);
}
