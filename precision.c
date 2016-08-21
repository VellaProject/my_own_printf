/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 23:05:59 by avella            #+#    #+#             */
/*   Updated: 2016/05/01 23:06:03 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	if_pre(t_main *main)
{
	int		i;
	int		size;
	int		i2;
	char	*myacc;

	i = 0;
	i2 = 0;
	i = main->i + 1;
	while (main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
	{
		main->i++;
	}
	size = main->i - i;
	myacc = (char *)malloc(sizeof(char) * size + 10);
	while (i <= main->i)
	{
		myacc[i2] = main->chaine[i];
		i2++;
		i++;
	}
	myacc[i2] = '\0';
	main->accurate = ft_atoi(myacc);
	free(myacc);
}

int		my_accurate(t_main *main, va_list *myva)
{
	main->i++;
	if (main->chaine[main->i] == '.')
	{
		main->pointetat = 1;
		if (main->chaine[main->i + 1] >= '0'
				&& main->chaine[main->i + 1] <= '9')
			if_pre(main);
		else if (main->chaine[main->i + 1] == '*')
		{
			main->i++;
			main->accurate = (int)main->elem;
			main->elem = va_arg(*myva, void *);
		}
		else
		{
			main->accurate = 0;
		}
		my_accurate(main, myva);
	}
	else
		main->i--;
	return (0);
}
