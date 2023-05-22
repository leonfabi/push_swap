#include <stdio.h>

int	main(void)
{
	int	length = 100;
	int	a;
	int	b;
	int	c;

	a = 0;
	b = (length - a) / 3 + (length - a) % 3 + a;
	c = 2 * (length - a) / 3 + 2 * (length - a) % 3 + a;

	while (a < 97)
	{
		printf("Low third:\t%d - %d\n", a, b);
		printf("Middle third:\t%d - %d\n", b, c);
		printf("Upper third:\t%d - %d\n", c, length);
		a=c;
		b = (length - a) / 3 + (length - a) % 3 + a;
		c = 2 * (length - a) / 3 + 2 * (length - a) % 3 + a;
	}
	return (1);
}
