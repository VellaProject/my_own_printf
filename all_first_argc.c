/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_first_argc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:23:17 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:23:18 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	zero_arg(t_main *main, va_list *myva)
{
	main->zeroetat = 1;
	flag_fiel(main, myva);
}

void	die_arg(t_main *main, va_list *myva)
{
	main->dietat = 1;
	flag_fiel(main, myva);
}

void	moin_arg(t_main *main, va_list *myva)
{
	main->moinetat = 1;
	flag_fiel(main, myva);
}

void	the_space(t_main *main)
{
	int i;
	int etat;

	etat = 0;
	i = 0;
	while (main->parsed[i] != '\0')
	{
		if (main->parsed[i] == 'u' || main->parsed[i] == 'c')
			etat = 1;
		i++;
	}
	if ((int)main->elem >= 0 && etat == 0 && anothertry(main) == 0)
	{
		if (spacenoplus(main) == 1)
			all_finded(main);
		while (main->chaine[main->i + 1] == ' ')
			main->i++;
	}
}

void	the_star(t_main *main, va_list *myva)
{
	main->etoile = 1;
	main->width = (int)main->elem;
	if (main->width < 0)
		main->moinetat = 1;
	main->elem = va_arg(*myva, void *);
	flag_fiel(main, myva);
}
