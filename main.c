#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len;
	int	lenp;

	char	str = 'x';
	char	*str1 = "deneme";
	int		num = 5;

	len = ft_printf("%p, %d, %s, %c",&num,num,str1,'x');
	ft_printf("yazdirilan karakter sayisi : %d\n",len);
	return (0);
}
