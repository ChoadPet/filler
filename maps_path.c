/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:31:47 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/22 18:49:58 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	path_small(t_skrr *skrr)
{
	fck_best_coordinate(skrr, 0, 14);
}

void	path_medium(t_skrr *skrr)
{
	fck_best_coordinate(skrr, 14, 25);
}

//void	path_large(t_skrr *skrr)
//{
//	fck_best_coordinate(skrr, 0, 16);
//}

void	fck_best_coordinate(t_skrr *skrr, int x, int y)
{
	int p;
	int q;

	p = x - skrr->x_map;
	q = y - skrr->y_map;
	(p < 0) ? p *= -1 : 0;
	(q < 0) ? q *= -1 : 0;
	(skrr->manh == -1) ? skrr->best_x = skrr->x_map : 0;
	(skrr->manh == -1) ? skrr->best_y = skrr->y_map : 0;
	(skrr->manh == -1) ? (skrr->manh = p + q) : (skrr->tmp = p + q);
	if (skrr->tmp < skrr->manh)
	{
		skrr->best_x = skrr->x_map;
		skrr->best_y = skrr->y_map;
	}
}

void 	piece_size(char **line, t_skrr *skrr)
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