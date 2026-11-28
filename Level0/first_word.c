
/* === first_word ===
 *
 * Write a program that takes a string and displays its first word, 
 * followed by a newline. A word is a section of string delimited by 
 * spaces/tabs or by the start/end of the string. If the number of 
 * parameters is not 1, or if there are no words, simply display a 
 * newline. */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac != 2)	// If not 1 param
	{
		write(1, "\n", 1);
		return (0);
	}
	// Skip leading spaces/tabs - reach 1st word or end of string
	while (av[1][i] == ' ' || av[1][i] == '\t')
	{
		i++;
	}
	// Write each character until a space/tab or end of string
	while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
	{
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);	// Always write a newline at the end
	return (0);
}
