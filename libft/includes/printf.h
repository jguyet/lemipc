/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:11:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/12 19:16:09 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# ifdef PRINTF_PROG

#  include <libft.h>
#  include <stdio.h>
#  include <unistd.h>
#  include <wchar.h>

#  define BUFF_SIZE 8192

typedef enum				e_printf_conversion
{
	percent = 0,
	s,
	big_s,
	p,
	d,
	big_d,
	i,
	o,
	big_o,
	u,
	big_u,
	x,
	big_x,
	c,
	big_c,
	b,
	big_b,
	f,
	big_f,
	conversion_len
}							t_printf_conversion;

typedef union				u_number
{
	unsigned long long int	longlong;
	unsigned long int		word;
	double					longdouble;
}							t_number;

typedef struct				s_printf_flag
{
	t_bool					is_negative;
	t_number				number;
	int						base;
	t_bool					alt;
	t_bool					space;
	t_bool					left;
	t_bool					showsign;
	t_bool					group;
	t_bool					is_long_double;
	t_bool					is_short;
	t_bool					is_long;
	t_bool					is_char;
	int						width;
	int						prec;
	char					pad;
	char					spec;
}							t_printf_flag;

typedef void				(*t_ptr_flag_func)();

typedef struct				s_printf
{
	char					*buffer;
	unsigned int			buffer_size;
	int						len;
	va_list					args;
	t_printf_flag			flags;
	char					*work_buffer;
	t_ptr_flag_func			ptr_funcs[conversion_len];
}							t_printf;

/*
** HANDLER
*/
void						handle_printf_flags(t_printf *t, char *s);

/*
** INIT
*/
t_printf					*ini_printf(void);
void						ini_flags(t_printf *t);

/*
** ARGS
*/
char						arg_get_char(t_printf *t);
unsigned char				arg_get_uchar(t_printf *t);
wchar_t						arg_get_wchar(t_printf *t);
double						arg_get_double(t_printf *t);
long double					arg_get_longdouble(t_printf *t);
int							arg_get_int(t_printf *t);
unsigned int				arg_get_uint(t_printf *t);
unsigned long				arg_get_ulong(t_printf *t);
long int					arg_get_long_int(t_printf *t);
unsigned long int			arg_get_ulong_int(t_printf *t);
long long int				arg_get_long_long_int(t_printf *t);
unsigned long long int		arg_get_ulong_long_int(t_printf *t);
char						*arg_get_string(t_printf *t);
wchar_t						*arg_get_wstring(t_printf *t);
void						*arg_get_void(t_printf *t);

/*
** ADD TO BUFFER
*/
void						add_char(t_printf *t, unsigned char c);
void						add_string(t_printf *t, char *s);
void						add_wchar(t_printf *t, wchar_t c);
void						fill_character(t_printf *t, char c);

/*
** LABEL
*/
void						form_interger(t_printf *t);
void						form_percent(t_printf *t);
void						number_left(t_printf *t);
void						number(t_printf *t);
void						number_type(t_printf *t);

/*
** CONVERSION
*/
void						conversion_big_b(t_printf *t);
void						conversion_b(t_printf *t);
void						conversion_big_d(t_printf *t);
void						conversion_big_o(t_printf *t);
void						conversion_big_x(t_printf *t);
void						conversion_big_c(t_printf *t);
void						conversion_c(t_printf *t);
void						conversion_big_f(t_printf *t);
void						conversion_f(t_printf *t);
void						conversion_i(t_printf *t);
void						conversion_o(t_printf *t);
void						conversion_p(t_printf *t);
void						conversion_big_s(t_printf *t);
void						conversion_s(t_printf *t);
void						conversion_u(t_printf *t);
void						conversion_big_u(t_printf *t);
void						conversion_x(t_printf *t);

void						to_string(t_printf *t, char *s);
void						to_char(t_printf *t, char c);
void						to_wchar(t_printf *t, wchar_t c);

/*
** OTHERS
*/
size_t						strwlen_print(const wchar_t *s);
t_bool						flags(t_printf *t, char **s);
t_bool						modifiers(t_printf *t, char **s);
char						*wstr_to_str(t_printf *t, wchar_t *s);
char						*concat2(char *s1, int len1, char *s2, int len2);
char						*concat(char *s1, int *len1, char *s2, int len2);

/*
** COLORS
*/
#  define NRM  "\x1B[0m"
#  define RED  "\x1B[31m"
#  define GRN  "\x1B[32m"
#  define YEL  "\x1B[33m"
#  define BLU  "\x1B[34m"
#  define MAG  "\x1B[35m"
#  define CYN  "\x1B[36m"
#  define WHT  "\x1B[37m"
#  define BOL  "\e[1m"
#  define COLOR_ACTIVED 1

char						*modif_colors(char *string);

# endif

/*
** PROTOTYPES
*/
int							ft_printf(const char *format, ...);
int							ft_fprintf(int fd, const char *format, ...);
int							ft_asprintf(char **ptr, const char *format, ...);
char						*ft_sprintf(const char *format, ...);

#endif
