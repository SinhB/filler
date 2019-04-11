/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 01:28:44 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/11 02:53:40 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_features(t_filler *filler, char *line, int i)
{
	int error;
	int n;

	n = 0;
	if (i == 1)
		error = ft_strcmp(filler->m_features, line) ? 0 : 1;
	else
		error = ft_strcmp(filler->p_features, line) ? 0 : 1;
	return (error);
}
