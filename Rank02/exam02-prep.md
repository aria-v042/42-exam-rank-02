# Exam Rank 02 - Preparation Guide

**Compile:** `cc -Wall -Wextra -Werror <name.c> -o name`
**Test:** `./name [arguments...]`

---
## Level 0

---
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

```c
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

---
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

```c
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

---
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

```c
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

---
### aff_z

**Expected files:** aff_z.c | **Allowed functions:** write

Write a program that takes a string, and displays the character 'z' followed by a newline.

Example:
\$> ./aff_z "abc" | cat -e
z\$
\$> ./aff_z | cat -e
z\$

#### Proposed solution

1. Always write "z\n"

```c
#include <unistd.h>
int main(void)
{
    write(1, "z\n", 2);     // Write 2 bytes, not 1
    return (0);
}
```

---
### first_word

**Expected files:** first_word.c | **Allowed functions:** write

Write a program that takes a string and displays its first word, followed by a newline.

A word is a section of string delimited by spaces/tabs or by the start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display a newline.

Examples:
\$> ./first_word "FOR PONY" | cat -e
FOR\$
\$> ./first_word "this ... is sparta, then again, maybe not" | cat -e
this\$
\$> ./first_word " " | cat -e
\$
\$> ./first_word "a" "b" | cat -e
\$
\$> ./first_word " lorem,ipsum " | cat -e
lorem,ipsum\$

#### Proposed solution

1. If the number of parameters is not 1, write newline and return
2. Iterate through leading spaces/tabs, skipping them --> when the loop stops, we're either at the first word or at the end of the string
3. Write each character of the word; stop when we find either a space/tab or the end of the string
4. Always write a newline at the end


```c
#include <unistd.h>
int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc != 2)	// If not 1 param
	{
		write(1, "\n", 1);
		return (0);
	}
	// Skip leading spaces/tabs - reach 1st word or end of string
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
	{
		i++;
	}
	// Write each character until a space/tab or end of string
	while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);      // Always write a newline at the end
	return (0);
}
```

---
### fizzbuzz

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_putstr

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strcpy

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

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
---
### ft_strlen

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_swap

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### maff_alpha

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### maff_revalpha

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### repeat_alpha

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### rev_print

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### rot_13

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### rotone

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### search_and_replace

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ulstr

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```


---
## Level 1
---
### alpha_mirror

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### camel_to_snake

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### do_op

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_atoi

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strchr

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strcmp

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strcspn

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strdup

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strpbrk

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strrev

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_strspn

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### inter

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### is_power_of_2

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### last_word

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### max

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### print_bits

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### reverse_bits

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### snake_to_camel

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### swap_bits

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### union

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### wdmatch

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```


---
## Level 2
---
### add_prime_sum

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### epur_str

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### expand_str

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_atoi_base

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_list_size

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_range

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_rrange

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### hidenp

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### lcm

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### paramsum

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### pgcd

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### print_hex

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### rstr_capitalizer

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### str_capitalizer

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### tab_mult

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```


---
## Level 3
---
### flood_fill

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### fprime

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_itoa

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_list_foreach

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_list_remove_if

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### ft_split

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### rev_wstr

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### rostring

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### sort_int_tab

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```

---
### sort_list

#todo

**Expected files:** X.c | **Allowed functions:** X

X

#### Proposed solution

1. X

```
X
```


