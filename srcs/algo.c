/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/19 17:41:28 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_edge(t_filler *filler, t_point *p)
{
	if ((p->y - 1 > 0) && filler->map.board[p->y - 1][p->x] == '.')
		return (1);
	if ((p->y + 1 < filler->map.height) && filler->map.board[p->y + 1][p->x] == '.')
		return (1);
	if ((p->x + 1 < filler->map.width) && filler->map.board[p->y][p->x + 1] == '.')
		return (1);
	if ((p->x - 1 > 0) && filler->map.board[p->y][p->x - 1] == '.')
		return (1);
	return (0);
}

double	calc_min(t_filler *filler, t_point *t, t_point *p, t_point *ad, int j)
{
	int 	i;
	int 	x1;
	int 	y1;
	double	min;
	double	res;

	i = 0;
	min = filler->point.min;
	while (i < filler->piece.cnt)
	{
		if (i == j)
			i++;
		else
		{
			y1 = (filler->piece.p[i].y - p->y + t->y);
			x1 = (filler->piece.p[i].x - p->x + t->x);
			res = pow((ad->x - x1), 2);
			res += pow((ad->y - y1), 2);
			res = sqrt(res);
			min = res < min ? res : min;
			i++;
		}
	}
	return (min);
}

double	calc_min_dist(t_filler *filler, t_point *tracker, t_point *ad)
{
	int 	i;
	t_point p;
	double 	min;
	double 	res;

	i = 0;
	min = filler->point.min;
	ft_bzero(&p, sizeof(p));
	while (i < filler->piece.cnt)
	{
		p.x = filler->piece.p[i].x;
		p.y = filler->piece.p[i].y;
		if (is_good(filler, i, &p, tracker))
		{
			res = calc_min(filler, tracker, &p, ad, i);
			if (res < filler->piece.p[i].min)
				filler->piece.p[i].min = res;
			min = res < min ? res : min;
		}
		i++;
	}
	return (min);
}

int	get_min_dist(t_filler *filler, t_point *tracker)
{
	double 	min;
	t_point ad;

	min = filler->size;
	ad.y = 0;
	while (ad.y < filler->map.height)
	{
		ad.x = 0;
		while (ad.x < filler->map.width)
		{
			if (filler->map.board[ad.y][ad.x] == filler->ad)
			{
				min = calc_min_dist(filler, tracker, &ad);
				if (min < filler->point.min)
				{
					filler->point.x = tracker->x;
					filler->point.y = tracker->y;
					filler->point.min = min;
				}
			 }
			ad.x++;
		}
		ad.y++;
	}
	return (1);
}

int	algo(t_filler *filler)
{
	t_point tracker;
	int		end;

	end = 0;
	tracker.y = 0;
	while (tracker.y < filler->map.height)
	{
		tracker.x = 0;
		while (tracker.x < filler->map.width)
		{
			if (filler->map.board[tracker.y][tracker.x] == filler->me)
			{
				if (check_edge(filler, &tracker))
				{
					if (check_p_pos(filler, &tracker))
					{
						end = 1;
						get_min_dist(filler, &tracker);
						tracker.x++;
					}
					else
						tracker.x++;
				}
				else
					tracker.x++;
			}
			else
				tracker.x++;
		}
		tracker.y++;
	}
	if (end == 1)
	{
		print_pos(filler);
		free_piece(&filler->piece);
		filler->point.x = 0;
		filler->point.y = 0;
		filler->point.min = filler->size;
	}
	else
	{
		free_struct(filler);
		ft_printf("0 0\n");
	}
	return (end);
}
