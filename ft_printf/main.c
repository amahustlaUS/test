#include "ft_printf.h"

int main()
{
 int x1;
 int x2;

 // x = ft_printf("0123456789");

 	   x1 = printf("lld\n", 424242);
	x2 = ft_printf("lld\n", 424242);
	 	 printf ("---------------------------\n");
	printf("x1 = %d\nx2 = %d\n", x1, x2);
 // 	ft_printf("MY PRINTF:\ndigit(d) = %i\ndigit(i) = %i\nstring: %s \nchar: %c\npointer: %p\n", 666, 6,"awesome", 'c', &x);
 // 	printf("---------------------\n");
 // 	printf("ORIGINAL PRINTF:\ndigit(d) = %06d\ndigit(i) = %i\nstring: %s \nchar: %c\npointer: %p\n", 666333111, 6,"awesome", 'c', &x);
	// printf("---------------------\n");
	 // system("leaks ft_printft");
	return (0);
}
