/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:11:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/03 21:39:21 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}


/* void print_char_index(unsigned int index, char *c)
{
    printf("Index: %u, Char: %c\n", index, *c);
}

int main()
{
    char str[] = "Hello, 42!";

    ft_striteri(str, print_char_index);

    return (0);
} */



/*  This is a recreation of the striteri function in C. The purpose of striteri is to apply a given function to each character
    of a string, passing both the index and the character itself to the provided function.

    According to the manual: "The `striteri()` function applies the function `f` to each character of the string `s`, 
    passing the index of the character and the address of the character as arguments."

    Function Parameters:

    - `char *s` → A pointer to the string on which the function `f` will be applied.
    - `void (*f)(unsigned int, char *)` → A pointer to the function that will be applied to each character. The function 
       `f` takes two parameters: an index (`unsigned int`) and a pointer to the character (`char *`).

    Understanding the Implementation:

    The function declares the following variables:

    - `unsigned int i` → A counter to keep track of the current index while iterating through the string.

    How the function works:

    1. Check for Null Pointer
      
    - The function first checks if the string `s` is `NULL`. If it is, the function simply returns, doing nothing. This prevents 
      any undefined behavior that would arise from trying to dereference a `NULL` pointer.

    if (!s)
        return;

2. Iterate Through the String
  
   - The function then enters a `while` loop where it iterates through the string `s` one character at a time, starting from 
     index `0` (since `i = 0` initially). It continues until the null-terminator (`\0`) is reached.

    while (s[i] != '\0')
    {
        f(i, s + i);
        i++;
    }

   - For each character in the string, the function `f` is called, with two arguments: 
   
     - `i` → The current index of the character in the string.
     - `s + i` → The address of the current character in the string. This is passed as a pointer (`char *`).

   - `i++` increments the index for the next iteration.

3. No Return Value
  
   - The function has no return value (`void`). It simply applies the function `f` to each character of the string.

Handling Edge Cases:

- If `s == NULL`, the function does nothing and returns immediately to avoid dereferencing a `NULL` pointer.
- The function ensures that the correct index and address of the character are passed to the function `f` for each iteration.

Example Usage:

Suppose we have the following code:

    #include <stdio.h>

    void print_char_index(unsigned int index, char *c)
    {
        printf("Index: %u, Char: %c\n", index, *c);
    }

    int main(void)
    {
        char str[] = "Hello, 42!";

        ft_striteri(str, print_char_index);

        return 0;
    }

    Step 1: Understanding the Arguments

        The string we are working with is str = "Hello, 42!". This means we have a string with the characters
        'H', 'e', 'l', 'l', 'o', ',', ' ', '4', '2', '!', and the null terminator '\0'.

        The function print_char_index is passed as an argument to ft_striteri. This function has the following signature:

        void print_char_index(unsigned int index, char *c)

        It prints the index and the character that was passed to it.

        The function will be called for each character of the string, and it requires two parameters:
        
            index → The index of the current character in the string.
            c → A pointer to the current character.

    Step 2: How (*f) Works Inside ft_striteri

    Within the ft_striteri function, we have the line:

    f(i, s + i);

    Here, the function f is called. f is the name of the function pointer that was passed to ft_striteri. In our case, f is the
    function print_char_index.

        i is the index of the current character. It starts at 0 and goes up to the last index of the string, which is the length of the string minus one.
        s + i is the address of the character at position i in the string. The expression s + i is a pointer pointing to the character at position i.

    So, for each character in the string, the function f (in this case, print_char_index) is called, passing:

        The current index of the character.
        The pointer to the character in the string.

    Step 3: How the print_char_index Function is Called

    The function print_char_index receives two parameters:

        The first is the index (for example, 0 for the first character, 1 for the second, and so on).
        The second is the pointer to the character (for example, &str[0], &str[1], etc.).

    When the ft_striteri function calls f(i, s + i), it is invoking the print_char_index function with the index and the pointer to the character.

    Here’s a detailed example of the execution:

    First Iteration (i = 0)

        Call: f(0, s + 0) → The function print_char_index(0, &str[0]) is called.
            The index is 0.
            The pointer is to the first character, which is 'H'.
        
        Inside print_char_index:
        
            *c dereferences the pointer s + 0, resulting in the character 'H'.
            So, the output will be:

            Index: 0, Char: H

    Second Iteration (i = 1)

        Call: f(1, s + 1) → The function print_char_index(1, &str[1]) is called.
            
            The index is 1.
            The pointer is to the second character, which is 'e'.
    
        Inside print_char_index:
        
            *c dereferences the pointer s + 1, resulting in the character 'e'.
            So, the output will be:

            Index: 1, Char: e

    Third Iteration (i = 2)

        Call: f(2, s + 2) → The function print_char_index(2, &str[2]) is called.
        
            The index is 2.
            The pointer is to the third character, which is 'l'.
    
        Inside print_char_index:
        
            *c dereferences the pointer s + 2, resulting in the character 'l'.
            So, the output will be:

            Index: 2, Char: l

    Continuing the Iterations . . .

    This process continues for each character in the string:

        For the character 'l' at i = 3, print_char_index(3, &str[3]) is called, and the character 'l' is printed.
        For the character 'o' at i = 4, print_char_index(4, &str[4]) is called, and the character 'o' is printed.
        And so on until the last character.

    Step 4: Full Output

    The final output of the program will be:

    Index: 0, Char: H
    Index: 1, Char: e
    Index: 2, Char: l
    Index: 3, Char: l
    Index: 4, Char: o
    Index: 5, Char: ,
    Index: 6, Char:  
    Index: 7, Char: 4
    Index: 8, Char: 2
    Index: 9, Char: !

    Key Takeaway:

    (*f) is a function pointer that allows the ft_striteri function to apply the provided function to each character of the string.
    Each time the function f is called, it receives the index of the character and a pointer to the character in the string. 
    This enables you to perform custom operations on each character based on both the character's value and its index in the string.

    This approach is useful when you need to modify or process a string in a customized way, particularly when the position of each
    character within the string matters.

*/

