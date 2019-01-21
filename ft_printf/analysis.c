/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 22:58:31 by anerus            #+#    #+#             */
/*   Updated: 2019/01/13 22:58:55 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_analys(const char *str)
{
	while (ft_strchr(" .#0-+*Ljthlz123456789", str[g_g.i]))
	{
		assign_digit(str);
		if (str[g_g.i] == '.')
		{
			handle_precision(str);
			while (str[g_g.i] >= '0' && str[g_g.i] <= '9')
				g_g.i++;
		}
		else if (str[g_g.i] >= '1' && str[g_g.i] <= '9' && g_g.flg.prec <= 0)
		{
			g_g.flg.width = ft_atoi(str + g_g.i);
			while (str[g_g.i] >= '0' && str[g_g.i] <= '9')
				g_g.i += 1;
		}
		else if (!str[g_g.i])
			return ;
		else
			g_g.i++;
	}
}

void	handle_str(const char *str)
{
	if (str[g_g.i] == 'd' || str[g_g.i] == 'i')
	{
		//if(for precision if it >= 0)
		dig(str);
	}
}

void	handle_precision(const char *str)
{
	g_g.i++;
	if (str[g_g.i] >= '0' && str[g_g.i] <= '9')
		g_g.flg.prec = ft_atoi(str + g_g.i);
}