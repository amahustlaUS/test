#include "ft_printf.h"

void	mod_dig(const char *str)
{
	long	tmp;

	tmp = va_arg(g_g.ap, long);
	g_g.str = ft_itoa(tmp);
	// if (g_g.mod != L)
	if (g_g.mod == mod_clear)
	{
		print_dig();
	}
	free(g_g.str);
}

void	print_dig(void)
{
	if (g_g.flg.minus)
	{
		print_sign();
		g_g.ret += write(1, g_g.str, ft_strlen(g_g.str));
		print_width();
	}
	else
	{
		print_width();
		print_sign();
		g_g.ret += write(1, g_g.str, ft_strlen(g_g.str));
	}
	g_g.i++;
}

void	print_sign(void)
{
	if (g_g.flg.plus)
	{
		if(g_g.str[0] != '-')
		g_g.ret += write(1, "+", 1);
	}
	else if (g_g.flg.negative)
		g_g.ret += write(1, "-", 1);
	else if (g_g.flg.space)
		g_g.ret += write(1, " ", 1);
}

int	get_nbr_len(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n /= 10)
		i++;
	return (i);
}

void	print_width(void)
{
	int len;

	len = ft_strlen(g_g.str);
	if (g_g.str[0] != '-')
	if (g_g.flg.plus)
		g_g.flg.width--;
	while(g_g.flg.width - len++)
	{
		g_g.ret += write(1, " ", 1);
	}
}