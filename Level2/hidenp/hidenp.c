#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	j = 0;

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	// Iterate through the second string (with j++) in search of each character
	// in the first string (av[1][i]):
	// --> If the current char (av[1][i]) is found, then move to the next we want to look for (with i++)
	// --> Stop when you reach the end of either of the strings
	while (av[1][i] && av[2][j])
	{
		if (av[1][i] == av[2][j]) 
		{
			i++;
		}
		j++;
	}
	// If we reached the '\0' character in the first string,
	// it means we found all of its characters
	if (av[1][i] == '\0')
	{
		write(1, "1\n", 2);
	}
	else
	{
		write(1, "0\n", 2);
	}
	return (0);
}
