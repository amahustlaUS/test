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
