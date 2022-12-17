#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len;
	int	lenp;

	char	str = 'x';
	char	*str1 = "deneme";
	int		num = 5;

	len = ft_printf("isim : %s\nyas: %d\n%%%\ncinsiyet: %c\n %x, -- %X","melih",22,'e',123,123);
	ft_printf("yazdirilan karakter sayisi : %d\n",len);
	return (0);
}
