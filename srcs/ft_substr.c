/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:26:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/05 16:08:37 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
    if (start + len > str_len)
		len = str_len - start;
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        buffer[i] = s[start + i];
         i++;
    }
    buffer[i] = '\0';
    return (buffer);
}

/* int main(int argc, char **argv)
{
    // ft_substr: extracts a substring from a given string, starting at the index "start" with length "len"
    if (argc == 4)
    {
        char *result = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
        if (result) 
        {
            printf("ft_substr: %s\n", result);
            free(result);
        }
    }
    return (0);
} */

/* 
$ cc -Wall -Werror -Wextra ft_substr.c 
$ ./a.out "Hello, World!" 7 5
$ ft_substr: World 
*/

/* 
    This is a recreation of the `ft_substr` function in C. The purpose of `ft_substr` is to create a new string by extracting a 
    portion of an input string (`s`) starting from a given index (`start`) and with a specific length (`len`). The function ensures 
    safe memory handling and returns a newly allocated string containing the extracted substring.

    Function Overview:

    According to the manual: "ft_substr() extracts a substring from the string s, starting at index `start` and with a length of `len`.
    It returns a newly allocated string containing the extracted substring. If memory allocation fails or invalid arguments are provided,
    it returns NULL."

    The `ft_substr` function processes the input string and allocates memory for a new string that contains the requested substring.
    The original string remains unchanged.

    Function Parameters:

    const char *s: A pointer to the input string from which the substring will be extracted.
    unsigned int start: The index at which the substring extraction will begin.
    size_t len: The maximum number of characters to be extracted.

    Implementation Breakdown:

    The function works in the following steps:

        1. Check for NULL Pointer:
        
            If the input string `s` is NULL, the function immediately returns NULL to avoid undefined behavior.

            if (!s)
                return (NULL);

        2. Calculate the Length of the Input String:
        
            The function calculates the length of the input string using `ft_strlen(s)`, which returns the number of characters in the string.

            str_len = ft_strlen(s);

        3. Handle Start Index Greater than String Length:
        
            If the `start` index is greater than or equal to the length of the string, there are no characters to extract, so the length of the
            substring is set to 0.

            if (start >= str_len)
                len = 0;

        4. Handle Length Exceeding the String Boundaries:
            
            If the `start + len` exceeds the length of the string, the function adjusts `len` to ensure the substring does not exceed the string
            boundaries.

            if (start + len > str_len)
                len = str_len - start;

        5. Allocate Memory for the Substring:
            
            The function allocates memory for the substring. The allocated memory should be large enough to store the substring and the null terminator.

            buffer = (char *)malloc((len + 1) * sizeof(char));
            if (!buffer)
                return (NULL);

        6. Copy the Substring:
        
            The function uses a `while` loop to copy the characters from `s` starting at index `start` and continuing for `len` characters. The loop terminates
            when all characters are copied or when the end of the string is reached.

            i = 0;
            while (i < len && s[start + i] != '\0')
            {
                buffer[i] = s[start + i];
                i++;
            }

        7. Null-Terminate the Substring:
        
            After copying the characters, the function ensures the new string is null-terminated.

            buffer[i] = '\0';

        8. Return the Substring:
        
            Finally, the function returns the newly allocated string containing the extracted substring.

            return (buffer);

        Example:

        #include <stdio.h>

        int main(int argc, char **argv)
        {
            char *result;

            if (argc == 4)
            {
                result = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
                if (!result)
                {
                    printf("Error: memory allocation failed\n");
                    return (1);
                }
                printf("Extracted Substring: %s\n", result);
                free(result);
            }
            return (0);
        }

    Detailed Step-by-Step Execution:

        Receiving Input:

        The program starts by checking if the number of command-line arguments is 4 (the program name, the input string, the starting index, and the length).
        
            Input: ./program "Hello, World!" 7 5

        Calling the ft_substr Function:

        The function ft_substr is called with the input string "Hello, World!", starting index 7, and length 5:
            
        result = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]))

        Checking for NULL Pointers:

        Inside the ft_substr function, the first thing that happens is the check to see if the input string s is NULL.
        
            If s is NULL, the function returns NULL immediately. In this case, s is valid, so the function continues.

        Calculating the String Length:

            The function calculates the length of the string using ft_strlen(s). In this case, str_len will be 13 for "Hello, World!".

        Handling Start Index Greater than String Length:

            The start index is 7, which is valid since it is less than str_len. The length of len is initially 5, so no changes are needed here.

        Memory Allocation for the Substring:

            The function allocates memory for the substring. It allocates 6 bytes to store the substring and the null terminator.

        Copying the Substring:

            The function starts copying characters from index 7 of the string. The substring extracted is "World". This substring is stored in buffer.

        Null-Terminating the Substring:

            The function ensures that the resulting string is null-terminated by setting buffer[i] = '\0'.

        Returning the Substring:

            The function returns the newly allocated string, which is "World".

        Freeing the Allocated Memory:

            After using the result, the memory allocated for the substring is freed to avoid memory leaks:  free(result)

    Key Takeaways:

    ft_substr extracts a substring from a given string based on a starting index and length.
    It handles edge cases such as an invalid starting index, memory allocation failure, and out-of-bounds length.
    The function is efficient and avoids modifying the original string.
    Memory allocated by ft_substr should be freed by the user to prevent memory leaks.

*/