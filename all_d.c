/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:22:42 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:22:45 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	join_lld(t_main *main)
{
	char	*number;
	int		size;

	number = my_itoa((long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_ld(t_main *main)
{
	char	*number;
	int		size;

	number = my_itoa((long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_hd(t_main *main)
{
	char	*number;
	int		size;

	if (find(main, 'D') == 1)
		number = my_itoa((long long int)main->elem);
	else
		number = my_itoa((short int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_hhd(t_main *main)
{
	char	*number;
	int		size;

	if (find(main, 'D'))
		number = my_utoa((long long int)main->elem);
	else
		number = my_itoa((signed char)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_jd(t_main *main)
{
	char	*number;
	int		size;

	number = my_itoa((long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}
