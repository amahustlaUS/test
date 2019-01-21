#include "ft_printf.h"

void	dig(const char *str)
{
	long	tmp;

	tmp = va_arg(g_g.ap, long long);
	g_g.str = ft_itoa(tmp);
	// if (g_g.mod != L)
	if (g_g.mod == mod_hh)
		g_g.str = ft_itoa((char)tmp);
	else if (g_g.mod == mod_h)
		g_g.str = ft_itoa((short)tmp);
	else if (g_g.mod == mod_clear)
		g_g.str = ft_itoa((int)tmp);
	else if (g_g.mod == mod_ll)
		g_g.str = ft_itoa((long long) tmp);
	else if (g_g.mod == mod_l)
		g_g.str = ft_itoa((long) tmp);
		print_dig();
	free(g_g.str);
}

void	print_dig(void)
{
	precision_and_sign();
	if (g_g.flg.zero)
	{
		print_sign();
		print_width();
		g_g.ret += write(1, g_g.str, ft_strlen(g_g.str));
	}
	else if (g_g.flg.minus)
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
		if (g_g.flg.negative)
		g_g.ret += write(1, "-", 1);
	else if(g_g.flg.plus)
		g_g.ret += write(1, "+", 1);
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
	if (g_g.flg.plus || g_g.flg.space || g_g.flg.negative)
		g_g.flg.width--;
	while(g_g.flg.width - len++ && len <= g_g.flg.width)
	{
		g_g.ret += g_g.flg.zero ? write(1, "0", 1) :
		 write(1, " ", 1);
	}
}
void	assign_digit(const char *str)
{
	str[g_g.i] >= 'L' && str[g_g.i] <= 'z' ? validate_mods(str) : 0;
	str[g_g.i] == ' ' ? g_g.flg.space = 1 : 0;//	done
	str[g_g.i] == '#' ? g_g.flg.hash = 1 : 0;
	str[g_g.i] == '0' ? g_g.flg.zero = 1 : 0;
	str[g_g.i] == '-' ? g_g.flg.minus = 1 : 0;//	done
	str[g_g.i] == '+' ? g_g.flg.plus = 1 : 0;//		done
	// str[g_g.i] == '*' ? validate_width(g_g) : 0;
}