#include "ft_printf.h"
#include <libc.h>
int main()
{
	
	printf("rl : %0*.10d\n", 21, INT_MIN);
	ft_printf("my : %0*.10d\n",21, INT_MIN);
	
//printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
//ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
//TEST(17, print(" --0*%0*.0d*0 0*%0*.10d*0-- ", -21, INT_MAX, 21, INT_MIN));
		return (0);

}
