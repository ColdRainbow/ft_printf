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

// void	string_s_puts_minus(t_format *format, char *str, char *line)
// {
// 	int		i;
// 	int		j;
// 	int		amount;
// 	char	space;

// 	i = 0;
// 	j = 0;
// 	space = ' ';
// 	amount = format->width + format->precision;
// 	while (i < format->precision)
// 	{
// 		str[i] = line[j++];
// 		i++;
// 	}
// 	while (i < amount)
// 	{
// 		str[i++] = space;
// 	}
// }

// void	string_s_puts(t_format *format, char *str, char *line)
// {
// 	int		i;
// 	int		j;
// 	int		amount;

// 	i = 0;
// 	j = 0;
// 	printf("AAAAAAAAAA\n");
// 	amount = format->precision + format->width;
// 	printf("the: %d\n", amount);
// 	printf("width: %d\n", format->width);
// 	while (i < format->width)
// 	{
// 		str[i] = ' ';
// 		i++;
// 	}
// 	while (i < amount)
// 	{
// 		str[i] = line[j];
// 		i++;
// 		j++;

// 	}
// 	printf("AAAAAAAAAA\n");
// }

/*
void	string_s_create(t_format *format, char **str, char *line)
{
	int		amount;
	int		l_len;

	l_len = strlen(line);
	amount = format->width;
//a = b
	if (format->width == format->precision)
	{
		amount = format->precision;
		format->width = 0;
	}
//a < b > c, a < c
//6) если ширина меньше длины слова и меньше точности, но точность больше длины слова
//-> выводим слово
	if (format->width < l_len && format->width < format->precision
	&& format->precision > l_len)
	{
		format->width = 0;
		format->precision = l_len;
		amount = l_len;
	}
//a > b < c, a > c
//a > b < c, a < c
//14) если ширина больше длины слова и больше точности, но точность меньше длины слова 
//-> отрезать от слова кол-во символов до точности, 
//-> добавить количество пробелов до ширины
	else if (format->width > format->precision && format->precision < l_len)
		format->width = format->width - format->precision;
//a > b > c
//23) если ширина больше длины слова и больше точности, но точность больше длины слова
//-> вывести слово
//-> добавить количество пробелов до ширины
//a < b > c, a > c
//23) если ширина больше длины слова и меньше точности, но точность больше длины слова
//-> вывести слово
//-> добавить количество пробелов до ширин
	else if (format->width > l_len && format->precision > l_len)
	{
		format->width = format->width - l_len;
		format->precision = l_len;
	}
//a < b < c
//5) если ширина меньше длины слова и меньше точности, но точность меньше длины слова
//-> игнорируем ширину, отрезаем от слова кол-во символов до точности
	else if (format->width < l_len && format->width < format->precision
	&& format->precision < l_len)
	{
		format->width = 0;
		amount = format->precision;
	}
	l_len = format->precision;
	*str = (char *)calloc(format->precision, sizeof(char));
	printf("Amount is %d\n", amount);
	printf("Width is %d\n", format->width);
	printf("Precision is %d\n", format->precision);
	printf("L_len is %d\n", l_len);*/
	// if (format->minus == 1)
		// string_s_puts_minus(format, *str, line);
	// else
		// string_s_puts(format, *str, line);
// }

void	string_s_puts_minus(t_format *format, char *str, char *line, int amount)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (i < amount - format->width)
		str[i++] = line[n++];
	while (i < amount)
		str[i++] = ' ';
}

void	string_s_puts(t_format *format, char *str, char *line, int amount)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	// printf("width: %d\n", format->width);
	// printf("amount: %d\n", amount);
	while (i < format->width)
		str[i++] = ' ';
	while (i < amount)
		str[i++] = line[n++];
	// printf("test: %s\n", str);
}

void	string_s_create(t_format *format, char **str, char *value_str)
{
	int	amount;

	amount = 0;
	if (format->precision < 0)
		amount = strlen(value_str);
	else
		amount = format->precision;
	if (format->width < amount)
		format->width = 0;
	else
		format->width = format->width - amount;
	amount = format->width + amount;
	if (!(*str = (char *)calloc(amount + 1, sizeof(char))))
		return ;
	bzero(*str, amount + 1);
	if (format->minus)
		string_s_puts_minus(format, *str, value_str, amount);
	else
		string_s_puts(format, *str, value_str, amount);
	set_amount(amount);
}

/*если точность есть (включая ноль, или если просто стоит точка (это тоже ноль (%.s))), то строка обрезается по точности 
if (precison == -1) // точноть не задана
	str_len = str_len;
else
	str_len = precision;

if (width < str_len)
{
	//нам похуй
	// p.s. оказывается, не совсем похуй...
	// нужно ширину занулить в этом случае
}
if (width > str_len)
{
	width = width - str_len;
}
amount = width + str_len;
calloc бла бла бла....*/