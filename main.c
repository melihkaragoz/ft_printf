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
	len = ft_printf("s : %s, c = %c, d: %d, p : %p, u : %u, u1 : %u\n",str1,str,num,&str,un,-1);
	ft_printf("ft yazdirilan karakter sayisi : %d\n\n\n",len);
	len = printf("s : %s, c = %c, d: %d, p : %p, u : %u, u1 : %u\n",str1,str,num,&str,un,-1);
	printf("yazdirilan karakter sayisi : %d\n\n\n",len);
	//len = ft_printf("%u, %u, %u, %u, %u, %u, %u \n",INT_MAX,INT_MIN,LONG_MAX,LONG_MIN,UINT_MAX,ULONG_MAX,9223372036854775807LL);
	//lenp = printf("%u, %u, %u, %u, %u, %u, %u \n",INT_MAX,INT_MIN,LONG_MAX,LONG_MIN,UINT_MAX,ULONG_MAX,9223372036854775807LL);
	//printf("ft : %d, p : %d",len,lenp);
	return (0);
}
