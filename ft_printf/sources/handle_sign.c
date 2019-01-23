#include "ft_printf.h"

void	define_sign(void)
{
	char *tmp;

	if (g_g.str[0] == '-' && g_g.str)
	{
		g_g.flg.negative = 1;
		tmp = ft_strdup(g_g.str + 1);
		free(g_g.str);
		g_g.str = tmp;
	}
}

void	precision_and_sign(void)
{
	int len;
	char *tmp;
	int i;

	define_sign();
	len = ft_strlen(g_g.str);
	if (g_g.flg.prec == 0 && g_g.str[0] == 0)
		g_g.str[0] = '\0';
	else if (g_g.flg.prec > len)
	{
		i = g_g.flg.prec - len;
		while (i--)
		{
			tmp = g_g.str;
			g_g.str = ft_strjoin("0", g_g.str);
			free(tmp);
		}
	}
}

void	validate_mods(const char *str)
{
	if (str[g_g.i] == 'h' && str[g_g.i + 1] != 'h' && g_g.mod == mod_clear)
		g_g.mod = mod_h;
	else if (str[g_g.i] == 'h' && str[g_g.i + 1] == 'h' && g_g.mod == mod_clear)
	{
		g_g.mod = mod_hh;
		g_g.i++;
	}
	else if (str[g_g.i] == 'l' && str[g_g.i + 1] != 'l')
		g_g.mod = mod_l;
	else if (str[g_g.i] == 'l' && str[g_g.i + 1] == 'l')
	{
		g_g.mod = mod_ll;
		g_g.i++;
	}
	// else if (s[g_g.i] == 'L')
	// 	g_g.mod = arg_L;
	// else if (s[g_g.i] == 'j')
	// 	g_g.mod = arg_j;
	// else if (s[g_g.i] == 'z')
	// 	g_g.mod = arg_z;
	// else if (s[g_g.i] == 't')
	// 	g_g.mod = arg_t;
}
