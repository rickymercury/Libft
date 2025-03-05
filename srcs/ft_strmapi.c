/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:53:55 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/04 19:48:12 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
    char	        *buffer;
	unsigned int	      i;
	unsigned int	    len;

	if (!s || !f)
		return (NULL);
    len = 0;
    while (s[len] != '\0')
		len++;
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    i = 0;
	while (i < len)
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/* char function_f_mapi(unsigned int i, char c)
{
        (void)i;
        return(c + 1);
}

int main()
{
    char *str_strmapi = "Hello, World!";
    char *result_strmapi = ft_strmapi(str_strmapi, function_f_mapi);
    
    printf("Origial: %s\n", str_strmapi);
    printf("New: %s\n", result_strmapi);
    free(result_strmapi);
} */

/*  This is a recreation of the strmapi function in C. The purpose of ft_strmapi is to create a new
    string by applying a given function (f) to each character of an input string (s), passing its
    index as the first argument. The function ensures that the transformation is performed safely
    and allocates memory dynamically to store the modified string.

    According to the manual: "The `ft_strmapi()` function applies the function `f` to each character
    of the string `s`, passing its index as the first argument. It returns a newly allocated string
    resulting from the successive applications of `f`. If memory allocation fails, the function returns `NULL`."

    The `ft_strmapi` function processes each character of the input string, applies the function `f`,
    and stores the transformed characters in a newly allocated string. The original string is not modified.
    Instead, a separate copy is created.

    Function Parameters:

    - `const char *s` → A pointer to the input string that will be processed.
    - `char (*f)(unsigned int, char)` → A pointer to a function that takes an index and a character
       as arguments and returns a transformed character.

    Understanding the Implementation:

    The function declares the following variables:

    - `unsigned int len` → Stores the length of `s` by iterating through it.
    - `unsigned int i` → Counter for iterating through `s` and applying the transformation.
    - `char *buffer` → A dynamically allocated string to store the transformed characters.

    How the function works:

    1. Check for NULL Pointers

    - If `s` or `f` are `NULL`, the function immediately returns `NULL` to prevent undefined behavior.

        if (!s || !f)
            return (NULL);

    2. Calculate the Length of the Input String

    - The function iterates through `s` to determine its length.

        len = 0;
        while (s[len] != '\0')
            len++;

    3. Allocate Memory for the New String

    - Memory is allocated for the transformed string using `malloc`.
    - The size allocated is `len + 1` to accommodate the null terminator (`\0`).
    - If allocation fails, the function returns `NULL`.

        buffer = (char *)malloc((len + 1) * sizeof(char));
        if (!buffer)
            return (NULL);

    4. Apply the Transformation Function to Each Character

    - The function iterates over `s`, applies `f(i, s[i])`, and stores the result in `buffer`.

        i = 0;
        while (i < len)
        {
            buffer[i] = f(i, s[i]);
            i++;
        }

    5. Null-Terminate the New String

    - The function ensures the transformed string is properly terminated.

        buffer[i] = '\0';

    6. Return the New String

    - The function returns the allocated and modified string.

        return (buffer);

    Handling Edge Cases:

    - If `s` or `f` is `NULL`, the function returns `NULL`.
    - If `malloc` fails, the function returns `NULL`.
    - If `s` is empty, an empty string is allocated and returned.

    Example Usage:

    #include <stdio.h>

    char ft_toupper_test(unsigned int i, char c)
    {
        (void)i; // Avoid unused variable warning
        if (c >= 'a' && c <= 'z')
            return (c - 32);
        return (c);
    }

    int main(int argc, char **argv)
    {
        char *result;

        if (argc == 2)
        {
            result = ft_strmapi(argv[1], ft_toupper_test);
            if (!result)
            {
                printf("Error: memory allocation failed\n");
                return (1);
            }
            printf("Modified String: %s\n", result);
            free(result);
        }
        else
        {
            printf("Usage: %s <string>\n", argv[0]);
        }
        return (0);
    }

    Step-by-Step Execution of the Example:

    - Input:

    ./program "hello, 42!"

    Step 1: Compute Length of `s`

    s = "hello, 42!"
    len = 10

    Step 2: Allocate Memory

    buffer is allocated with space for 11 characters (10 + 1 for `\0`).

    Step 3: Apply the Transformation Function

    The function `ft_toupper_test` is applied to each character:

    | Index | Original | Transformed |
    |-------|----------|-------------|
    | 0     | 'h'      | 'H'         |
    | 1     | 'e'      | 'E'         |
    | 2     | 'l'      | 'L'         |
    | 3     | 'l'      | 'L'         |
    | 4     | 'o'      | 'O'         |
    | 5     | ','      | ','         |
    | 6     | ' '      | ' '         |
    | 7     | '4'      | '4'         |
    | 8     | '2'      | '2'         |
    | 9     | '!'      | '!'         |

    Step 4: Null-Terminate the String

    buffer[10] = '\0'

    Step 5: Output the Result

    Output:

    Modified String: HELLO, 42!

    Special Cases:

    1. If `s` is empty, an empty string is returned.
    2. If `malloc` fails, `NULL` is returned.
    3. The function does not modify the original string.

    Key Takeaways:

    - `ft_strmapi` creates a new string by applying `f` to each character of `s`.
    - Memory is dynamically allocated, so the user must free it.
    - The function safely handles NULL pointers and empty strings.
*/