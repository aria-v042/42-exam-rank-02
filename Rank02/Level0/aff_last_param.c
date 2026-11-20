
/* === aff_last_param ===
 *
 * Write a program that takes strings as arguments, and displays its 
 * last argument followed by a newline. If the number of arguments is 
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
    while (argv[argc - 1][i] != '\0')	// Last param is argv[argc - 1]
    {
        write(1, &argv[argc - 1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
