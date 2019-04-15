/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/15 18:31:53 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	parse_m_features(t_filler *filler)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	ft_dprintf(2, "%s\n", line);
	if (ft_strcmp(filler->m_features, line))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	free(line);
	line = NULL;
	filler->point.min = filler->size;
	return (1);
}

int		fill_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	while (i < filler->map.height)
	{
		line = NULL;
		get_next_line(0, &line);
		ft_dprintf(2, "%s\n", line);
		while (ft_isdigit(*line) || ft_isblank(*line))
			line++;
		ft_strcpy(filler->map.board[i], line);
		i++;
	}
	line = NULL;
	return (1);
}

int	parse_map(t_filler *filler)
{
	char	*line;

	line = NULL;
	if (filler->init_m == 1)
		if (!parse_m_features(filler))
			return (errors(filler, 3));
	get_next_line(0, &line);
	ft_dprintf(2, "%s\n", line);
	free(line);
	line = NULL;
	fill_map(filler);
	filler->init_m = 1;
	return (1);
}
