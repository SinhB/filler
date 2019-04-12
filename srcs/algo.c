/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 20:12:24 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_edge(t_filler *filler, int y, int x)
{
	if (filler->map.board[y - 1][x] && filler->map.board[y - 1][x] == '.')
		return (1);
	if (filler->map.board[y + 1][x] && filler->map.board[y + 1][x] == '.')
		return (1);
	if (filler->map.board[y][x + 1] && filler->map.board[y][x + 1] == '.')
		return (1);
	if (filler->map.board[y][x - 1] && filler->map.board[y][x - 1] == '.')
			return (1);
	return (0);
}

int	calc_min_dist(t_filler *filler, int y, iny x, int j, int i)
{
	int i;
	int j;
	int x1;
	int y1;

	i = 0;
	while (i < filler->piece.cnt)
	{
		if (filler->piece.point[i].good)
		{
			j = 0;
			while (j < filler->piece.cnt)
			{
				x1 = ft_pow((i - (filler->piece.point[i].x - x)), 2);
				y1 = ft_pow((j - (filler->piece.point[i].y - y)), 2);
				filler->piece.point[i].min_dist = ft_sqrt(x1 + y1);
				j++;
			}
		}
		i++;
	}
	return (min);
}

int	get_min_dist(t_filler *filler, int y, int x)
{
	int j;
	int i;
	int min;

	j = 0;
	min = 0;
	while (j < filler->map.height)
	{
		i = 0;
		while (i < filler->map.width)
		{
			if (filler->map.board[j][i] == filler->bot)
			{
				min = calc_min_dist(filler, y, x, j, i);
				if (min < filler->point.min_dist)
				{
					filler->point.x = x;
					filler->point.y = y;
					filler->point.min_dist = min;
				}
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	algo(t_filler *filler)
{
	int y;
	int x;

	y = 0;
	while (y< filler->map.height)
	{
		x = 0;
		while (x < filler->map.width)
		{
			if (filler->map.board[y][x] == filler->me)
			{
				if (check_edge(filler, y, x))
					if (check_p_pos(filler, y, x))
						get_min_dist(filler, y, x);
			}
			x++;
		}
		y++;
	}
	return (1);
}
