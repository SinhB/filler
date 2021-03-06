/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:57:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/05/10 13:02:15 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_m_line(t_filler *filler, char *dest, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (j >= filler->map.width)
			return (0);
		if ((i < 3 && !ft_isdigit(str[i])) || (i == 3 && str[i] != ' '))
			return (0);
		if (i > 3 && str[i] != 'O' && str[i] != 'X' && str[i] != '.')
			return (0);
		else if (i > 3)
		{
			dest[j] = str[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (1);
}

int	check_first_m_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i < 4 && str[i] != ' ')
			return (0);
		if (i > 4 && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_m_features(t_filler *filler)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) != 1)
	{
		ft_memdel((void**)&line);
		return (0);
	}
	if (ft_strcmp(filler->m_features, line))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	ft_memdel((void**)&line);
	filler->point.min = filler->size;
	return (1);
}

int	fill_map(t_filler *filler)
{
	char	*line;
	int		i;

	i = 0;
	while (i < filler->map.height)
	{
		line = NULL;
		if (get_next_line(0, &line) != 1)
		{
			ft_memdel((void**)&line);
			return (0);
		}
		if (!check_m_line(filler, filler->map.board[i], line))
		{
			ft_memdel((void**)&line);
			return (0);
		}
		ft_memdel((void**)&line);
		i++;
	}
	ft_memdel((void**)&line);
	return (1);
}

int	parse_map(t_filler *filler)
{
	char	*line;

	line = NULL;
	if (filler->init_m == 1)
		if (!parse_m_features(filler))
			return (errors(filler, 3));
	if ((get_next_line(0, &line) != 1))
	{
		ft_memdel((void**)&line);
		return (0);
	}
	if (!check_first_m_line(line))
	{
		ft_memdel((void**)&line);
		return (errors(filler, 6));
	}
	ft_memdel((void**)&line);
	if (!fill_map(filler))
		return (errors(filler, 5));
	filler->init_m = 1;
	return (1);
}
