#include "ft_printf.h"
#include <libc.h>
int main()
{
	
	//printf("rl : %0*.10d\n", 21, INT_MIN);
	//ft_printf("my : %0*.10d\n",21, INT_MIN);
	int i = -2147483648;
	//char *j = "assd";
	//ft_printf ("%-30d-\n", i);
	//printf("%-30d-\n", i);
	ft_printf ("%030d-\n", i);
	printf("%030d-\n", i);
	//ft_printf("%-30.10d-\n", i);
	//printf("%-30.10d-\n", i);
	ft_printf("%010.*d-\n", 20, i);
	printf("%010.*d-\n", 20, i);
	//ft_printf("%30.6d-\n", i);
	//printf("%30.5d-\n", i);

		int j = 12345;
	//char *j = "assd";
	/*ft_printf ("%-30d-\n", j);
	printf("%-30d-\n", j);
	ft_printf ("%030d-\n", j);
	printf("%030d-\n", j);
	ft_printf("%-30.10d-\n", j);
	printf("%-30.10d-\n", j);
	ft_printf("%030.5d-\n", j);
	printf("%030.5d-\n", j);
	ft_printf("%-30.0d-\n", j);
	printf("%-30.0d-\n", j);*/
		return (0);

}
