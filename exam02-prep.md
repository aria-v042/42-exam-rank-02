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

**Expected files:** alpha_mirror.c | **Allowed functions:** write

Write a program called alpha_mirror that takes a string and displays this string after replacing each alphabetical character by the opposite alphabetical character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

Case is not changed.
If the number of arguments is not 1, display only a newline.

Examples:
```
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### camel_to_snake

**Expected files:** camel_to_snake.c | **Allowed functions:** malloc, free, realloc, write

Write a program that takes a single string in lowerCamelCase format and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter except for the first one.

A snake_case string is a string where each word is in lower case, separated by an underscore "_".

Examples:
```
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### do_op

**Expected files:** do_op.c | **Allowed functions:** atoi, printf, write

Write a program that takes three strings:
\- The first and the third one are representations of base-10 signed integers that fit in an int.
\- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation, followed by a newline. If the number of parameters is not 3, the program just displays a newline.

Examples:
```
$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_atoi

**Expected files:** ft_atoi.c | **Allowed functions:** none

Write a function that converts the string argument str to an integer (type int) and returns it.

It works much like the standard atoi(const char \*str) function, see the man.

Your function must be declared as follows:
```
int ft_atoi(const char *str);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strchr

**Expected files:** ft_strchr.c | **Allowed functions:** none

Reproduce the behavior of the function strchr (man strchr).

The function must be declared as follows:
```
char    *ft_strchr(const char *s, int c);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strcmp

**Expected files:** ft_strcmp.c | **Allowed functions:** none

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:
```
int ft_strcmp(char *s1, char *s2);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strcspn

**Expected files:** ft_strcspn.c | **Allowed functions:** none

Reproduce exactly the behavior of the function strcspn (man strcspn).

The function should be prototyped as follows:
```
size_t  ft_strcspn(const char *s, const char *reject);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strdup

**Expected files:** ft_strdup.c | **Allowed functions:** malloc

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:
```
char    *ft_strdup(char *src);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strpbrk

**Expected files:** ft_strpbrk.c | **Allowed functions:** none

Reproduce the behavior of the function strpbrk (man strpbrk).

The function must be declared as follows:
```
char    *ft_strpbrk(const char *s1, const char *s2);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strrev

**Expected files:** ft_strrev.c | **Allowed functions:** none

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:
```
char    *ft_strrev(char *str);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_strspn

**Expected files:** ft_strspn.c | **Allowed functions:** none

Reproduce the behavior of the function strspn (man strspn).

The function must be declared as follows:
```
size_t  ft_strspn(const char *s, const char *accept);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### inter

**Expected files:** inter.c | **Allowed functions:** write

Write a program that takes two strings and displays, without doubles, the characters that appear in both strings, in the order they appear in the first one.

The display will be followed by a \n.
If the number of arguments is not 2, the program displays \n.

Examples:
```
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### is_power_of_2

**Expected files:** is_power_of_2.c | **Allowed functions:** none

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:
```
int is_power_of_2(unsigned int n);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### last_word

**Expected files:** last_word.c | **Allowed functions:** write

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:
```
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this ... is sparta, then again, maybe not" | cat -e
not$
$> ./last_word " " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word " lorem,ipsum " | cat -e
lorem,ipsum$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### max

**Expected files:** max.c | **Allowed functions:** none

Write the following function:
```
int max(int* tab, unsigned int len);
```

The first parameter is an array of int, the second is the number of elements in the array.

The function returns the largest number found in the array.
If the array is empty, the function returns 0.

#### Proposed solution

#todo

1. X

```
X
```

---
### print_bits

**Expected files:** print_bits.c | **Allowed functions:** write

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE AT THE END.

Your function must be declared as follows:
```
void    print_bits(unsigned char octet);
```

Example, if you pass 2 to print_bits, it will print "00000010"

#### Proposed solution

#todo

1. X

```
X
```

---
### reverse_bits

