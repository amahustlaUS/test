/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 04:04:46 by anerus            #+#    #+#             */
/*   Updated: 2018/10/28 04:26:55 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(s1);
	while (s2[++i] && i < (int)n)
		s1[len++] = s2[i];
	s1[len] = '\0';
	return (s1);
}
