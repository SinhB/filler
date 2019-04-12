/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 19:23:40 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_p_line(t_filler *filler, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '*')
			return (0);
		if (line[i] == '*')
			filler->piece.cnt++;
		i++;
	}
	if (i != filler->piece.width)
		return (0);
	return (1);
}

int	check_good(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->piece.cnt)
	{
		if (filler->piece.point[i].good)
			return (1);
	}
	return (0);
}

int	check_p_pos(t_filler *filler, int y, int x)
{
	int i;
	int x1;
	int y1;
	int x2;
	int y2;
	int good;

	i = 0;
	while (i < filler->piece.cnt)
	{
		j = 0;
		x1 = filler->piece.point[i].x - x;
		y1 = filler->piece.point[i].y - y;
		good = 1;
		while (j < filler->piece.cnt)
		{
			y2 = filler->piece.point[j].y;
			x2 = filler->piece.point[j].x;
			if (i == j)
				j++;
			else
			{
				if (filler->map.board[y2 - y1][x2 - x1] != '.')
					good = 0;
				j++;
			}
		}
		if (good)
			filler->piece.point[i].good = 1;
		i++;
	}
	return (check_good(filler));
}
