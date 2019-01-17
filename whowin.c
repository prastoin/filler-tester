/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whowin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prastoin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:59:28 by prastoin          #+#    #+#             */
/*   Updated: 2018/12/28 10:45:29 by prastoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_cut(char *tmp[2], int i)
{
	int result;
	int whowin;

	result = atoi(tmp[0] + 10) - atoi(tmp[1] + 10);
	whowin = (result > 0 ? 1 : 2);
	ft_putnbr_fd(whowin, i);
	ft_putchar_fd('\n', i);
	close(i);
}

int			main(void)
{
	char		*tmp[2];
	char		*line;
	static int	start;
	int			i;
	int			ret;

	ret = 1;
	i = open("result", O_RDWR | O_APPEND);
	while (ret > 0)
	{
		if (tmp[0])
			free(tmp[0]);
		if (tmp[1])
			free(tmp[1]);
		if (start > 1)
			tmp[0] = ft_strdup(tmp[1]);
		if (start > 0)
			tmp[1] = ft_strdup(line);
		start++;
		if (line)
			free(line);
		ret = get_next_line(0, &line);
	}
	ft_cut(tmp, i);
	return (0);
}
