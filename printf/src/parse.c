/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:00:02 by jkate             #+#    #+#             */
/*   Updated: 2021/01/20 19:00:06 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		parse_specifiers(t_format *format, va_list ap, const char *line)
{
	int i;

	i = 0;

	// ZERO
	if (line[i] && line[i] == '0')
	{
		format->zero = 1;
		i++;
	}

	// MINUS
	if (line[i] && line[i] == '-')
	{
		format->minus = 1;
		i++;
	}

	// WIDTH
	if (line[i] && (line[i] == '*' || (line[i] >= '0' && line[i] <= '9')))
	{
		if (line[i] == '*')
		{
			format->width = va_arg(ap, int);
			if (format->width < 0)
			{
				format->width = format->width * -1;
				format->minus = 1;
			}
			i++;
		}
		else
		{
			format->width = atoi(line + i);
			while (line[i] && line[i] >= '0' && line[i] <= '9')
				i++;
		}
	}

	// ACCURACY
	if (line[i] && line[i] == '.')
	{
		i++;
		if (line[i] && line[i] == '*')
		{
			format->precision = va_arg(ap, int);
			i++;
		}
		else
		{
			format->precision = atoi(line + i);
			while (line[i] && line[i] >= '0' && line[i] <= '9')
				i++;
		}
	}

	// TYPE
	if (line[i] && (line[i] == 'c' || line[i] == 's' || line[i] == 'd' || line[i] == 'i' || line[i] == 'x' || line[i] == 'X' || line[i] == 'u' || line[i] == 'p'))
	{
		if (line[i] == 'x' || line[i] == 'X' || line[i] == 'p')
			format->num_set->base = TYPE_HEXICAL;
		format->type = line[i];
		i++;
		set_index(i);
		return (1);
	}
	return (0);
}

void	parse_cs(t_format *format, char **str, va_list ap)
{
	char *line;
	char symbol;

	if (format->type == 'c')
	{
		symbol = (char)va_arg(ap, int);
		string_c_puts(format, symbol);
	}
	else
	{
		line = va_arg(ap, char *);
		string_s_create(format, str, line);
	}
}

void	parse_dipouxx(t_format *format, char **str, va_list ap)
{
	int				value;
	unsigned int	unvalue;

	if (format->type == 'd' || format->type == 'i')
	{
		value = va_arg(ap, int);
		if (value < 0)
		{
			unvalue = value * -1;
			format->num_set->value_neg = 1;
		}
		else
			unvalue = value;
	}
	else
		unvalue = va_arg(ap, unsigned int);
	string_dipouxx_create(format, unvalue, str);
}
