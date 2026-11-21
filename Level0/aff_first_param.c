
/* === aff_first_param ===
 *
 * Write a program that takes strings as arguments, and displays its 
 * first argument followed by a newline. If the number of arguments is 
 * less than 1, the program displays a newline. */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc < 2)	// If less than 1 param
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] != '\0')	// Iterate through 1st param
    {
        write(1, &argv[1][i], 1);	// Write current character
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
