/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:33:27 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/29 19:32:37 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_piece_size(t_filler *filler)
{
	char	*line;
	int		i;
	int		error;

	i = 0;
	error = 1;
	line = NULL;
	if (get_next_line(0, &line) != 1)
	{
		ft_memdel((void**)&line);
		return (0);
	}
	if (ft_strncmp(line, "Piece ", 6))
		error = 0;
	if (!(filler->piece.height = ft_atoi(&line[6])))
		error = 0;
	i = ft_cntdigit(filler->piece.height) + 1;
	if (!(filler->piece.width = ft_atoi(&line[6 + i])))
		error = 0;
	i += ft_cntdigit(filler->piece.width);
	if (line[6 + i] != ':')
		error = 0;
	ft_memdel((void**)&line);
	return (error);
}

int		get_map_size(t_filler *filler)
{
	char	*line;
	int		i;
	int		error;

	i = 0;
	error = 1;
	line = NULL;
	if (get_next_line(0, &line) != 1)
	{
		ft_memdel((void**)&line);
		return (0);
	}
	filler->m_features = ft_strdup(line);
	if (ft_strncmp(line, "Plateau ", 8)
		|| !(filler->map.height = ft_atoi(&line[8])))
		error = 0;
	i = ft_cntdigit(filler->map.height) + 1;
	if (!(filler->map.width = ft_atoi(&line[8 + i])))
		error = 0;
	i += ft_cntdigit(filler->map.width);
	if (line[8 + i] != ':')
		error = 0;
	ft_memdel((void**)&line);
	return (error);
}

void	p_nb(t_filler *filler, char me, char ad)
{
	filler->me = me;
	filler->ad = ad;
}

int		get_player_number(t_filler *filler, int i)
{
	char	*line;
	int		error;

	error = 1;
	line = NULL;
	if (get_next_line(0, &line) != 1)
	{
		ft_memdel((void**)&line);
		return (0);
	}
	if (ft_strncmp(line, "$$$ exec p", 10))
		error = 0;
	if (line[14] == '[')
		while (line[14 + i])
			i++;
	else
		error = 0;
	if (line[12] != ':' || line[13 + i] != ']')
		error = 0;
	if (line[10] == '1' || line[10] == '2')
		line[10] == '1' ? p_nb(filler, 'O', 'X') : p_nb(filler, 'X', 'O');
	else
		error = 0;
	ft_memdel((void**)&line);
	return (error);
}
