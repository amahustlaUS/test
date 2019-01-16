/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 18:01:51 by anerus            #+#    #+#             */
/*   Updated: 2019/01/08 18:03:30 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_printf(const char *s)
{
	g_g.flg.prec = -1;// instead of --> set_flgs(&g->flg);
	g_g.mod = mod_clear;
	flags_analys(s);
	if (!s[g_g.i])
		return ;
	//check_params(g);
	//parse_str(s, g);
	handle_str(s);
}

int		ft_printf(const char *format, ...)
{
	ft_bzero(&g_g, sizeof(g_g));
	va_start(g_g.ap, format);
	if (!format[g_g.i])
	    return (g_g.ret);
	while (format[g_g.i])
	{
		if (format[g_g.i] == '%' && !format[g_g.i + 1])
			return (g_g.ret);
		else if (format[g_g.i] == '%' && format[g_g.i + 1] != '%')
		{
		    g_g.i++;
			solve_printf(format);
			// g_g.i++;
		}
		else if (format[g_g.i] == '%' && format[g_g.i + 1] == '%')
		{
			g_g.ret += write(1, "%", 1);
			g_g.i += 2;
		}
		else
		{
			g_g.ret += write(1, &format[g_g.i], 1);
			g_g.i++;
		}
	}
	va_end(g_g.ap);
	return (g_g.ret);
}
