/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 09:31:03 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/05 09:31:04 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	path_small(t_skrr *skrr)
{
	if (skrr->player == 1)
	{
		if (is_it_free(skrr, 5, 15))
			fck_best_coordinate(skrr, 5, 15);
		else if (is_it_free(skrr, 13, 8))
			fck_best_coordinate(skrr, 13, 8);
		else if (is_it_free(skrr, 0, 8))
			fck_best_coordinate(skrr, 0, 8);
		else
			fck_best_coordinate(skrr, 13, 14);
	}
	else if (skrr->player == 2)
	{
		if (is_it_free(skrr, 0, 15))
			fck_best_coordinate(skrr, 0, 15);
		else if (is_it_free(skrr, 7, 8))
			fck_best_coordinate(skrr, 7, 8);
		else if (is_it_free(skrr, 13, 0))
			fck_best_coordinate(skrr, 13, 0);
		else if (is_it_free(skrr, 10, 0))
			fck_best_coordinate(skrr, 10, 0);
		else
			fck_best_coordinate(skrr, 0, 15);
	}
}

void	path_medium(t_skrr *skrr)
{
	if (skrr->player == 1)
	{
		if (is_it_free(skrr, 11, 20))
			fck_best_coordinate(skrr, 11, 20);
		else if (is_it_free(skrr, 22, 38))
			fck_best_coordinate(skrr, 22, 38);
		else if (is_it_free(skrr, 12, 0))
			fck_best_coordinate(skrr, 12, 0);
		else if (is_it_free(skrr, 20, 0))
			fck_best_coordinate(skrr, 20, 0);
		else if (is_it_free(skrr, 20, 10))
			fck_best_coordinate(skrr, 20, 10);
		else
			fck_best_coordinate(skrr, 12, 20);
	}
	else if (skrr->player == 2)
	{
		if (is_it_free(skrr, 12, 0))
			fck_best_coordinate(skrr, 12, 0);
		else if (is_it_free(skrr, 12, 38))
			fck_best_coordinate(skrr, 12, 38);
		else
			fck_best_coordinate(skrr, 6, 20);
	}
}

void	path_large(t_skrr *skrr)
{
	if (skrr->player == 1)
	{
		if (is_it_free(skrr, 60, 0))
			fck_best_coordinate(skrr, 60, 0);
		else if (is_it_free(skrr, 20, 90))
			fck_best_coordinate(skrr, 20, 90);
		else if (is_it_free(skrr, 98, 50))
			fck_best_coordinate(skrr, 98, 50);
		else if (is_it_free(skrr, 1, 1))
			fck_best_coordinate(skrr, 1, 1);
		else
			fck_best_coordinate(skrr, 97, 97);
	}
	else if (skrr->player == 2)
	{
		if (is_it_free(skrr, 0, 60))
			fck_best_coordinate(skrr, 0, 60);
		else if (is_it_free(skrr, 98, 50))
			fck_best_coordinate(skrr, 98, 50);
		else if (is_it_free(skrr, 80, 97))
			fck_best_coordinate(skrr, 80, 96);
		else
			fck_best_coordinate(skrr, 40, 96);
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
	if (skrr->manh == -1)
		skrr->manh = p + q;
	else
		skrr->tmp = p + q;
	if (skrr->tmp < skrr->manh)
	{
		skrr->manh = skrr->tmp;
		skrr->best_x = skrr->x_map;
		skrr->best_y = skrr->y_map;
	}
}
