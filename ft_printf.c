/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:45:58 by sylvain           #+#    #+#             */
/*   Updated: 2020/12/30 13:57:02 by sgeymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_write_data(t_p *p, const char *format)
{
	p->l = 0;
	p->i++;
	while (format[p->i - 1] != 'c' && format[p->i - 1] != 'd' &&
		format[p->i - 1] != 'i' && format[p->i - 1] != 'p' &&
	format[p->i - 1] != 's' && format[p->i - 1] != 'u' && format[p->i - 1] !=
		'x' && format[p->i - 1] != 'X' && format[p->i] != '\0' && p->l == 0)
	{
		if (format[p->i] == '-' || format[p->i] == '%')
			ft_negative(p, format);
		if (format[p->i] == 'c' || format[p->i] == 'd' || format[p->i] == 'i'
		|| format[p->i] == 'p' || format[p->i] == 's' || format[p->i] == 'u' ||
				format[p->i] == 'x' || format[p->i] == 'X')
			ft_letters(p, format);
		if ((format[p->i] > '0' && format[p->i] <= '9') ||
				(format[p->i] == '*'))
			ft_number_or_star(p, format);
		if (((format[p->i] == '0') && ((format[p->i - 1] < '0') ||
			(format[p->i - 1] > '9')) && (((format[p->i + 1] >= '0' &&
			format[p->i + 1] <= '9') || format[p->i + 1] == '*'))))
			ft_zero(p, format);
		if (format[p->i] == '.')
			ft_point(p, format);
		(format[p->i] == ' ') ? ft_putchar(' ') : 0;
		p->i++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_p	*p;

	if (!(p = malloc(sizeof(t_p))))
		return (0);
	p->i = 0;
	p->l = 0;
	g_nbrchar = 0;
	va_start(p->list, format);
	while (format[p->i] != '\0')
	{
		p->k = 0;
		p->na = 0;
		p->nb = 0;
		p->d = 0;
		p->e = 0;
		if (format[p->i] == '%')
			ft_write_data(p, format);
		else
			ft_putchar(format[p->i++]);
	}
	va_end(p->list);
	free(p);
	return (g_nbrchar);
}
