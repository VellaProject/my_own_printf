/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:24:08 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:24:09 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	norme_p(t_main *main)
{
	int		size_accurate;
	int		size_word;

	size_accurate = main->accurate;
	size_word = ft_strlen(main->print);
	if (size_word < size_accurate)
	{
		while (size_word < size_accurate)
		{
			main->print = ft_strjoin("0", main->print);
			size_word++;
			main->size++;
		}
	}
	main->size += 2;
	main->print = ft_strjoin("0x", main->print);
}

void	lastedd(t_main *main)
{
	main->size += 3;
	main->print = ft_strjoin("0x0", main->print);
}

void	in_norme_p(t_main *main)
{
	int i;

	if (main->accurate > 0)
		norme_p(main);
	else if (main->width < 0)
	{
		main->size += 3;
		main->print = ft_strjoin("0x0", main->print);
	}
	else if (main->width > 2 && main->zeroetat == 1)
	{
		i = 2;
		while (i < main->width)
		{
			main->print = ft_strjoin("0", main->print);
			i++;
			main->size++;
		}
		main->print = ft_strjoin("0x", main->print);
	}
	else
		lastedd(main);
}

void	the_p_lol(t_main *main)
{
	int size_accurate;
	int size_word;

	main->size += 2;
	base_converter(main, (unsigned long long int)main->elem, 16);
	if (main->accurate > 0)
	{
		size_accurate = main->accurate;
		size_word = ft_strlen(main->print);
		if (size_word < size_accurate)
		{
			while (size_word < size_accurate)
			{
				main->print = ft_strjoin("0", main->print);
				size_word++;
				main->size++;
			}
		}
	}
}

void	yo_nor(t_main *main, int size)
{
	int i;

	i = ft_strlen(main->print) + 2;
	while (i < main->width)
	{
		if (main->accurate > size - 2)
			main->print = ft_strjoin("0", main->print);
		i++;
	}
}
