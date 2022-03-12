/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bypark <bypark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 09:10:14 by bypark            #+#    #+#             */
/*   Updated: 2021/05/19 20:41:26 by bypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t		num;

	num = 0;
	while (*(str++) != '\0')
		num++;
	return (num);
}

static size_t	ft_strlcpy(char *dest, char *src, size_t size)
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

static size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	index;
	char	*s;

	s = (char *)src;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= size)
		return (len_src + size);
	if (size == 0)
		return (len_src);
	index = 0;
	while (s[index] != '\0' && index < (size - 1 - len_dest))
	{
		dest[len_dest + index] = s[index];
		index++;
	}
	dest[len_dest + index] = '\0';
	return (len_dest + len_src);
}

char			*ft_strjoin(char *s1, char *s2, int *flag)
{
	char	*str;
	int		err;

	err = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
	{
		str = ft_strdup(s2, &err);
		if (err)
			*flag = 1;
		return (str);
	}
	else if (!s2)
		return (s1);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		*flag = 1;
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(str, (char *)s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

char			*ft_strdup(char *s1, int *flag)
{
	char	*ptr;
	size_t	index;
	size_t	i;

	*flag = 0;
	index = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (index + 1))))
	{
		*flag = 1;
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
