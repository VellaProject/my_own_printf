/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 23:26:20 by avella            #+#    #+#             */
/*   Updated: 2016/04/30 23:28:03 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	the_l(t_main *main)
{
	main->etat = 1;
	if (main->chaine[main->i + 1] == 'l')
	{
		main->i++;
		main->type = 2;
	}
	else
		main->type = 1;
	lenght_fiel(main);
}

void	the_h(t_main *main)
{
	main->etat = 1;
	if (main->chaine[main->i + 1] == 'h')
	{
		main->i++;
		main->type = 4;
	}
	else
		main->type = 3;
	lenght_fiel(main);
}

int		lenght_fiel(t_main *main)
{
	main->i++;
	if (main->chaine[main->i] == 'l')
		the_l(main);
	else if (main->chaine[main->i] == 'h')
		the_h(main);
	else if (main->chaine[main->i] == 'j')
	{
		main->etat = 1;
		main->type = 5;
		lenght_fiel(main);
	}
	else if (main->chaine[main->i] == 'z')
	{
		main->etat = 1;
		main->type = 6;
		lenght_fiel(main);
	}
	else
		main->i--;
	return (0);
}
