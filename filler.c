/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:30:38 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/05 09:30:42 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;
	t_skrr	skrr;

	skrr.sh = -1;
	while (get_next_line(0, &line) > 0)
	{
		basic_info(&line, &skrr);
		if (line[0] == '0')
			g_map[++skrr.x_map] = ft_strsub(line, 4, (skrr.map_size_y + 4));
		if (line[0] == '.' || line[0] == '*')
			g_piece[++skrr.x_piece] = ft_strsub(line, 0, (skrr.piece_size_y));
		if (skrr.sh == skrr.x_piece + 1)
			found_first(&skrr);
	}
	return (0);
}
