/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/13 21:56:18 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_m_features(t_filler *filler)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (ft_strcmp(filler->m_features, line))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	if (line)
		ft_memdel((void**)&line);
	filler->point.min = filler->size;
	return (1);
}

int		fill_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	ft_dprintf(2, "salut fillmap\n");
	while (i < filler->map.height)
	{
		get_next_line(0, &line);
		while (ft_isdigit(*line) || ft_isblank(*line))
			line++;
		ft_strcpy(filler->map.board[i], &*line);
		i++;
	}
	return (1);
}

int	parse_map(t_filler *filler)
{
	char	*line;

	ft_dprintf(2, "salut map\n");
	if (filler->init_m == 0)
	{
		if (!(get_map_size(filler)))
			return (errors(filler, 1));
	}
	else if (!parse_m_features(filler))
		return (errors(filler, 3));
	if (filler->init_m == 0)
		init_map(filler);
	get_next_line(0, &line);
	if (line)
		ft_memdel((void**)&line);
	fill_map(filler);
	return (1);
}
