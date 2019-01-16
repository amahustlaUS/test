/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_own_count_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anerus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:29:58 by anerus            #+#    #+#             */
/*   Updated: 2018/11/08 19:53:01 by anerus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(const char *s, char c)
{
	size_t		j;
	size_t		i;

	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			j++;
		i++;
	}
	return (j);
}