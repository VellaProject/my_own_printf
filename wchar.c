/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 22:45:28 by avella            #+#    #+#             */
/*   Updated: 2016/05/01 22:52:42 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	second_mask(wint_t mycarac, t_main *main)
{
	unsigned char first;
	unsigned char second;

	first = (unsigned char)(((mycarac & 0x07c0) >> 6) + 0xC0);
	second = (unsigned char)((mycarac & 0x003F) + 0x80);
	main->print = ft_strjoin_carac(main->print, (char)first);
	main->print = ft_strjoin_carac(main->print, (char)second);
}

void	three_mask(wint_t mycarac, t_main *main)
{
	unsigned char first;
	unsigned char second;
	unsigned char three;

	first = (unsigned char)(((mycarac & 0xF000) >> 12) + 0xE0);
	second = (unsigned char)(((mycarac & 0x0FC0) >> 6) + 0x80);
	three = (unsigned char)((mycarac & 0x003F) + 0x80);
	main->print = ft_strjoin_carac(main->print, (char)first);
	main->print = ft_strjoin_carac(main->print, (char)second);
	main->print = ft_strjoin_carac(main->print, (char)three);
}

void	four_mask(wint_t mycarac, t_main *main)
{
	unsigned char first;
	unsigned char second;
	unsigned char three;
	unsigned char four;

	first = (unsigned char)(0xF0 | mycarac >> 18);
	second = (unsigned char)(((mycarac & 0xF000) >> 12) + 0xE0);
	three = (unsigned char)(((mycarac & 0x0FC0) >> 6) + 0x80);
	four = (unsigned char)((mycarac & 0x003F) + 0x80);
	main->print = ft_strjoin_carac(main->print, (char)first);
	main->print = ft_strjoin_carac(main->print, (char)second);
	main->print = ft_strjoin_carac(main->print, (char)three);
	main->print = ft_strjoin_carac(main->print, (char)four);
}

void	mywchar(t_main *main, wint_t value)
{
	wint_t mycarac;

	mycarac = value;
	if (mycarac < 0x80)
		prem_mask(main, mycarac);
	else if (mycarac < 0x800)
		sec_mask(main, mycarac);
	else if (mycarac < 0x10000)
		tre_mask(main, mycarac);
	else if (mycarac < 0x200000)
		fo_mask(main, mycarac);
}
