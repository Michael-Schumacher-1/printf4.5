/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeymond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:08:12 by sgeymond          #+#    #+#             */
/*   Updated: 2020/12/30 13:00:23 by sgeymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_base_p3(t_p *p, char *base, int d)
{
	while (p->pow > -1)
	{
		while ((p->lenght_base - 1) *
			ft_power(ft_strlen(base), p->pow) > p->nmb)
			p->lenght_base--;
		if (d == 0 && base[p->lenght_base - 1] == '0')
			d = 0;
		else
		{
			ft_putchar(base[p->lenght_base - 1]);
			d = 1;
		}
		p->nmb = p->nmb - ((p->lenght_base - 1) *
		ft_power(ft_strlen(base), p->pow));
		p->lenght_base = ft_strlen(base);
		p->pow--;
	}
}

int		ft_putnbr_base_p2(t_p *p, char *base, int a)
{
	int d;

	p->pow = 0;
	p->nb0 = 0;
	p->zero = 0;
	d = 0;
	if (a == 7)
	{
		ft_putstr("0x");
		p->zero = p->na - ft_putnbr_base_p2(p, "0123456789abcdef", 2);
		while (p->nb0++ < p->zero)
			ft_putchar('0');
		p->nb0--;
	}
	while (p->testc / p->lenght_base > 0)
	{
		p->pow++;
		p->testc = p->testc / p->lenght_base;
	}
	p->testc = p->nmb;
	if (a == 2)
		return (p->pow + 1);
	(p->pow > 11) ? ft_putnbr_base_x(p, "0123456789abcdef", 8)
	: ft_putnbr_base_p3(p, base, d);
	return (p->nmb + 1);
}

int		ft_putnbr_base_p(t_p *p, char *base, int a)
{
	p->nmb = p->testc;
	p->lenght_base = ft_strlen(base);
	p->pow = 0;
	p->testc = p->nmb;
	if (p->testc == 0 && a == 3)
		ft_putstr("0x");
	else if (base_is_valid(base) == 0)
		return (ft_putnbr_base_p2(p, base, a));
	return (p->nmb + 1);
}
