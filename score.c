/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:20:28 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/28 09:17:11 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_cut(int p1, int p2, int player)
{
	if (player == 1)
	{
		ft_putstr("Prastoin a ");
		ft_putnbr((p1 * 100 / (p1 + p2)));
		ft_putstr("% de win rate sur ");
		ft_putnbr((p1 + p2));
		ft_putstr(" parties\n");
	}
	else
	{
		ft_putstr("Prastoin a ");
		ft_putnbr((p2 * 100 / (p1 + p2)));
		ft_putstr("% de win rate sur ");
		ft_putnbr((p2 + p1));
		ft_putstr(" parties\n");
	}
}

int			main(int argc, const char **argv)
{
	int		fd;
	char	*line;
	int		p1;
	int		p2;
	int		player;

	(void)argc;
	p1 = 0;
	p2 = 0;
	fd = open("result", O_RDWR);
	player = (argv[1][0] == '1' ? 1 : 2);
	while (get_next_line(fd, &line) > 0)
	{
		if (atoi(line) == 1)
			p1++;
		else if (atoi(line) == 2)
			p2++;
		free(line);
	}
	ft_cut(p1, p2, player);
	close(fd);
	return (0);
}
