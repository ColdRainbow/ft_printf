/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_dipouxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:01:51 by jkate             #+#    #+#             */
/*   Updated: 2021/01/20 19:01:53 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	string_dipouxx_puts_minus(t_format *format, char *str, int size, unsigned int value)
{
	int		i;
	char	ch_filler;

	ch_filler = format->zero ? '0' : ' ';
	// format->num_set->value_len = numlen_base(value, format->num_set->base) + format->num_set->value_neg;
	// printf("width: %d\n", format->width);
	// printf("%d\n", size);
	if (format->num_set->value_neg)
		str[0] = '-';
	// printf("%d\n", format->num_set->value_len + format->num_set->value_neg - 1);
	if (!format->num_set->special_case)
	{
		if (format->type == 'x')
			itoa_base(str, value, format->num_set->base, format->num_set->value_len + format->num_set->value_neg - 1, LOW_HEX_BASE);
		else
			itoa_base(str, value, format->num_set->base, format->num_set->value_len + format->num_set->value_neg - 1, UPPER_HEX_BASE);
	}
	i = format->num_set->value_len + format->num_set->value_neg;
	// printf("%d\n", format->num_set->value_len);
	while (i < size)
	{
		if (format->width > 0)
		{
			str[i] = ch_filler;
			format->width--;
		}
		else if (format->precision > 0)
		{
			str[i] = '0';
			format->precision--;
		}
		i++;
	}
}

void	string_dipouxx_puts(t_format *format, char *str, int size, unsigned int value)
{
	int		i;
	int		temp_size;
	char	ch_filler;

	i = 0;
	temp_size = size - 1;
	ch_filler = format->zero ? '0' : ' ';
	// format->num_set->value_len = numlen_base(value, format->num_set->base);
	// printf("precision: %d\n", format->precision);
	printf("kekekke: %d\n", size - (format->num_set->value_len + format->num_set->value_neg));
	while (i < size - (format->num_set->value_len + format->num_set->value_neg))
	{
		if (format->width > 0)
		{
			str[i] = ch_filler;
			format->width--;
		}
		i++;
	}
	if (format->num_set->value_neg)
		str[i++] = '-';
	while (i < size - (format->num_set->value_len + format->num_set->value_neg))
	{
		if (format->precision > 0)
		{
			str[i] = '0';
			format->precision--;
		}
		i++;
	}
	if (format->num_set->special_case)
		return ;
	// printf("\nbase: %d\n", format->num_set->base);
	// printf("\nis neg: %d\n", format->num_set->value_neg);
	// printf("\nkek: %d\n", format->num_set->value_len + i - 1);
	if (format->type == 'x')
		itoa_base(str, value, format->num_set->base, format->num_set->value_len + i - 1, LOW_HEX_BASE);
	else
		itoa_base(str, value, format->num_set->base, format->num_set->value_len + i - 1, UPPER_HEX_BASE);
}

void	string_dipouxx_create(t_format *format, unsigned int value, char **str)
{
	int	amount;

	// определяем длину числа с учетом знака
	format->num_set->value_len = numlen_base(value, format->num_set->base) + format->num_set->value_neg;

	// если указана точность или минус - зануляем флаг 0
	if (format->precision >= 0 || format->minus)
		format->zero = 0;

	// особый ебучий кейс
	// если точность %.d и число 0, то 0 - не выводим!
	if (!format->precision && !value) 
	{
		format->num_set->special_case = 1;
		format->num_set->value_len--;
	}

	if (format->width > format->precision)
	{
		amount = format->width;
		if (format->num_set->value_len >= format->precision)
		{
			format->width -= format->num_set->value_len;
			format->precision = -1;
		}
		else
		{
			format->width -= format->precision;
			format->precision -= format->num_set->value_len;
		}
	}
	else
	{
		amount = format->precision + format->num_set->value_neg;
		format->precision = format->precision - (format->num_set->value_len - format->num_set->value_neg);
		// printf("prec: %d\n", format->precision);
		// printf("prec: %d\n", amount);
		format->width = 0;
	}
	if (format->num_set->value_len > amount)
	{
		amount = format->num_set->value_len;
		format->width = 0;
		format->precision = -1;
	}
	// printf("prec: %d\n", format->precision);
	// printf("kek: %d\n", amount);
	if (!(*str = (char *)calloc(amount + 1, sizeof(char))))
		return ;
	bzero(*str, amount + 1);
	format->num_set->value_len = format->num_set->value_len - format->num_set->value_neg; // убираем минус из длины
	if (format->minus)
		string_dipouxx_puts_minus(format, *str, amount, value);
	else
		string_dipouxx_puts(format, *str, amount, value);
	set_amount(amount);
}
