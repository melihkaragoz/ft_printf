#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len;
	int	lenp;

	char str = 'x';
	char *str1 = "deneme";
	len = ft_printf("%c %s\n",str,str1);
	//lenp = printf("melih");
	return (0);
}
