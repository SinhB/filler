/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:43:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/24 12:01:12 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double	calc_min(t_filler *filler, t_point *t, t_point *p, t_point *ad)
{
	int		i;
	double	min;
	double	res;

	i = 0;
	min = filler->point.min;
	while (i < filler->piece.cnt)
	{
		if (i == p->i)
			i++;
		else
		{
			res = ft_pow((ad->x - (filler->piece.p[i].x - p->x + t->x)), 2);
			res += ft_pow((ad->y - (filler->piece.p[i].y - p->y + t->y)), 2);
			res = ft_sqrt(res);
			min = res < min ? res : min;
			i++;
		}
	}
	return (min);
}

double	calc_min_dist(t_filler *filler, t_point *tracker, t_point *ad)
{
	t_point	p;
	double	min;
	double	res;

	p.i = 0;
	min = filler->point.min;
	ft_bzero(&p, sizeof(p));
	while (p.i < filler->piece.cnt)
	{
		p.x = filler->piece.p[p.i].x;
		p.y = filler->piece.p[p.i].y;
		if (is_good(filler, &p, tracker))
		{
			res = calc_min(filler, tracker, &p, ad);
			if (res < filler->piece.p[p.i].min)
				filler->piece.p[p.i].min = res;
			min = res < min ? res : min;
		}
		p.i++;
	}
	return (min);
}

int		get_min_dist(t_filler *filler, t_point *tracker)
{
	double	min;
	t_point	ad;

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

int		its_me(t_filler *filler, t_point *tracker)
{
	if (check_edge(filler, tracker))
	{
		if (check_p_pos(filler, tracker))
		{
			get_min_dist(filler, tracker);
			return (1);
		}
	}
	return (0);
}

int		algo(t_filler *filler)
{
	t_point	tracker;
	int		end;

	end = 0;
	tracker.y = 0;
	while (tracker.y < filler->map.height)
	{
		tracker.x = 0;
		while (tracker.x < filler->map.width)
		{
			if (filler->map.board[tracker.y][tracker.x] == filler->me)
				end = its_me(filler, &tracker) ? 1 : end;
			tracker.x++;
		}
		tracker.y++;
	}
	return (filler_end(filler, end));
}
