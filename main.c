#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len;
	int	lenp;

	char	str = 'x';
	char	*str1 = "deneme";
	int		num = 42;

	len = ft_printf("--%c %s %d,%d,%s--\n",str,str1,num,100,"ve son");
	ft_printf("yazdirilan karakter sayisi : %d\n",len);
	return (0);
}
