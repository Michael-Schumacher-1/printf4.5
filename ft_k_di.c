/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_k_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:45:17 by sylvain           #+#    #+#             */
/*   Updated: 2020/12/28 15:22:05 by sgeymond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_k_four(t_p *p)
{
	if (p->test < 0)
		p->m = 1;
	p->nl = number_lenght(p->test);
	if (p->nb - p->na > 0)
	{
		if (p->na < 0)
			p->n0 = p->nb - p->nl;
		else
			p->n0 = p->na - p->nl + p->m;
	}
	if (p->nb - p->na <= 0)
		p->n0 = (p->na - p->nl) + p->m;
	if (p->n0 < 0)
		p->n0 = 0;
}

void	ft_k_three_eight_nine_twelve_di(t_p *p)
{
	if ((p->k == 9 || p->k == 12) && (p->nb > 0 && p->na != 0))
		p->n0 = p->nb - p->nl;
	else if ((p->k == 9 || p->k == 12) && (p->nb == 0))
		p->n0 = p->na - p->nl - p->m;
	else
	{
		if (p->na > p->nl)
			p->n0 = p->na - p->nl;
		else if (p->nb > p->nl && (p->k == 9 || p->k == 12 || (p->k == 3 &&
						p->na < 0 && p->nb > 0 && p->d == 0 && p->e == 0)))
			p->n0 = p->nb - p->nl - p->m;
		else
			p->n0 = 0;
	}
}

void	ft_k_two_eight_di(t_p *p)
{
	if (p->m == 1)
		ft_putchar('-');
	if (p->n0 == 0)
		ft_putnbr(p->test);
}

void	ft_test_negative_di(t_p *p)
{
	p->test = p->test * -1;
	p->m = 1;
}
