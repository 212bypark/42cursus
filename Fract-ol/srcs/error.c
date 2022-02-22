#include "../include/error.h"
#include "../include/fractol.h"

void	ft_error(int error_code)
{
	if (error_code == ERR_CODE)
		printf("ERROR\n");
	if (error_code == ERR_ALLOC)
		printf("ALLOCTION FAIL\n");
	if (error_code == ERR_FRAC)
		printf("1. Mandelbrot\n2. Julia\n3. Burningship\n");
	exit(0);
}
