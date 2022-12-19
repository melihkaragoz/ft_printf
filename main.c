#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("%x\n",LONG_MAX);
	printf("%x\n",LONG_MAX);
	return (0);
}
