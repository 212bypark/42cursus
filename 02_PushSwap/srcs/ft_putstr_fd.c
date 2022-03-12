#include "../include/pushswap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || s[0] == 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}
