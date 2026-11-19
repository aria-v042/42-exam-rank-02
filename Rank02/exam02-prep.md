# Exam Rank 02 - Preparation Guide

**Compile:** `cc -Wall -Wextra -Werror <file.c>`
**Test:** `./a.out [arguments...]`

## Level 1

### aff_a

**Expected files:** aff_a.c | **Allowed functions:** write

Write a program that takes a string, and displays the first 'a' character it encounters in it, followed by a newline. If there are no 'a' characters in the string, the program just writes a newline. If the number of parameters is not 1, the program displays a newline.

Example:
\$> ./aff_a "abc" | cat -e
a\$
\$> ./aff_a "dubO a POIL" | cat -e
a\$
\$> ./aff_a "zz sent le poney" | cat -e
\$
\$> ./aff_a | cat -e
\$

#### Proposed solution

1. If the number of parameters is not 1, write a newline and return
2. Iterate through the characters of the string --> `argv[1]`
    - If the 'a' character is found, write "a" and exit the loop
3. Always write a newline at the end

```
#include <unistd.h>
int main(int argc, char **argv)
{
    int i = 0;

    if (argc != 2)      // If num of parameters is not 1, display newline and return
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] != '\0')      // Iterate through characters
    {
        if (argv[1][i] == 'a')      // If 'a' is found, display it and exit loop
        {
            write(1, "a", 1);
            break;
        }
        i++;
    }
    write(1, "\n", 1);      // Always display a newline at the end
    return (0);
}
```

### aff_first_param

**Expected files:** aff_first_param.c | **Allowed functions:** write

Write a program that takes strings as arguments, and displays its first argument followed by a newline.

If the number of arguments is less than 1, the program displays a newline.

Examples:
\$> ./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e
vincent\$
\$> ./aff_first_param "j'aime le savon" | cat -e
j'aime le savon\$
\$> ./aff_first_param | cat -e
\$

#### Proposed solution

1. If the number of parameters is less than 1, write a newline and return
2. Iterate through all of the characters of the first parameter --> `argv[1]` is the first parameter
    - Write each character to the standard output
3. Always write a newline at the end

```
#include <unistd.h>
int main(int argc, char **argv)
{
    int i = 0;

    if (argc < 2)       // If less than 1 param
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] != '\0')      // Iterate through 1st param
    {
        write(1, &argv[1][i], 1);       // Write current character
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
```

### aff_last_param

**Expected files:** aff_last_param.c | **Allowed functions:** write

Write a program that takes strings as arguments, and displays its last argument followed by a newline.

If the number of arguments is less than 1, the program displays a newline.

Examples:
\$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
chats\$
\$> ./aff_last_param "j'aime le savon" | cat -e
j'aime le savon\$
\$> ./aff_last_param | cat -e
\$

#### Proposed solution

1. If the number of parameters is less than 1, write a newline and return
2. Iterate through all of the characters of the last parameter --> `argv[argc - 1]` is always the last parameter
    - Write each character to the standard output
3. Always write a newline at the end

```
#include <unistd.h>
int main(int argc, char **argv)
{
    int i = 0;

    if (argc < 2)       // If less than 1 param
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[argc - 1][i] != '\0')       // Last param is argv[argc - 1]
    {
        write(1, &argv[argc - 1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
```

### X

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

### ft_strcpy

| **File**    | ft_strcpy.c |
| :---------- | :---------- |
| **Allowed** | none        |

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

```
char *ft_strcpy(char *s1, char *s2);
```

#### Solution

```
char	*ft_strcpy(char	*dest, char	*src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
```
