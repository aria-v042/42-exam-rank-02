#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	a;
	int	b;

	// If parameters is not 2, display newline and exit
	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	// Convert parameters to int using atoi()
	a = atoi(av[1]);
	b = atoi(av[2]);
	// Use Euclid's algorithm to find the greatest common divisor
	// --> when a=0, gcd is the value in b
	while (a != 0)
	{
		int temp = a;
		a = b % a;
		b = temp;
	}
	// print GCD (in b) using printf()
	printf("%d\n", b);
	return (0);
}
