/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:31:57 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/22 18:32:06 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft/src/ft_printf/ft_printf.h"
# include "libft/src/get_next_line/get_next_line.h"
# include "libft/src/libft/libft.h"

char				**g_map;
char 				**g_piece;

typedef struct		s_skrr
{
	int 			sh;
	int				player;
	int 			map_size_x;
	int 			map_size_y;
	int				x_map;
	int 			y_map;
	int 			piece_size_x;
	int 			piece_size_y;
	int 			x_piece;
	int 			y_piece;

}					t_skrr;

void				basic_info(char **line, t_skrr *skrr);
void				piece_size(char **line, t_skrr *skrr);
void				found_first(t_skrr *skrr);
int					find_star(t_skrr *skrr, char o, char x);

//tmp function, just for print some info
//void				print_info(t_skrr *skrr);

#endif
