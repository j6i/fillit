/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:02:40 by mschroed          #+#    #+#             */
/*   Updated: 2019/01/04 12:45:16 by mschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fillit.h"

void	usage(void)
{
	ft_putstr("usage: fillit input_file\n");
}

int		error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		solved;
	int		size;
	t_mino	*print;

	i = 0;
	solved = 0;
	size = 2;
	if (argc == 2)
	{
		if ((print = mino_oc(argv[1])) == 0)
			return (error());
		while (solved == 0)
		{
			map(size);
			//if (place is solved)
				solved = 1;
			size++;
		}
		while (print != NULL)
		{
			print2d(print->coordinates);
			puts("");
			print = print->next;
		}
	}
	else
		usage();
	return (0);
}
