/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_secondary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:31:13 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/05 09:31:14 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	basic_info(char **line, t_skrr *skrr)
{
	(!(ft_strncmp(*line, "$$$ exec p1", 11))) ? (skrr->player = 1) : 0;
	(!(ft_strncmp(*line, "$$$ exec p2", 11))) ? (skrr->player = 2) : 0;
	if (!(ft_strncmp(*line, "Plateau 15", 10)))
		map_set(skrr, 15, 17);
	else if (!(ft_strncmp(*line, "Plateau 24", 10)))
		map_set(skrr, 24, 40);
	else if (!(ft_strncmp(*line, "Plateau 10", 10)))
		map_set(skrr, 100, 99);
	(!(ft_strncmp(*line, "Piece", 5))) ? piece_size(line, skrr) : 0;
}

void	map_set(t_skrr *skrr, int x, int y)
{
	skrr->x_map = -1;
	skrr->x_piece = -1;
	skrr->map_size_x = x;
	skrr->map_size_y = y;
	g_map = ((char **)malloc((sizeof(char *) * skrr->map_size_x)));
}

void	piece_size(char **line, t_skrr *skrr)
{
	while (**line)
	{
		if ((**line == ' ') && (*line)++)
		{
			skrr->piece_size_x = ft_atoi(*line);
			while (**line != ' ')
				(*line)++;
			skrr->piece_size_y = ft_atoi(*line);
		}
		(*line)++;
	}
	g_piece = ((char **)malloc(sizeof(char *) * skrr->piece_size_x));
	skrr->sh = skrr->piece_size_x;
}

int		is_it_free(t_skrr *skrr, int x, int y)
{
	int until;

	if (skrr->map_size_x == 15)
	{
		until = 1;
		if (maybe_free(skrr, x, y, until))
			return (1);
		return (0);
	}
	else if (skrr->map_size_x == 24)
	{
		until = 1;
		if (maybe_free(skrr, x, y, until))
			return (1);
		return (0);
	}
	else if (skrr->map_size_x == 100)
	{
		until = 1;
		if (maybe_free(skrr, x, y, until))
			return (1);
		return (0);
	}
	return (0);
}

int		maybe_free(t_skrr *skrr, int x, int y, int until)
{
	int i;
	int j;

	i = x;
	i = (i - 1 < 0) ? x : (x - until);
	while ((i < (x + until)) && ((x + until) < skrr->map_size_x))
	{
		j = y;
		j = (j - 1 < 0) ? y : (y - until);
		while ((j < (y + until)) && ((y + until) < skrr->map_size_y))
		{
			if ((g_map[i][j] == 'O') || (g_map[i][j] == 'X'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
