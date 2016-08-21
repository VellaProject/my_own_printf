/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_px.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:24:23 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:24:24 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	the_p(t_main *main)
{
	int size;

	if ((main->accurate == 0 && main->width != 0) ||
			(find(main, '.') == 1 && main->accurate < 1 && main->width != 0) ||
			((unsigned long long int)main->elem == 0 && find(main, '.') == 1
			&& main->accurate < 1))
	{
		main->size += 2;
		main->print = ft_strjoin(main->print, "0x");
	}
	else if ((unsigned long long int)main->elem == 0)
		in_norme_p(main);
	else
	{
		the_p_lol(main);
		size = ft_strlen(main->print) + 2;
		if (main->width > size)
			yo_nor(main, size);
		main->print = ft_strjoin("0x", main->print);
	}
}

void	norme_x(t_main *main)
{
	if (main->type == 0)
		base_converter(main, (unsigned int)main->elem, 16);
	else if (main->type == 1)
		base_converter(main, (unsigned long int)main->elem, 16);
	else if (main->type == 2)
		base_converter(main, (unsigned long long int)main->elem, 16);
	else if (main->type == 3)
		base_converter(main, (unsigned short int)main->elem, 16);
	else if (main->type == 4)
		base_converter(main, (unsigned char)main->elem, 16);
	else if (main->type == 5)
		base_converter(main, (uintmax_t)main->elem, 16);
	else if (main->type == 6)
		base_converter(main, (size_t)main->elem, 16);
	if (main->print[0] == '\0')
	{
		main->size++;
		main->print = ft_strjoin(main->print, "0");
	}
}

void	the_x(t_main *main)
{
	if ((main->accurate == 0 && main->width != 0) ||
			(find(main, '.') == 1 && main->accurate < 1 && main->width != 0) ||
			((unsigned int)main->elem == 0 && find(main, '.') == 1
			&& main->accurate < 1))
	{
		return ;
	}
	if ((unsigned long long int)main->elem != 4294967296 || main->type >= 1)
	{
		if (main->dietat == 1 && (unsigned long long int)main->elem != 0)
			main->size += 2;
		if ((unsigned long long int)main->elem != 0)
			norme_x(main);
		else
		{
			main->size++;
			main->print = ft_strjoin(main->print, "0");
		}
	}
	else
	{
		main->size++;
		main->print = ft_strjoin(main->print, "0");
	}
	accurate_d(ft_strlen(main->print), main);
}

void	norme_xx(t_main *main)
{
	if (main->type == 0)
		base_converter_upper(main, (unsigned int)main->elem, 16);
	else if (main->type == 1)
		base_converter_upper(main, (unsigned long int)main->elem, 16);
	else if (main->type == 2)
		base_converter_upper(main, (unsigned long long int)main->elem, 16);
	else if (main->type == 3)
		base_converter_upper(main, (unsigned short int)main->elem, 16);
	else if (main->type == 4)
		base_converter_upper(main, (unsigned char)main->elem, 16);
	else if (main->type == 5)
		base_converter_upper(main, (uintmax_t)main->elem, 16);
	else if (main->type == 6)
		base_converter_upper(main, (size_t)main->elem, 16);
	if (main->print[0] == '\0')
	{
		main->size++;
		main->print = ft_strjoin(main->print, "0");
	}
}

void	the_xx(t_main *main)
{
	if ((main->accurate == 0 && main->width != 0) ||
			(find(main, '.') == 1 && main->accurate < 1 && main->width != 0) ||
			((unsigned int)main->elem == 0 && find(main, '.') == 1
			&& main->accurate < 1))
		return ;
	if ((unsigned long long int)main->elem != 4294967296 || main->type >= 1)
	{
		if (main->dietat == 1 && (unsigned long long int)main->elem != 0)
		{
			main->size += 2;
		}
		if ((unsigned long long int)main->elem != 0)
			norme_xx(main);
		else
		{
			main->size++;
			main->print = ft_strjoin(main->print, "0");
		}
	}
	else
	{
		main->size++;
		main->print = ft_strjoin(main->print, "0");
	}
	accurate_d(ft_strlen(main->print), main);
}
