#include "../include/pushswap.h"

void	ft_bzero(void *ptr, size_t num)
{
	while (num--)
		*((char *)ptr++) = 0;
}
