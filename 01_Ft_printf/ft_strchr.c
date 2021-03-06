/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:04:15 by bypark            #+#    #+#             */
/*   Updated: 2021/06/23 12:14:50 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*str;

	index = 0;
	str = (char *)s;
	while (str[index] != (unsigned char)c)
	{
		if (str[index] == '\0')
			return (NULL);
		index++;
	}
	return (&((char *)s)[index]);
}
