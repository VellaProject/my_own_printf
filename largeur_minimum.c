/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largeur_minimum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:16:42 by avella            #+#    #+#             */
/*   Updated: 2016/05/01 17:50:39 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int		okorno(t_main *main)
{
	int i;

	i = 0;
	if (main->parsed[i] == '+' || main->parsed[i] == '-'
		|| main->parsed[i] == '#' || main->parsed[i] == ' ')
	{
		i++;
	}
	while (main->parsed[i] <= '9' && main->parsed[i] >= '0')
	{
		i++;
	}
	if (main->parsed[i] == '*')
		return (1);
	return (0);
}

void	first_width(t_main *main)
{
	int		size;
	int		i;
	int		i2;
	char	*myacc;

	i2 = 0;
	i = main->i + 1;
	if (main->chaine[main->i + 1] == '0')
	{
		main->zeroetat = 1;
		main->i++;
	}
	while (main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
		main->i++;
	size = main->i - i;
	myacc = (char *)malloc(sizeof(char) * size + 10);
	while (i <= main->i)
	{
		myacc[i2] = main->chaine[i];
		i2++;
		i++;
	}
	myacc[i2] = '\0';
	main->width = ft_atoi(myacc);
}

int		my_width(t_main *main, va_list *myva)
{
	int		yesno;

	yesno = okorno(main);
	if (main->etoile == 1)
		yesno = 0;
	if (yesno == 1)
	{
		while (main->chaine[main->i + 1] != '*')
			main->i++;
	}
	if (main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9'
			&& yesno == 0)
	{
		first_width(main);
	}
	else if (main->chaine[main->i + 1] == '*')
	{
		main->i++;
		main->width = (int)main->elem;
		if (main->width < 0)
			main->moinetat = 1;
		main->elem = va_arg(*myva, void *);
	}
	return (0);
}
