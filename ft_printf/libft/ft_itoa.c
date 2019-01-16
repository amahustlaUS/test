/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:03:45 by anerus            #+#    #+#             */
/*   Updated: 2018/11/08 16:30:07 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	big_dig;

	len = get_str_len(n);
	big_dig = n;
	if (n < 0)
	{
		big_dig = -n;
		len++;
	}
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	str[--len] = big_dig % 10 + '0';
	while (big_dig /= 10)
		str[--len] = big_dig % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
