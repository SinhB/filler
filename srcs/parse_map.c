/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/12 16:19:48 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->map.height)
	{
		ft_dprintf(2, "%s\n", filler->map.board[i]); //fd = 2 to print without affecting VM input -> only for testing
		i++;
	}
}

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
	return (1);
}

int	parse_map(t_filler *filler)
{
	char	*line;

	if (filler->init_m == 0)
	{
		if (!(get_map_size(filler)))
			return (errors(filler, 1));
	}
	else if (!parse_m_features(filler))
		return (errors(filler, 3));
	init_map(filler);
	get_next_line(0, &line);
	ft_memdel((void**)&line);
	fill_map(filler);
	filler->init_m = 1;
	print_map(filler);
	return (1);
}
