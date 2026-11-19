
/* === aff_a ===
 *
 * Write a program that takes a string, and displays the first 'a' character it
 * encounters in it, followed by a newline. If there are no 'a' characters in
 * the string, the program just writes a newline. If the number of parameters is
 * not 1, the program displays a newline. */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

	// If num of parameters is not 1, display newline and return
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
	// Iterate through characters
    while (argv[1][i] != '\0')
    {
		// If 'a' is found, display it and exit loop
        if (argv[1][i] == 'a')
        {
            write(1, "a", 1);
            break;
        }
		i++;
    }
	// Always display a newline at the end
    write(1, "\n", 1);
    return (0);
}
