/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:00:50 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/03 20:29:20 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

/* int main()
{
	char *s = "hello world";
	char c = 'l';
	char *res = ft_strchr(s,c);
	printf("%s\n",res);
} */


/*
    This is a recreation of the `strchr` function in C. The purpose of `strchr` is to locate the 
    first occurrence of a character `c` in the string `s` and return a pointer to it.

    According to the manual:
    
        The `strchr` function returns a pointer to the first occurrence of the character `c`
        in the string `s`, or NULL if the character is not found.
        The terminating null byte ('\0') is considered part of the string, so if `c` is '\0',
        the function returns a pointer to this terminator.

    Function Parameters:
    
    - `const char *s` → A pointer to the string where the search will be performed.
    - `int c`         → The character to search for, passed as an `int` but cast to `char`.

    Return Value:
    
    - If `c` is found, the function returns a pointer to its first occurrence in `s`.
    - If `c` is not found, the function returns `NULL`.
    - If `c` is `'\0'`, the function returns a pointer to the null terminator of `s`.

    Understanding the Implementation:

    char *ft_strchr(const char *s, int c)
    {
        int i;

        i = 0;
        while (s[i] != '\0') // Iterate until end of string
        {
            if (s[i] == (char)c) // If we find `c`, return pointer to it
                return ((char *)(s + i));
            i++;
        }
        if ((char)c == '\0') // If `c` is '\0', return pointer to null terminator
            return ((char *)(s + i));
        return (NULL); // If `c` is not found, return NULL
    }

    Step-by-Step Execution:

    1. Start a While Loop: `while (s[i] != '\0')`
      
       - The loop iterates through each character in `s` until it reaches the null terminator (`'\0'`).
       - Each character is checked against `(char)c`.

    2. Check for a Match: `if (s[i] == (char)c)`
      
       - If `s[i]` is equal to `c`, the function returns `s + i`, which is a pointer to that position.

    3. Increment `i` to Continue Searching
      
       - If `c` is not found, `i++` moves to the next character.

    4. Handling the Null Terminator (`if ((char)c == '\0')`)
      
       - If `c` is `'\0'`, we return `s + i`, which is a pointer to the null terminator of `s`.

    6. If `c` is Not Found, Return `NULL`
      
       - If the loop completes without finding `c`, return `NULL` as specified by the manual.

    Example Usage:

    #include <stdio.h>

    int main(void)
    {
        char str[] = "Hello, World!";
        char *result = ft_strchr(str, 'W');

        if (result != NULL)
            printf("Character found at: %s\n", result);
        else
            printf("Character not found\n");

        return 0;
    }

   Step-by-Step Execution of the Example:

      s = "Hello, World!"
      c = 'W'
 
    - String Representation in Memory:

      Index:    0    1    2    3    4    5    6    7    8    9   10   11   12   13
      Data:   ['H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0']

    - Loop Execution:
      
      | i | s[i]  | s[i] == 'W'? | Action |
      |---|-------|-------------|---------|
      | 0 | 'H'   | No          | Continue |
      | 1 | 'e'   | No          | Continue |
      | 2 | 'l'   | No          | Continue |
      | 3 | 'l'   | No          | Continue |
      | 4 | 'o'   | No          | Continue |
      | 5 | ','   | No          | Continue |
      | 6 | ' '   | No          | Continue |
      | 7 | 'W'   | Yes         | Return pointer to `s + 7` |

    - Output:
      
      Character found at: World!

    - Since `'W'` was found at index `7`, the function returns a pointer to that position in `s`.
      
    Handling Edge Cases:

    1. If `c` is `'\0'` (null terminator):
    
       - The function returns a pointer to the end of `s`.

      char str[] = "Hello";
      char *ptr = ft_strchr(str, '\0');
      printf("%p\n", (void *)ptr); // Points to `str + 5`

    2. If `c` is not in `s`:
    
       - The function returns `NULL`.
       
      char *ptr = ft_strchr("Test", 'x'); // Returns NULL

    3. If `s` is an empty string `""`:
    
       - The function only matches if `c == '\0'`.

      char *ptr = ft_strchr("", 'a');  // Returns NULL
      char *ptr2 = ft_strchr("", '\0'); // Returns pointer to `""`

*/