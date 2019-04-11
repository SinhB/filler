/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/11 17:45:15 by yabecret         ###   ########.fr       */
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
	if (filler->init_m == 0)
	{
		get_next_line(0, &line);
		if (!check_features(filler, line, 1))
		{
			ft_memdel((void**)&line);
			return (0);
		}
	}
	if (line)
		ft_memdel((void**)&line);
	return (1);
}

int	parse_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	if (!parse_m_features(filler))
		return (errors(3));
	get_next_line(0, &line);
	while (i < filler->map.height)
	{
		get_next_line(0, &line);
		while (ft_isdigit(*line) || ft_isblank(*line))
			line++;
		ft_strcpy(filler->map.board[i], &*line);
		//ft_memdel((void**)&line);
		i++;
	}
	filler->init_m = 0;
	print_map(filler);
	return (1);
}
