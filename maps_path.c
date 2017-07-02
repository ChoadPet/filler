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
	if (skrr->player == 1)
	{
		if (is_it_free(8, 0, 'O', 'X'))
			fck_best_coordinate(skrr, 8, 0);
		else if (is_it_free(5, 16, 'O', 'X'))
			fck_best_coordinate(skrr, 5, 16);
		else
			fck_best_coordinate(skrr, 14, 16);
	}
	if (skrr->player == 2)
	{
		fck_best_coordinate(skrr, 0, 8);
	}
}

void	path_medium(t_skrr *skrr)
{
	if (skrr->player == 1)
	{
		if (is_it_free(3, 0, 'O', 'X'))
			fck_best_coordinate(skrr, 3, 0);
		else if (is_it_free(8, 39, 'O', 'X'))
			fck_best_coordinate(skrr, 8, 39);
		else
			fck_best_coordinate(skrr, 22, 39);
	}
	if (skrr->player == 2)
	{
		fck_best_coordinate(skrr, 10, 0);
	}
}

void	path_large(t_skrr *skrr)
{
	if (skrr->player == 1)
	{
		fck_best_coordinate(skrr, 0, 0);
	}
	if (skrr->player == 2)
	{
		fck_best_coordinate(skrr, 99, 99);
	}
}

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