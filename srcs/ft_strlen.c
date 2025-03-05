/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:58:13 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/03 21:11:02 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int main()
{
	char *str;
	str = "Hello";
	printf("ft_strlen: %lu\n", ft_strlen(str));
	printf("strlen: %lu\n", strlen(str));
} */


/*
    This is a recreation of the `strlen` function in C. The purpose of `strlen` is to determine the 
    length of a given string by counting the number of characters before the null terminator (`\0`).

    According to the manual:  
    "The strlen() function calculates the length of the string pointed to by `s`, excluding the 
    terminating null byte ('\0')."

    Function Parameters:

    - `const char *s` → A pointer to the string whose length will be measured.

    Understanding the Implementation:

    The function declares the following variables:

    - `size_t i` → A counter used to traverse the string and count its characters.

    How the function works:

    1. Initialize the Counter
      
       - The function starts by initializing `i` to 0.

        size_t i = 0;

    2. Traverse the String
    
       - The function enters a `while` loop that iterates over the string until it encounters the null terminator (`\0`).

        while (s[i])
            i++;

       - Each time the loop runs, `i` is incremented by 1, effectively counting the number of characters in `s`.

    3. Return the Length
     
       - When the loop exits, `i` contains the number of characters in `s`, so it is returned.

        return (i);

    Handling Edge Cases:

    - If `s == NULL`, the function **does not** check for it. Calling `ft_strlen(NULL)` results in **undefined behavior** 
      (it will attempt to access `s[0]`, causing a segmentation fault).
    - If `s` is an empty string (`""`), the function correctly returns `0`, since there are no characters before `\0`.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>

        int main(void)
        {
            char *str1 = "Hello, world!";
            char *str2 = "";

            printf("Length of '%s': %lu\n", str1, ft_strlen(str1));
            printf("Length of an empty string: %lu\n", ft_strlen(str2));

            return 0;
        }

    Step 1: Understanding the Arguments

    - `str1 = "Hello, world!"` (a string of 13 characters + `\0`).
    - `str2 = ""` (an empty string that only contains `\0`).

    Step 2: Loop Execution

    - For `"Hello, world!"`:

      H  e  l  l  o  ,     w  o  r  l  d  !  \0
      1  2  3  4  5  6  7  8  9 10 11 12 13  (14º byte is \0)

      - The loop runs 13 times before stopping at `\0`, so the function returns `13`.

    - For `""` (empty string):
    
      - The first character is `\0`, so the loop never runs, and the function returns `0`.

    Step 3: Output

        Length of 'Hello, world!': 13
        Length of an empty string: 0

    Key Takeaway:  

    - `ft_strlen` is a simple and efficient way to determine the length of a string.
    - It **does not** check for `NULL`, so passing a `NULL` pointer will cause a segmentation fault.

*/
