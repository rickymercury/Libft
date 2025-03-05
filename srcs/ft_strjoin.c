/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:40:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/04 12:22:40 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
    size_t	len_s1;
	size_t	len_s2;
	size_t		i;
	size_t	    j;

	if (!s1 || !s2)
		return (NULL);
    i = 0;
    j = 0;
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
	buffer = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!buffer)
		return (NULL);
	while (i < len_s1)
	{
		buffer[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}

/* int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Original string: %s\n", argv[1]);
		printf("Original string: %s\n", argv[2]);
		printf("Joined string: %s\n", ft_strjoin(argv[1], argv[2]));
	}
	return (0);
} */


/*  This is a recreation of the strjoin function in C. The purpose of strjoin is to concatenate (join) two given strings (s1 and s2)
into a newly allocated string.

According to the manual: "The `ft_strjoin()` function allocates and returns a new string, which is the result of
the concatenation of `s1` and `s2`. If the allocation fails, the function returns `NULL`."

        The `ft_strjoin` function creates a new string consisting of `s1` followed by `s2`. 
        Memory for the new string is dynamically allocated and must be freed by the user.
        If `s1` or `s2` are `NULL`, the function returns `NULL`.

Function Parameters:

- `const char *s1` → A pointer to the first string to be joined.
- `const char *s2` → A pointer to the second string to be joined.

Understanding the Implementation:

The function declares the following variables:

- `size_t len_s1` → Stores the length of `s1` using `ft_strlen(s1)`.
- `size_t len_s2` → Stores the length of `s2` using `ft_strlen(s2)`.
- `size_t i, j` → Counters for iterating through `s1` and `s2`.

How the function works:

1. Check for Null Pointers

- The function first checks if `s1` or `s2` is `NULL`. If either is `NULL`, the function returns `NULL`. This prevents
  any undefined behavior that would arise from trying to access a `NULL` pointer.

    if (!s1 || !s2)
        return (NULL);

2. Compute String Lengths

- The function calculates the length of `s1` and `s2` to determine the total memory required.

    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);

3. Allocate Memory for the New String

- The function uses `malloc` to allocate memory for `len_s1 + len_s2 + 1` characters:

    - `len_s1` → The number of characters from `s1`
    - `len_s2` → The number of characters from `s2`
    - `+1` → To include the null terminator `\0`
    
- If `malloc` fails, it returns `NULL`.

    buffer = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if (!buffer)
        return (NULL);

4. Copy `s1` to the New Buffer

- The first `while` loop iterates through `s1` and copies each character to `buffer`.

    while (i < len_s1)
    {
        buffer[i] = s1[i];
        i++;
    }

5. Copy `s2` to the New Buffer (After `s1`)

- After copying `s1`, the loop copies `s2` into `buffer`, starting at `buffer[i]`.

    while (j < len_s2)
    {
        buffer[i + j] = s2[j];
        j++;
    }

6. Null-Terminate the New String

- The last character of `buffer` is set to `\0` to ensure it is a valid C string.

    buffer[i + j] = '\0';

7. Return the New String

- The function returns `buffer`, which now contains `s1` followed by `s2`.

    return (buffer);

Handling Edge Cases:

- If `s1` or `s2` is `NULL`, the function returns `NULL`.
- If `malloc` fails, the function also returns `NULL` to prevent memory-related errors.
- If `s1` or `s2` is an empty string (`""`), the function still works correctly:
    - If `s1` is empty, the function returns a copy of `s2`.
    - If `s2` is empty, the function returns a copy of `s1`.
    - If both are empty, it returns an empty string (`""`).

    
Example Usage:

#include <stdio.h>

    int main(void)
    {
        char *s1 = "Hello, ";
        char *s2 = "World!";
        char *result = ft_strjoin(s1, s2);

        if (result)
        {
            printf("Concatenated String: %s\n", result);
            free(result); // Free allocated memory
        }
        else
            printf("Error concatenating strings.\n");
        
        return 0;
    }

    Step-by-Step Execution of the Example:

    - Input:
    
      s1 = "Hello, "
      s2 = "World!"


    Step 1: Memory Allocation

        The function calculates the length of both strings and allocates memory to store s1 + s2 + '\0'.

            String	Length (strlen)
            
            s1 = "Hello, "	7
            s2 = "World!"	6
            buffer (allocated space)	7 + 6 + 1 = 14 bytes

        Initially, the allocated memory is empty but has enough space to store "Hello, World!".
        
        Index	0	1	2	3	4	5	6	7	8	9	10	11	12	13
        Data	?	?	?	?	?	?	?	?	?	?	?	?	?	\0

        The last position (index 13) is reserved for the null terminator \0.
    
    Step 2: Copy s1 into buffer

        Now, we copy s1 = "Hello, " into buffer.

        Index	0	1	2	3	4	5	6	7	8	9	10	11	12	13
        Data	'H'	'e'	'l'	'l'	'o'	','	' '	?	?	?	?	?	?	\0

        | i | s1[i]  | buffer[i]  |
        |---|--------|------------|
        | 0 | 'H'    | 'H'        |
        | 1 | 'e'    | 'e'        |
        | 2 | 'l'    | 'l'        |
        | 3 | 'l'    | 'l'        |
        | 4 | 'o'    | 'o'        |
        | 5 | ','    | ','        |
        | 6 | ' '    | ' '        |
        
        The pointer i iterated from 0 to 6, filling buffer with s1.
    
    Step 3: Copy s2 into buffer (after s1)

        Now, we copy s2 = "World!" into buffer, starting from index 7.

        Index	0	1	2	3	4	5	6	7	8	9	10	11	12	13
        Data	'H'	'e'	'l'	'l'	'o'	','	' '	'W'	'o'	'r'	'l'	'd'	'!'	\0
    
        | j | s2[j]  | buffer[i + j] |
        |---|--------|---------------|
        | 0 | 'W'    | 'W'           |
        | 1 | 'o'    | 'o'           |
        | 2 | 'r'    | 'r'           |
        | 3 | 'l'    | 'l'           |
        | 4 | 'd'    | 'd'           |
        | 5 | '!'    | '!'           |

    The pointer j iterated from 0 to 5, filling buffer with s2.

    Step 4: Final Concatenated String

        Now, buffer correctly contains the string "Hello, World!", properly null-terminated.

        Index	0	1	2	3	4	5	6	7	8	9	10	11	12	13
        Data	'H'	'e'	'l'	'l'	'o'	','	' '	'W'	'o'	'r'	'l'	'd'	'!'	\0

        Now, when we call printf("%s", buffer);, the output will be: 

        "Concatenated String: Hello, World!"
    
    
    Special Cases:

    1. If `s1` or `s2` are `NULL`:
       - The function returns `NULL`.

    2. If `s1` or `s2` are empty strings:
       - `s1 = ""`, `s2 = "World!"` → Returns "World!"
       - `s1 = "Hello, "`, `s2 = ""` → Returns "Hello, "

    3. If `malloc` fails:
       - Returns `NULL`, and the string is not created.
       
Key Takeaways:

- `ft_strjoin` creates a new string by concatenating two given strings.
- It dynamically allocates memory, so the returned string must be freed after use.
- It correctly handles edge cases, such as `NULL` input and empty strings.
- It is useful for joining strings in a memory-safe way, preventing buffer overflows.

*/


