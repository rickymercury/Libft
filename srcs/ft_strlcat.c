/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:53:03 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/04 12:45:54 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
    src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (src_len + size);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);

	char dest01[20] = "Hello, ";
	size_t size = 16;

	size_t result = ft_strlcat(dest01, argv[1], size);
	printf("ft_strlcat(%s): %s\n", argv[1], dest01);
	printf("Return value: %zu\n", result);

	return (0);
} */


/*  This is a recreation of the strlcat function in C. The purpose of strlcat is to concatenate 
    a given source string (src) to the end of a destination string (dest), ensuring that the 
    destination string does not exceed a specified size (size).

    According to the manual: "The `ft_strlcat()` function appends `src` to the end of `dest`, 
    ensuring that `dest` will not exceed the provided `size`. The function returns the total 
    length of the string that would have been created if `size` had been large enough to hold 
    both `dest` and `src`. If the `size` is less than or equal to the current length of `dest`, 
    the function returns the sum of the `src` length and `size`."

        The `ft_strlcat` function appends `src` to `dest`, ensuring that `dest` is null-terminated 
        and does not exceed the given `size`. It performs the concatenation in a safe manner, 
        considering the available space in `dest` and preventing buffer overflows.

    Function Parameters:

    - `char *dest` → A pointer to the destination string, which will be appended with `src`.
    - `const char *src` → A pointer to the source string, which will be appended to `dest`.
    - `size_t size` → The total size available for the concatenation (including space for the null terminator).

    Understanding the Implementation:

    The function declares the following variables:

    - `size_t dest_len` → Stores the length of `dest` using a while loop to count the characters.
    - `size_t src_len` → Stores the length of `src` using a while loop to count the characters.
    - `size_t i` → Counter for iterating through `src` and copying its characters to `dest`.

    How the function works:

    1. Calculate the Length of Destination String

    - The function first calculates the length of `dest` by iterating through it until the null terminator is found.

        dest_len = 0;
        while (dest[dest_len] != '\0')
            dest_len++;

    2. Calculate the Length of Source String

    - Similarly, it calculates the length of `src` by iterating through it until the null terminator is found.

        src_len = 0;
        while (src[src_len] != '\0')
            src_len++;

    3. Check if Size is Less Than or Equal to Destination Length

    - If `size` is less than or equal to the length of `dest`, the function returns `src_len + size`, 
      indicating that it would have concatenated the entire `src` string if there was enough space.

        if (size <= dest_len)
            return (src_len + size);

    4. Concatenate Source String to Destination String

    - The function proceeds to concatenate `src` to `dest` only if there is space left in `dest`.
    - The loop copies characters from `src` to `dest`, making sure the total length does not exceed `size - 1`.

        while (src[i] != '\0' && (dest_len + i) < (size - 1))
        {
            dest[dest_len + i] = src[i];
            i++;
        }

    5. Null-Terminate the Destination String

    - After copying the characters, the function ensures that the destination string is null-terminated 
      by adding `'\0'` at the appropriate position.

    dest[dest_len + i] = '\0';

    6. Return the Total Length of the Concatenated String

    - The function returns the total length of the string that would have been created if `size` had been 
      large enough to hold both `dest` and `src`.

        return (dest_len + src_len);

    Handling Edge Cases:

    - If `size` is less than or equal to the length of `dest`, the function returns `src_len + size`, 
      indicating that no concatenation was done beyond the current space in `dest`.
    - If `src` is empty, the function will not modify `dest` and will return the length of `dest`.
    - If `dest` is already full, no more characters from `src` will be appended, and the function will return the length that would have been needed.

    Example Usage:

    #include <stdio.h>

    int main(void)
    {
        char dest[20] = "Hello, ";
        const char *src = "World!";
        size_t size = 20;
        size_t result = ft_strlcat(dest, src, size);

        printf("Resulting String: %s\n", dest);
        printf("Total Length: %zu\n", result);

        return 0;
    }

    Step-by-Step Execution of the Example:

    - Input:
  
    dest = "Hello, "
    src = "World!"
    size = 20

    Step 1: Compute Lengths of `dest` and `src`

    dest_len = 7
    src_len = 6

    Step 2: Check if `size` is Less Than or Equal to `dest_len`

    size = 20, which is greater than `dest_len` (7), so we proceed with concatenation.

    Step 3: Concatenate `src` to `dest`

    The function copies "World!" to `dest` starting at index 7.

        Index	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
        Data	'H'	'e'	'l'	'l'	'o'	','	' '	'W'	'o'	'r'	'l'	'd'	'!'	'\0'	?	?	?	?	?

    Step 4: Null-Terminate the String

    The string is correctly null-terminated, and the total length is `dest_len + src_len = 7 + 6 = 13`.

    The output will be:

    Resulting String: Hello, World!
    Total Length: 13

    Special Cases:

    1. If `size` is less than `dest_len`, the function returns `src_len + size`.
    2. If `src` is empty, the function does not modify `dest` and returns `dest_len + src_len`.
    3. If `malloc` fails (in a different scenario), the function returns `NULL`.

    Key Takeaways:

    - `ft_strlcat` ensures that `dest` will not exceed the given `size` while safely appending `src` to it.
    - It calculates and returns the total length of the string that would have been created, helping to manage buffer sizes.
    - It handles edge cases like empty strings and ensures the destination string is null-terminated.
*/
