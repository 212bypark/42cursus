/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:14:13 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 12:14:20 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	count;
	char	*s;

	index = 0;
	count = 0;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	while (src[count] != 0)
		count++;
	if (size != 0)
	{
		while (s[index] != '\0' && index < size - 1)
		{
			dest[index] = s[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (count);
}
