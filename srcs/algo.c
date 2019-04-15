/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/15 17:17:36 by yabecret         ###   ########.fr       */
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

int	print_pos(t_filler *filler)
{
	int i;
	int cnt;
	int x;
	int y;

	i = 0;
//	ft_dprintf(2, "piece.cnt :%d\n", filler->piece.cnt);
	while (i < filler->piece.cnt)
	{
		if (filler->piece.p[i].min <= filler->point.min)
			cnt = i;
		i++;
	}
	x = filler->point.x - filler->piece.p[cnt].x;
	y = filler->point.y - filler->piece.p[cnt].y;
	// ft_dprintf(2, "p.x :%d\n", filler->point.x);
	// ft_dprintf(2, "p.y :%d\n", filler->point.y);
	// ft_dprintf(2, "piece.p[%d].x :%d\n", cnt, filler->piece.p[cnt].x);
	// ft_dprintf(2, "piece.p[%d].y :%d\n", cnt, filler->piece.p[cnt].y);
	ft_printf("%d %d\n", x, y);
	return (1);
}

double	calc_min(t_filler *filler, t_point *t, t_point *p, t_point *ad)
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
		y1 = (filler->piece.p[i].y - p->y + t->y);
		x1 = (filler->piece.p[i].x - p->x + t->x);
		res = pow((ad->x - x1), 2);
		res += pow((ad->y - y1), 2);
		res = sqrt(res);
		min = res < min ? res : min;
		i++;
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
		if (filler->piece.p[i].good)
		{
			p.x = filler->piece.p[i].x;
			p.y = filler->piece.p[i].y;
			res = calc_min(filler, tracker, &p, ad);
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

	min = 0;
	ad.y = 0;
	while (ad.y < filler->map.height)
	{
		ad.x = 0;
		while (ad.x < filler->map.width)
		{
			if (filler->map.board[ad.y][ad.x] == filler->ad)
			{
				if (check_edge(filler, &ad))
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
				}
			}
			tracker.x++;
		}
		tracker.y++;
	}
	print_pos(filler);
	free_piece(&filler->piece);
	return (end);
}
