/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 06:01:20 by jkate             #+#    #+#             */
/*   Updated: 2021/01/23 06:01:23 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* не забыть удалить отсюда всякую  xуяту */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <strings.h>

# define LOW_HEX_BASE	'a'
# define UPPER_HEX_BASE	'A'

# define TYPE_HEXICAL	16
# define TYPE_DECIMAL	10
# define TYPE_OCTAL		8
# define TYPE_BINARY		2

/*
** BASE is 10 by default
** special_case is when precision is 0 (%.d) and value in 0
** we should not print THE VALUE (ZERO)
*/

typedef struct		s_num_settings
{
	int				value_len;
	int				value_neg;
	int				special_case;
	int				base;
}					t_num_settings;

/*
** FD is 1 by default
** PRECISSION is -1 by default
*/

typedef struct		s_format
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	char			type;
	int				fd;
	t_num_settings	num_set[1];
}					t_format;

int					ft_printf(const char *line, ...);
int					parse_specifiers(t_format *format, va_list ap, const char *line);

/* D I P O U X X */
void				parse_dipouxx(t_format *format, char **str, va_list ap);
void				string_dipouxx_create(t_format *format, unsigned int value, char **str);
void				string_dipouxx_puts(t_format *format, char *str, int size, unsigned int value);

/* S C */
void				parse_cs(t_format *format, char **str, va_list ap);
void				string_c_puts(t_format *format, char symbol);
void				string_s_create(t_format *format, char **str, char *line);
void				string_s_puts(t_format *format, char *str, char *line, int amount);
void				string_s_puts_minus(t_format *format, char *str, char *line, int amount);

void				parse_puxx(t_format *format, char **str, va_list ap);
void				string_puxx_create(t_format *format, unsigned int value, char **str);
void				string_puxx_puts(t_format *format, char *str, int size, unsigned int value);

/* EXTRA */
int					numlen_base(ssize_t num, int base);
void				itoa_base(char *str, ssize_t value, int base, int len, char letter);
void				clear_format_struct(void);
t_format			*get_format_struct(void);
int					set_index(int i);
int					set_amount(int amount);

/* debug */
void				debug_shit(t_format *format);

#endif
