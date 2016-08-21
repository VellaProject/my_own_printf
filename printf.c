/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 23:07:08 by avella            #+#    #+#             */
/*   Updated: 2016/05/01 23:38:22 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	init_main(t_main *main)
{
	main->print = ft_memalloc(sizeof(char) * 10);
	main->parsed = ft_memalloc(sizeof(char) * 10);
	main->accurate = -1;
	main->width = 0;
	main->mini = 0;
	main->taille = 0;
	main->signemoin = 0;
	main->pointetat = 0;
	main->etat = 0;
	main->size = 0;
	main->conv = 't';
	main->type = 0;
	main->moinetat = 0;
	main->casc = 0;
	main->dietat = 0;
	main->zeroetat = 0;
	main->plusetat = 0;
	main->etoile = 0;
	main->stop = 0;
}

t_main	*init_pls(const char *format)
{
	t_main *main;

	main = (t_main *)malloc(sizeof(t_main) * 10);
	main->sizeword = 0;
	main->i = 0;
	main->totalsize = 0;
	main->chaine = format;
	return (main);
}

void	ok_un(t_main *main, const char *format)
{
	ft_putchar(format[main->i]);
	main->sizeword++;
}

void	mid_range(t_main *main, va_list *myva)
{
	flag_fiel(main, myva);
	my_width(main, myva);
	my_accurate(main, myva);
	lenght_fiel(main);
	manage_arg(main);
	add_mini(main);
	ft_putstr(main->print);
}

int		ft_printf(const char *format, ...)
{
	va_list		myva;
	t_main		*main;

	main = init_pls(format);
	va_start(myva, format);
	while (format[main->i] != '\0')
	{
		if (format[main->i] != '%')
			ok_un(main, format);
		else if (format[main->i + 1] != '\0')
		{
			init_main(main);
			if (main->chaine[main->i + 1] != '%')
				main->elem = va_arg(myva, void *);
			mid_range(main, &myva);
			if (main->casc == 1)
				write(1, "\0", 1);
			main->totalsize += main->size;
		}
		if (format[main->i] != '\0')
			main->i++;
	}
	va_end(myva);
	main->totalsize += main->sizeword;
	return (main->totalsize);
}
