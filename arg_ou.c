/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:23:59 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:24:00 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	all_o(t_main *main)
{
	if ((unsigned long long int)main->elem != 0)
	{
		if (main->type == 0)
			base_converter(main, (unsigned int)main->elem, 8);
		else if (main->type == 1)
			base_converter(main, (unsigned long int)main->elem, 8);
		else if (main->type == 2)
			base_converter(main, (unsigned long long int)main->elem, 8);
		else if (main->type == 3)
			base_converter(main, (unsigned short int)main->elem, 8);
		else if (main->type == 4)
			base_converter(main, (unsigned char)main->elem, 8);
		else if (main->type == 5)
			base_converter(main, (uintmax_t)main->elem, 8);
		else if (main->type == 6)
			base_converter(main, (size_t)main->elem, 8);
	}
	else if (main->dietat == 0)
	{
		main->size++;
		main->print = ft_strjoin(main->print, "0");
	}
}

void	the_o(t_main *main)
{
	if (((main->accurate == 0 && main->width != 0) ||
				(find(main, '.') == 1 && main->accurate < 1
				&& main->width != 0) ||
				((unsigned int)main->elem == 0 && find(main, '.') == 1
				&& main->accurate < 1)) && main->dietat == 0)
		return ;
	if (main->dietat == 1)
	{
		main->print = ft_strjoin(main->print, "0");
		main->size++;
	}
	all_o(main);
	accurate_d(ft_strlen(main->print), main);
}

void	the_second_o(t_main *main)
{
	if (((main->accurate == 0 && main->width != 0) ||
				(find(main, '.') == 1 && main->accurate < 1
				&& main->width != 0) ||
				((unsigned int)main->elem == 0 && find(main, '.') == 1
				&& main->accurate < 1)) && main->dietat == 0)
	{
		return ;
	}
	if (main->dietat == 1)
	{
		main->print = ft_strjoin(main->print, "0");
		main->size++;
	}
	if ((unsigned long long int)main->elem != 0)
		base_converter_upper(main, (unsigned long long int)main->elem, 8);
	else if (main->dietat == 0)
	{
		main->size++;
		main->print = ft_strjoin(main->print, "0");
	}
	accurate_d(ft_strlen(main->print), main);
}

void	the_u(t_main *main)
{
	if (main->type == 0)
		join_u(main);
	else if (main->type == 1)
		join_lu(main);
	else if (main->type == 2)
		join_llu(main);
	else if (main->type == 3)
		join_hu(main);
	else if (main->type == 4)
		join_hhu(main);
	else if (main->type == 5)
		join_ju(main);
	else if (main->type == 6)
		join_zu(main);
}

void	the_second_u(t_main *main)
{
	if (main->type > 0)
	{
		main->type++;
	}
	else
		main->type = 1;
	if (main->type == 1)
		join_lu(main);
	else if (main->type == 2)
		join_llu(main);
	else if (main->type == 3)
		join_hu(main);
	else if (main->type == 4)
		join_hhu(main);
	else if (main->type == 5)
		join_ju(main);
	else if (main->type >= 6)
		join_zu(main);
}
