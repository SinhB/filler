/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 18:30:19 by yabecret         ###   ########.fr       */
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

int	calc_min_dist(t_filler *filler, int y, iny x)
{
	
	return (min);
}

int	get_min_dist(t_filler *filler, int y, int x)
{
	int y;
	int x;
	int min;

	y = 0;
	min = 0;
	while (y< filler->map.height)
	{
		x = 0;
		while (x < filler->map.width)
		{
			if (filler->map.board[y][x] == filler->bot)
			{
				min = calc_min_dist(filler, y, x);
				if (min < filler->point.min_dist)
				{
					filler->point.x = x;
					filler->point.y = y;
					filler->point.min_dist = min;
				}
			}
			x++;
		}
		y++;
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
					get_min_dist(filler, y, x);
			}
			x++;
		}
		y++;
	}
	return (1);
}
