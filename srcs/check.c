/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/14 02:08:29 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_good(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->piece.cnt)
	{
		if (filler->piece.p[i].good)
			return (1);
		i++;
	}
	return (0);
}

int	is_good(t_filler *filler, int j, t_point *p, t_point *t)
{
	 int i;
	 int x1;
	 int y1;
	 int good;

	 i = 0;
	 good = 1;
	 while (i < filler->piece.cnt)
	 {
		 y1 = (filler->piece.p[i].y - p->y + t->y); //point en cours
		 x1 = (filler->piece.p[i].x - p->x + t->x);
		 if (i == j)
			 i++;
		 else
		 {

			 if ((y1 < 0) || (y1 > filler->map.height) || (x1 < 0) || (x1 > filler->map.width))
			 {
//			 ft_dprintf(2, "overflow\n");
				 return (0);
			 }
			 if (filler->map.board[y1][x1] != '.')
				 good = 0;
			 i++;
		 }
	 }
	return (good);
}

int	check_p_pos(t_filler *filler, t_point *tracker) // point de la map
{
	int i;
	t_point p;

	i = 0;
	while (i < filler->piece.cnt)
	{
		p.x = filler->piece.p[i].x; // point de base
		p.y = filler->piece.p[i].y;
		// ft_dprintf(2, "p.x :%d\n", p.x);
		// ft_dprintf(2, "p.y :%d\n", p.y);
		// ft_dprintf(2, "tracker.x :%d\n", tracker->x);
		// ft_dprintf(2, "tracker.y :%d\n", tracker->y);
		filler->piece.p[i].good = is_good(filler, i, &p, tracker);
		// ft_dprintf(2, "index  :%d\n", i);
		// ft_dprintf(2, "good ? :%d\n", filler->piece.p[i].good);
		i++;
	}
	return (check_good(filler));
}
