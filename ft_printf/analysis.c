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
	//	str[g_g.i] >= 'L' && str[g_g.i] <= 'z' ? validate_mods(str, g_g) : 0;
		str[g_g.i] == ' ' ? g_g.flg.space = 1 : 0;//	done
		str[g_g.i] == '#' ? g_g.flg.hash = 1 : 0;
		str[g_g.i] == '0' ? g_g.flg.zero = 1 : 0;
		str[g_g.i] == '-' ? g_g.flg.minus = 1 : 0;//	done
		str[g_g.i] == '+' ? g_g.flg.plus = 1 : 0;//		done
	//	str[g_g.i] == '*' ? validate_width(g_g) : 0;
	//	if (str[g_g.i] == '.')
	//		validate_precision(str, g_g);
		if (str[g_g.i] >= '1' && str[g_g.i] <= '9' && g_g.flg.prec <= 0)
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