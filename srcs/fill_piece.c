/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:58:53 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 15:59:03 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_point_pos(t_filler *filler)
{
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < filler->piece.height)
	{
		j = 0;
		while (filler->piece.square[i][j])
		{
			if (filler->piece.square[i][j] == '*')
			{
				filler->piece.p[cnt].x = j;
				filler->piece.p[cnt].y = i;
				cnt++;
			}
			j++;
		}
		i++;
	}
}

int		fill_piece(t_filler *filler)
{
	char 	*line;
	int		i;

	i = 0;
	while (i < filler->piece.height)
	{
		get_next_line(0, &line);
		if (!check_p_line(filler, line))
			return (0);
		ft_strcpy(filler->piece.square[i], &*line);
		ft_memdel((void**)&line);
		i++;
	}
	filler->piece.p = (t_point*)palloc(sizeof(t_point) * filler->piece.cnt);
	ft_dprintf(2, "cnt :%d\n", filler->piece.cnt);
	get_point_pos(filler);
	ft_dprintf(2, "done\n");
	// while (i < filler->piece.cnt)
	// {
	// 	ft_dprintf(2, "x :%d\n", filler->piece.p[i].x);
	// 	ft_dprintf(2, "y :%d\n", filler->piece.p[i].y);
	// 	i++;
	// }
	return (1);
}
