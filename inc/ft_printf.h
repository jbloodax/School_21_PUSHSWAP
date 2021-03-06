/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbloodax <jbloodax@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 21:07:11 by akraig            #+#    #+#             */
/*   Updated: 2020/01/30 17:48:01 by jbloodax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include "libft.h"

# define MAX(a,b) ((a > b) ? a : b)

#define INT 0					//without flags for d, i
#define SHORT (1 << 0)			//h
#define LONG (1 << 1)			//l for int
#define LONGLONG (1 << 2)		//ll
#define CHAR (1 << 4)			//hh

/*
**	type:
**	a - 0	hex in form 0xh.hhhhp+d (только C99)
**	A - 1	hex in form 0Xh.hhhhP+d (только C99)
**	c - 2	symbol	c
**	d - 3	decimal int	42
**	i - 4	decimal int 42
**	e - 5	exponent 2.21e4
**	E - 6	exponent 2.21E4
**	f - 7	float decimal
**	F - 8	float decimal, 
**	g - 9	shortest of %e or %f (truncates 0 at the end
**				and looks like rounds to 2 signs after decimal point)
**				C99: INF, INFINITY in case of infinity 
**				or NAN in case of not a number
**	G - 10	shortest of %E or %F (truncates 0 at the end
**				and looks like rounds to 2 signs after decimal point)
**	o - 11	octal unsigned
**	s - 12	sting (putstr)
**	u - 13	decimal unsigned
**	x - 14	hex unsigned (small letters)
**	X - 15	hex unsigned (capital letters)
**	p - 16	pointer
**	n - 17	pointer to store number of alredy outputed symbols before %n
**	% - 18	just % sign
**	< - BONUS ADD: repeat last argument
*/

typedef struct		s_parse
{
	char 			type;
	unsigned int	size;
	int				is_signed;
	int				spaces;
	char			*flags;
	int				width;
	int				prec;
	int				zero_prec;
	int 			skip_0_flag;
	int				E;
	/*
	Модификатор точности
	указывает на минимальное количество символов, которое должно появиться при обработке типов d, i, o, u, x, X;
	указывает на количество символов, которое должно появиться после десятичной запятой (точки) при обработке типов a, A, e, E, f, F;
	максимальное количество значащих символов для типов g и G;
	максимальное число символов, которые будут выведены для типа s;
	*/
	int				printed;
	int				length;
	char			*next;
	char			*buf;
	/* arguments */
	int64_t 		arg_i;
	double			arg_d;
	char			*arg_s;
}					t_parse;

/*
**	types
**  1     %с	Символ типа char
**  2     %d	Десятичное число целого типа со знаком
**  3     %i	Десятичное число целого типа со знаком
**  4     %е	Научная нотация (е нижнего регистра)
**  5     %Е	Научная нотация (Е верхнего регистра)
**  6     %f	Десятичное число с плавающей точкой
**  7     %g	Использует код %е или %f — тот из них, который
**              короче (при использовании %g используется е нижнего регистра)
**  8     %G	Использует код %Е или %f — тот из них, который
**              короче (при использовании %G используется Е верхнего регистра)
**  9     %о	Восьмеричное целое число без знака
**  10    %s	Строка символов
**  11    %u	Десятичное число целого типа без знака
**  12    %х	Шестнадцатиричное целое число без знака (нижний регистр)
**  13    %Х	Шестнадцатиричное целое число без знака (верхний регистр)
**  14    %р	Выводит на экран значение указателя
**  15    %n	указатель на переменную целого типа, в которую 
**              помещено количество символов, записанных на данный момент
*/

typedef struct      s_double
{
	char *special;
	char *sign;
	char *exp;
	char *mant;
}                   t_double;

typedef struct		s_lst
{
	char			type;
	int 			mod;
	char			*s;
	char			c;
	int				n;
	float			f;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_node;

int					ft_printf(const char *restrict s, ...);
t_parse				*parse_string(char *s, t_parse *params, va_list valist);
void				buffer(t_parse *p, char *s, int freeable);
void				print_char(char c, t_parse *p);
char				*print_float(double d, t_parse *p);
void				print_str(char *str, t_parse *p);
t_double			*new_double(double d);
int64_t				bin_to_dec(char *bin);
char				*get_fractional(t_double *num, t_parse *p);
char				*add_symbols(char *s, char c, size_t n, int is_after);
char				*read_color(t_parse *p, char *s, char *code);
char			    *read_width(t_parse *p, char *tmp, va_list valist);
char				*read_size(t_parse *p, char *tmp);
char				*read_flags(char *tmp, t_parse *p);
char				*read_prec(char *tmp, t_parse *p, va_list valist);
void				read_type(char *tmp, t_parse *p);
t_node				*new_piece(char type, int mod);
t_parse				*new_param(void);
void				clear_param(t_parse *p);
void				del_param(t_parse *p, va_list valist);
t_node				*add_last_piece(t_node **head, t_node *new);
int					int_length_and_update(int64_t n, t_parse *p);
int 	    		is_positive(int64_t n, t_parse *p);
void				add_sign(int64_t n, t_parse *p, char **num);
char   				*fill_width(t_parse *p, char *num, char sign);
char				*get_int(t_parse *p, int64_t n);
void				print_s_int(int64_t n, t_parse *p);
void				print_u_int(uint64_t n, t_parse *p);
void				print_int(int64_t n, t_parse *p);
char				*prepare_string(t_parse *p, int base, int64_t v);
void				print_base_u(uint64_t v, t_parse *p, int base);
int64_t				print_base(int64_t v, t_parse *p, int base);
void				print_percentage(t_parse *p);
void				print_arg(t_parse *p);
void			    get_and_print_arg(va_list valist, t_parse *p);
t_parse				*parse_string(char *tmp, t_parse *p, va_list valist);
void				buffer(t_parse *p, char *s, int freeable);
char				*read_line(t_parse *p, char *s);
char				*is_special_double(t_double num, char *mant);
char 				*float_e(char *intg, int prec, t_parse *p);
char 				*float_g(char *intg, char *fract, t_parse *p);
t_double 			*get_bits(double d, t_double *num);
t_double			 *new_double(double d);
void				free_double(t_double *num);
int64_t				bin_to_dec(char *bin);
int					find_last_digit(char *mant);
char 				*get_five_power(char *five_power, int power);
char 				*get_two_power(char *two_power, int power);
void				sum(char *summ, char *add);
void				sum2(char *summ, char *add);
char				*add_symbols(char *s, char c, size_t n, int is_after);
char				*round_fractional(char *fract, int prec, int is_int, t_parse *p);
char				*count_exp(t_double *num, int is_integer);
char				*get_fractional(t_double *num, t_parse *p);
char				*get_integer(t_double *num, t_parse *p);
char				*concat_parts(char *integer, char *fract, t_parse *p);

#endif
