/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 22:24:28 by avella            #+#    #+#             */
/*   Updated: 2016/05/01 22:43:55 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	mid_parsing(t_main *main, int i)
{
	while (main->chaine[i] <= '9' && main->chaine[i] >= '0')
	{
		main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
		i++;
	}
	while (main->chaine[i] == 'l' || main->chaine[i] == 'h' ||
			main->chaine[i] == 'j' || main->chaine[i] == 'z')
	{
		main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
		i++;
	}
	if (main->chaine[i] != '\0')
		main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
}

void	parsing(t_main *main)
{
	int i;

	i = main->i;
	while (main->chaine[i] == '+' || main->chaine[i] == '-' ||
			main->chaine[i] == '#' || main->chaine[i] == ' ')
	{
		main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
		i++;
	}
	while (main->chaine[i] <= '9' && main->chaine[i] >= '0')
	{
		main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
		i++;
	}
	if (main->chaine[i] == '.')
	{
		main->parsed = ft_strjoin_carac(main->parsed, main->chaine[i]);
		i++;
	}
	mid_parsing(main, i);
}

int		flag_fiel(t_main *main, va_list *myva)
{
	main->i++;
	parsing(main);
	if (main->chaine[main->i] == '0')
		zero_arg(main, myva);
	if (main->chaine[main->i] == '+')
		the_plus(main, myva);
	else if (main->chaine[main->i] == '#')
		die_arg(main, myva);
	else if (main->chaine[main->i] == '-')
		moin_arg(main, myva);
	else if (main->chaine[main->i] == '*')
		the_star(main, myva);
	else if (main->chaine[main->i] == ' ')
	{
		if (no_conv(main) == 1 && find(main, '%') == 0)
			return (0);
		the_space(main);
		flag_fiel(main, myva);
	}
	else
		main->i--;
	return (0);
}
