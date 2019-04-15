/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:27:09 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/15 17:50:51 by yabecret         ###   ########.fr       */
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
				filler->piece.p[cnt].min = filler->point.min;
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
	line = NULL;
	while (i < filler->piece.height)
	{
		line = NULL;
		get_next_line(0, &line);
		if (!check_p_line(filler, line))
		{
			free(line);
			line = NULL;
			return (0);
		}
		ft_strcpy(filler->piece.square[i], line);
		i++;
	}
	free(line);
	line = NULL;
	return (1);
}

int		parse_piece(t_filler *filler)
{
	if (!get_piece_size(filler))
		return (errors(filler, 2));
	init_piece(filler);
	if (!fill_piece(filler))
		return (errors(filler, 4));
	filler->piece.p = (t_point*)palloc(sizeof(t_point) * filler->piece.cnt);
	get_point_pos(filler);
	return (1);
}
