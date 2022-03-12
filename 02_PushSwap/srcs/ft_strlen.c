#include "../include/pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t		num;

	num = 0;
	while (*(str++) != '\0')
		num++;
	return (num);
}
