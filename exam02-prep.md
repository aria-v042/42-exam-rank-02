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
```
$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
$
```

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

    if (argc != 2)  // If NOT 1 param, write newline and return
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] != '\0')  // Iterate through characters
    {
        if (argv[1][i] == 'a')  // If 'a', write "a" and exit loop
        {
            write(1, "a", 1);
            break;
        }
        i++;
    }
    write(1, "\n", 1);  // Always write a newline at the end
    return (0);
}
```

---
### aff_first_param

**Expected files:** aff_first_param.c | **Allowed functions:** write

Write a program that takes strings as arguments, and displays its first argument followed by a newline.

If the number of arguments is less than 1, the program displays a newline.

Examples:
```
$> ./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e
vincent$
$> ./aff_first_param "j'aime le savon" | cat -e
j'aime le savon$
$> ./aff_first_param | cat -e
$
```

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
if (argc < 2)   // If LESS than 1 param
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[1][i] != '\0')  // Iterate through 1st param
    {
        write(1, &argv[1][i], 1);   // Write current character
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
```
$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
chats$
$> ./aff_last_param "j'aime le savon" | cat -e
j'aime le savon$
$> ./aff_last_param | cat -e
$
```

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

    if (argc < 2)   // If LESS than 1 param
    {
        write(1, "\n", 1);
        return (0);
    }
    while (argv[argc - 1][i] != '\0')   // Last param is argv[argc - 1]
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
```
$> ./aff_z "abc" | cat -e
z$
$> ./aff_z | cat -e
z$
```

#### Proposed solution

1. Always write "z\n"

```c
#include <unistd.h>
int main(void)
{
    write(1, "z\n", 2); // Write 2 bytes, not 1
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
```
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this ... is sparta, then again, maybe not" | cat -e
this$
$> ./first_word " " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word " lorem,ipsum " | cat -e
lorem,ipsum$
```

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

	if (argc != 2)  // If NOT 1 param
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
	write(1, "\n", 1);  // Always write a newline at the end
	return (0);
}
```

---
### fizzbuzz

**Expected files:** fizzbuzz.c | **Allowed functions:** write

Write a program that prints the numbers from 1 to 100, each separated by a newline.

If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:
```
$>./fizzbuzz
1
2
fizz
4
buzz
fizz
[...]
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_putstr

**Expected files:** ft_putstr.c | **Allowed functions:** write

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first character.

Your function must be declared as follows:

```
void    ft_putstr(char *str);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strcpy

**Expected files:** ft_strcpy.c | **Allowed functions:** none

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

```
char    *ft_strcpy(char *s1, char *s2);
```

#### Proposed solution

#todo

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

**Expected files:** ft_strlen.c | **Allowed functions:** none

Write a function that returns the length of a string.

Your function must be declared as follows:

```
int ft_strlen(char *str);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_swap

**Expected files:** ft_swap.c | **Allowed functions:** none

Write a function that swaps the contents of two integers the adresses of which are passed as parameters.

Your function must be declared as follows:

```
void    ft_swap(int *a, int *b);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### maff_alpha

**Expected files:** maff_alpha.c | **Allowed functions:** write

Write a program that displays the alphabet, with even letters in uppercase, and odd letters in lowercase, followed by a newline.

Example:
```
$> ./maff_alpha | cat -e
aBcDeFgHiJkLmNoPqRsTuVwXyZ$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### maff_revalpha

**Expected files:** maff_revalpha.c | **Allowed functions:** write

Write a program that displays the alphabet in reverse order, with even letters in uppercase, and odd letters in lowercase, followed by a newline.

Example:
```
$> ./maff_revalpha | cat -e
zYxWvUtSrQpOnMlKjIhGfEdCbA$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### repeat_alpha

#todo

**Expected files:** repeat_alpha.c | **Allowed functions:** write

Write a program called repeat_alpha that takes a string and display it repeating each alphabetical character as many times as its alphabetical index, followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.

Examples:
```
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### rev_print

**Expected files:** rev_print.c | **Allowed functions:** write

Write a program that takes a string, and displays the string in reverse followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:
```
$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### rot_13

**Expected files:** rot_13.c | **Allowed functions:** write

Write a program that takes a string and displays it, replacing each of its letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
The output will be followed by a newline.
If the number of arguments is not 1, the program displays a newline.

Example:
```
$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
```

#### Proposed solution

#todo

1. X

```
X
```

---
### rotone

**Expected files:** rotone.c | **Allowed functions:** write

Write a program that takes a string and displays it, replacing each of its letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n.

Example:
```
$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
```

#### Proposed solution

#todo

1. X

```
X
```

---
### search_and_replace

**Expected files:** search_and_replace.c | **Allowed functions:** write, exit

Write a program called search_and_replace that takes 3 arguments, the first arguments is a string in which to replace a letter (2nd argument) by another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string) then the program simply rewrites the string followed by a newline.

Examples:
```
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ulstr

**Expected files:** ulstr.c | **Allowed functions:** write

Write a program that takes a string and reverses the case of all its letters.
Other characters remain unchanged.

You must display the result followed by a '\n'.
If the number of arguments is not 1, the program displays '\n'.

Examples:
```
$>./ulstr "L'eSPrit nE peUt plUs pRogResSer s'Il staGne et sI peRsIsTent VAnIte et auto-
justification." | cat -e
l'EspRIT Ne PEuT PLuS PrOGrESsER S'iL STAgNE ET Si PErSiStENT vaNiTE ET AUTO-
JUSTIFICATION.$
$>./ulstr | cat -e
$
```

#### Proposed solution

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

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

#todo

1. X

```
X
```


