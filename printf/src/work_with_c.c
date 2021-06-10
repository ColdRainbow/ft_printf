/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:00:41 by jkate             #+#    #+#             */
/*   Updated: 2021/01/20 19:00:43 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	string_c_puts(t_format *format, char symbol)
{
	int i;
	int	amount;

	i = 0;
	if (format->width > 1)
		amount = format->width - 1;
	else
	{
		format->width = 0;
		amount = 1;
	}
	if (format->minus)
		write(format->fd, &symbol, 1);
	while (format->width)
	{
		write(format->fd, " ", 1);
		format->width--;
	}
	if (!format->minus)
		write(format->fd, &symbol, 1);
	set_amount(amount);
}
