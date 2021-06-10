#include "include/ft_printf.h"
#define PRINT printf
#define PRINTF printf
#define FT_PRINT ft_printf

int main()
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	int count;

	count = 0;
	// ft_printf("%d\n", ft_printf("%s: %d\n", "here we go again", 100));
	// ft_printf("%d\n", ft_printf("%20s\n", "here we go again"));
	// ft_printf("%d\n", ft_printf("%-20s\n", "here we go again"));
	// count = ft_printf("%c\n", 'a');
	// printf("count: %d\n", count);
	// count = ft_printf("%20c\n", 'a');
	// printf("count: %d\n", count);
	// count = ft_printf("%-20c\n", 'a');
	// printf("count: %d\n", count);
	// PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d));
	// PRINT(" --- Return : %d\n", FT_PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d));

	// PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T1
	// PRINT(" --- Return : %d\n", FT_PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T1
	// PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T1
	// PRINT(" --- Return : %d\n", FT_PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d)); //T1
	// printf("%-0d\n", -12);
	// ft_printf("%-0d\n", -12);

	// PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	// printf("%*d\n", -4, -12);
	// ft_printf("%*d\n", -4, -12);

	printf("%.*i\n", 3, -12);
	ft_printf("%.*i\n", 3, -12);
	exit(0);

	while (a < 5)
	{
		PRINTF("aaaaaaaaaaa: %d\n", a);
		PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT(" --- Return : %d\n", FT_PRINT("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT("-------------------------------------------------------------------------------------------\n");
		PRINT(" --- Return : %d\n", PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT(" --- Return : %d\n", FT_PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT("-------------------------------------------------------------------------------------------\n");
		PRINT(" --- Return : %d\n", PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT(" --- Return : %d\n", FT_PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT("-------------------------------------------------------------------------------------------\n");
		PRINT(" --- Return : %d\n", PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT(" --- Return : %d\n", FT_PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
		PRINT("-------------------------------------------------------------------------------------------\n");
		a++;
	}


	// printf("%1.d\n", 0);
	// ft_printf("%1.d\n", 0);
	return (0);
}
