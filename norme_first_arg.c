/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_first_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:24:40 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:24:41 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int		anothertry(t_main *main)
{
	int i;

	i = 0;
	while (main->parsed[i] == ' ')
	{
		i++;
	}
	if (main->parsed[i] == '%')
	{
		return (1);
	}
	return (0);
}

int		spacenoplus(t_main *main)
{
	int i;

	i = 0;
	while (main->parsed[i] != '\0')
	{
		if (main->parsed[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int		no_conv(t_main *main)
{
	char	*flag;
	int		i;

	i = 0;
	flag = "sSpdDioOuUxXcC";
	while (flag[i] != '\0')
	{
		if (find(main, flag[i]) == 1)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	the_plus(t_main *main, va_list *myva)
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
	if ((int)main->elem >= 0 && etat == 0 && main->plusetat != 1 &&
			find(main, 'C') == 0 && find(main, 'o') == 0 && find(main, 'O') == 0
			&& find(main, 's') == 0 && find(main, 'p') == 0 &&
			find(main, 'x') == 0 && find(main, 'X') == 0)
	{
		main->taille++;
		main->size++;
		main->plusetat = 1;
	}
	flag_fiel(main, myva);
}

void	all_finded(t_main *main)
{
	if (find(main, 'p') == 0 && find(main, 'o') == 0 &&
			find(main, 'x') == 0 && find(main, 'X') == 0 &&
			find(main, 's') == 0
			&& find(main, 'C') == 0 && find(main, 'S') == 0)
	{
		main->taille++;
		main->size++;
		main->print = ft_strjoin(main->print, " ");
	}
}
