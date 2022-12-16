#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len;
	int	lenp;

	char *str = "melih";
	char *str1 = "deneme";
	len = ft_printf("%s %s\n",str,str1);
	//lenp = printf("melih");
	return (0);
}
