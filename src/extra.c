/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:00:21 by jkate             #+#    #+#             */
/*   Updated: 2021/01/20 19:00:23 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			numlen_base(ssize_t num, int base)
{
	int i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num /= base;
		i++;
	}
	return (i);
}

/*
** я комментарий и ЕНТА функция меня заебала!
*/

void		itoa_base(char *str, ssize_t value, int base, int len, char letter)
{
	if (value == 0)
		str[len] = '0';
	while (value)
	{
		if (value % base >= 10)
			str[len] = value % base + letter - 10;
		else
			str[len] = value % base + '0';
		value /= base;
		len--;
	}
	// if (base == 16)
	// {
	// 	str[len] = 'x';
	// 	len--;
	// 	str[len] = '0';
	// }
	// else if (base == 8)
	// {
	// 	str[len] = '0';
	// }
}

void		clear_format_struct(void)
{
	t_format	*format;

	format = get_format_struct();
	bzero(format, sizeof(t_format));
	format->precision = -1;
	format->num_set->base = 10;
	format->fd = 1;
}

// int				minus;
// int				zero;
// int				width;
// int				precision;
// char			type;
// int				fd;
// t_num_settings	num_set[1];

// int				value_len;
// int				value_neg;
// int				special_case;
// int				base;

t_format	*get_format_struct(void)
{
	static t_format format = {
								0, //minus
								0, //zero
								0, //width
								-1, //prec
								0, //type
								1,
								{0, 0, 0, 10}};
	return (&format);
}

int			set_index(int i)
{
	static int p = 0;

	if (i > 0)
		p = i;
	return (p);
}

int			set_amount(int amount)
{
	static int num_sym = 0;

	if (amount > 0)
		num_sym = num_sym + amount;
	else if (amount == -1)
		num_sym = 0;
	return (num_sym);
}
