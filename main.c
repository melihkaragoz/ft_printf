#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	len;
	int	lenp;

	char	str = 'x';
	char	*str1 = "deneme";
	int		num = 5;
	unsigned int un = 1231231234;

	printf("\n\n");
	len = ft_printf("u1 : %u\n",un);
	ft_printf("ft yazdirilan karakter sayisi : %d\n\n\n",len);
	len = printf("u1 : %u\n",un);
	printf("yazdirilan karakter sayisi : %d\n\n\n",len);
	return (0);
}
