/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/14 02:30:57 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_m_features(t_filler *filler)
{
	char *line;

	line = NULL;
	ft_dprintf(2, "m_features..\n");
	get_next_line(0, &line);
	ft_dprintf(2, "cmp....\n");
	ft_dprintf(2, "filler->m_features :%s\n", filler->m_features);
	ft_dprintf(2, "line : %s\n", line);
	if (ft_strcmp(filler->m_features, line))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	ft_dprintf(2, "cmp done..\n");
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

	ft_dprintf(2, "get map....\n");
	if (!(get_map_size(filler)))
		return (errors(filler, 1));
	// if (filler->init_m == 0)
	// {
	// 	ft_dprintf(2, "get map....\n");
	// 	if (!(get_map_size(filler)))
	// 		return (errors(filler, 1));
	// }
	// else if (!parse_m_features(filler))
	// 	return (errors(filler, 3));
	//if (filler->init_m == 0)
	ft_dprintf(2, "init map..\n");
	init_map(filler);
	ft_dprintf(2, "init done..\n");
	get_next_line(0, &line);
	ft_dprintf(2, "line : %s\n", line);
	if (line)
		ft_memdel((void**)&line);
	fill_map(filler);
	return (1);
}
