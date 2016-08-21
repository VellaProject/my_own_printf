/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:45:51 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:49:16 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PRINTF_H
# define MY_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include "includes/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

typedef struct			s_main
{
	int			i;
	const char	*chaine;
	int			nb;
	int			taille;
	void		*elem;
	int			signemoin;
	int			stop;
	int			casc;
	int			pointetat;
	int			type;
	char		conv;
	int			etoile;
	int			etat;
	int			dietat;
	int			plusetat;
	int			accurate;
	int			width;
	int			moinetat;
	int			zeroetat;
	int			mini;
	char		*parsed;
	char		*print;
	int			size;
	int			sizeword;
	int			totalsize;
}						t_main;

int						no_conv(t_main *main);
void					parsing(t_main *main);
void					mywchar(t_main *main, wint_t value);
char					*my_utoa(unsigned long long int n);
char					*my_itoa(long long int n);
char					*ft_strjoin_carac(char const *s1, char s2);
int						manage_arg(t_main *main);
int						base_converter(t_main *main,
						unsigned long long int convert, int basee);
int						base_converter_upper(t_main *main,
						unsigned long long int convert, int basee);
int						ft_printf(const char *format, ...);
int						add_mini(t_main *main);
int						my_width(t_main *main, va_list *myva);
int						flag_fiel(t_main *main, va_list *myva);
int						my_accurate(t_main *main, va_list *myva);
int						lenght_fiel(t_main *main);
int						find(t_main *main, char tofind);
void					accurate_d(int size, t_main *main);
void					join_lld(t_main *main);
void					join_ld(t_main *main);
void					join_hd(t_main *main);
void					join_hhd(t_main *main);
void					join_jd(t_main *main);
void					join_zd(t_main *main);
void					join_d(t_main *main);
void					join_lu(t_main *main);
void					join_llu(t_main *main);
void					join_hu(t_main *main);
void					join_hhu(t_main *main);
void					join_ju(t_main *main);
void					join_zu(t_main *main);
void					join_u(t_main *main);
void					d_i_signemoin(t_main *main);
void					all_d_i(t_main *main);
void					d_i(t_main *main);
void					the_second_d(t_main *main);
void					all_o(t_main *main);
void					the_o(t_main *main);
void					the_second_o(t_main *main);
void					the_u(t_main *main);
void					the_second_u(t_main *main);
void					the_s_c(t_main *main);
void					the_c(t_main *main);
void					the_other(t_main *main);
void					hihi_s(t_main *main);
void					the_first_s(t_main *main);
void					the_second_s(t_main *main);
void					the_s(t_main *main);
void					the_second_ss(t_main *main);
void					the_s_s(t_main *main);
void					norme_p(t_main *main);
void					lastedd(t_main *main);
void					in_norme_p(t_main *main);
void					the_p_lol(t_main *main);
void					yo_nor(t_main *main, int size);
void					the_p(t_main *main);
void					norme_x(t_main *main);
void					the_x(t_main *main);
void					norme_xx(t_main *main);
void					the_xx(t_main *main);
void					the_percent(t_main *main);
void					last_arg(t_main *main);
void					a_un_moment(t_main *main);
int						jajaja(t_main *main);
int						manage_arg(t_main *main);
void					mid_parsing(t_main *main, int i);
void					parsing(t_main *main);
int						anothertry(t_main *main);
int						spacenoplus(t_main *main);
int						no_conv(t_main *main);
void					the_plus(t_main *main, va_list *myva);
void					the_star(t_main *main, va_list *myva);
void					all_finded(t_main *main);
void					the_space(t_main *main);
void					zero_arg(t_main *main, va_list *myva);
void					die_arg(t_main *main, va_list *myva);
void					moin_arg(t_main *main, va_list *myva);
int						find(t_main *main, char tofind);
void					first(t_main *main);
void					last_mini(t_main *main);
void					one_else(t_main *main, int needzero);
void					ok_ok(t_main *main, int needzero);
void					another_else(t_main *main, int needzero);
void					ok_its_norme(t_main *main, int needzero);
void					in_nor(t_main *main);
void					hai_hai(t_main *main, int needzero);
int						add_mini(t_main *main);
int						okorno(t_main *main);
void					first_width(t_main *main);
void					second_mask(wint_t mycarac, t_main *main);
void					three_mask(wint_t mycarac, t_main *main);
void					four_mask(wint_t mycarac, t_main *main);
void					prem_mask(t_main *main, wint_t mycarac);
void					sec_mask(t_main *main, wint_t mycarac);
void					tre_mask(t_main *main, wint_t mycarac);
void					fo_mask(t_main *main, wint_t mycarac);
#endif