**Expected files:** reverse_bits.c | **Allowed functions:** none

Write a function that takes a byte, reverses it, bit by bit (like the example) and returns the result.

Your function must be declared as follows:
```
unsigned char   reverse_bits(unsigned char octet);
```

Example:
```
   1 byte
_____________
  0010 0110
     ||
     \/
  0110 0100
```

#### Proposed solution

#todo

1. X

```
X
```

---
### snake_to_camel

**Expected files:** snake_to_camel.c | **Allowed functions:** malloc, free, realloc, write

Write a program that takes a single string in snake_case format and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter except for the first one.

Examples:
```
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### swap_bits

**Expected files:** swap_bits.c | **Allowed functions:** none

Write a function that takes a byte, swaps its halves (like the example) and returns the result.

Your function must be declared as follows:
```
unsigned char   swap_bits(unsigned char octet);
```

Example:
```
  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
```

#### Proposed solution

#todo

1. X

```
X
```

---
### union

**Expected files:** union.c | **Allowed functions:** write

Write a program that takes two strings and displays, without doubles, the characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and will be followed by a \n.
If the number of arguments is not 2, the program displays \n.

Example:
```
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### wdmatch

**Expected files:** wdmatch.c | **Allowed functions:** write

Write a program that takes two strings and checks whether it's possible to write the first string with characters from the second string, while respecting the order in which these characters appear in the second string.

If it's possible, the program displays the string, followed by a \n, otherwise it simply displays a \n.
If the number of arguments is not 2, the program displays a \n.

Examples:
```
$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
```

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

**Expected files:** add_prime_sum.c | **Allowed functions:** write, exit

Write a program that takes a positive integer as argument and displays the sum of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number, just display 0 followed by a newline.

Examples:
```
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### epur_str

**Expected files:** epur_str.c | **Allowed functions:** write

Write a program that takes a string, and displays this string with exactly one space between words, with no spaces or tabs either at the beginning or the end, followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the program displays \n.

Example:
```
$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S* Sherlock..." "nAw S* ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### expand_str

**Expected files:** expand_str.c | **Allowed functions:** write

Write a program that takes a string and displays it with exactly three spaces between each word, with no spaces or tabs either at the beginning or the end, followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display a newline.

Examples:
```
$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S* Sherlock..." "nAw S* ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_atoi_base

**Expected files:** ft_atoi_base.c | **Allowed functions:** none

Write a function that converts the string argument str (base N <= 16) to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base.

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the string.

Your function must be declared as follows:
```
int ft_atoi_base(const char *str, int str_base);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_list_size

```
Expected files   : ft_list_size.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int ft_list_size(t_list *begin_list);

You must use the following structure in your program ft_list_size.c:

typedef struct  s_list
{
    struct s_list *next;
    void *data;
}   t_list;
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_range

**Expected files:** ft_range.c | **Allowed functions:** malloc

```
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3..
```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_rrange

```
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:
- With (1, 3) you will return an array containing 3, 2 and 1.
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
```

#### Proposed solution

#todo

1. X

```
X
```

---
### hidenp

#todo
```
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples:
$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
```

#### Proposed solution

#todo

1. X

```
X
```

---
### lcm

#todo
```
Expected files   : lcm
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest positive
integer divisible by both integers.

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

unsigned int    lcm(unsigned int a, unsigned int b);
```

#### Proposed solution

#todo

1. X

```
X
```

---
### paramsum

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### pgcd

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### print_hex

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### rstr_capitalizer

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### str_capitalizer

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### tab_mult

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

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
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### fprime

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_itoa

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_list_foreach

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_list_remove_if

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### ft_split

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### rev_wstr

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### rostring

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### sort_int_tab

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```

---
### sort_list

#todo
```
Expected files   :
Allowed functions:
--------------------------------------------------------------------------------

```

#### Proposed solution

#todo

1. X

```
X
```


