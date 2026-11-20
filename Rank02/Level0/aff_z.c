
/* === aff_z ===
 *
 * Write a program that takes a string, and displays the character 'z' 
 * followed by a newline. */

#include <unistd.h>

int	main(void)
{
	write(1, "z\n", 2);	// Write 2 bytes, not 1
	return (0);
}
