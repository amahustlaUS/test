#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	enum	e_mod
{
	mod_clear,
	mod_hh,
	mod_h,
	mod_l,
	mod_ll,
	mod_L,
	mod_z,
	mod_j,
	mod_t
}				t_mod;

typedef	struct	s_flg
{
	int		minus;
	int		plus;
	int		hash;
	int		zero;
	int		space;
	int		width;
	int		prec;
	int		negative;
}				t_flg;

typedef	struct	s_gen
{
	va_list		ap;
	t_mod		mod;
	t_flg		flg;
	int			i;
	int			ret;
	char		*str;
}				t_gen;

t_gen	g_g;

int		ft_printf(const char *format, ...);
void	solve_printf(const char *s);
void	flags_analys(const char *s);
void	handle_str(const char *str);
void	dig(const char *str);
void	print_dig(void);
void	print_sign(void);
void	print_width(void);
int		get_nbr_len(int n);
void	define_sign(void);
void	handle_precision(const char *str);
void	assign_digit(const char *str);
void	precision_and_sign(void);
void	validate_mods(const char *str);

#endif
