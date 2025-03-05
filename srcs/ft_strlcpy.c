/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:46:24 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/04 18:51:10 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

    if (!src)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
    if (size == 0)
		return (src_len);
	if (size > 0)
	{
        i = 0;
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/* int main()
{
    char src[] = "Hello, World!";
    char dest[20];
    size_t size = 16;

    size_t result = ft_strlcpy(dest, src, size);
    printf("ft_strlcpy(%s): %s\n", src, dest);
    printf("Length of source string: %zu\n", result);

    return (0);
} */


/*
This is a recreation of the strlcpy function in C. The purpose of strlcpy is to copy a string from src to dest, ensuring
that the destination string is null-terminated and that no more than size - 1 characters are copied.

According to the manual: "The ft_strlcpy() function copies up to size - 1 characters from the string src to dest, and
always null-terminates the result (unless size is zero). It returns the total length of the string it tried to create
(i.e., the length of src)."

    The `ft_strlcpy` function copies characters from the source string `src` into the destination string `dest`, making sure
    to null-terminate the string.
    It ensures that no more than `size - 1` characters are copied, and it always places a null terminator at the end of `dest`. 
    If `size` is 0, the function does not copy any characters but still returns the length of `src`.

Function Parameters:

    char *dest → A pointer to the destination string, where the characters from src will be copied.
    const char *src → A pointer to the source string, which will be copied to dest.
    size_t size → The size of the destination buffer, including space for the null terminator.

Understanding the Implementation:

The function declares the following variables:

    size_t i → A counter used for iterating through the characters of src.
    size_t src_len → A variable used to store the length of src.

How the function works:

    Check for a NULL src:

        The function first checks if src is NULL. If it is, the function returns 0, as it is not possible to copy a NULL string.

        if (!src) return (0);

    Calculate the length of src:

        The function calculates the length of src by iterating through each character until the null terminator is encountered.

        src_len = 0; 
        while (src[src_len] != '\0') 
            src_len++;

    Handle the case when size == 0:

        If size is 0, no characters are copied, and the function simply returns the length of src without performing any copying.

        if (size == 0) return (src_len);

    Copy characters from src to dest:

        The function copies characters from src to dest, ensuring that no more than size - 1 characters are copied. It terminates
        the string at the end of the copied characters.

        while (src[i] != '\0' && i < size - 1)
        { 
            dest[i] = src[i]; 
            i++; 
        } 
        dest[i] = '\0';

    Return the length of src:

        The function returns the length of src, which indicates the full length of the string, even though only a part of it may have been copied.

        return (src_len);

    Handling Edge Cases:

        If src is NULL, the function returns 0.
        If size is 0, no characters are copied, and the function returns the length of src.
        If size is greater than the length of src, the entire string is copied, and the destination string is null-terminated.
        If src is larger than size - 1, only size - 1 characters are copied, and the destination string is null-terminated after the copied characters.

    Example Usage:

    #include <stdio.h>

    int main(void)
    {
        char src[] = "Hello, World!";
        char dest[20];
        size_t size = 16;

        size_t result = ft_strlcpy(dest, src, size);
        printf("ft_strlcpy(%s): %s\n", src, dest);
        printf("Length of source string: %zu\n", result);

        return 0;
    }

    Step-by-Step Execution of the Example:

    Input:

    src = "Hello, World!" 
    dest = (empty string, buffer size 20) 
    size = 16

    Step 1: Memory Allocation and Setup

    - `dest` is a buffer of size 20, large enough to hold the copied string.
    - `size = 16`, which means at most 15 characters can be copied (leaving space for the null terminator).

    Step 2: Copy Characters from src to dest

    - The first 15 characters of `src` ("Hello, World!") are copied to `dest`.
    - The 16th character position is reserved for the null terminator (`\0`).

    After copying, `dest` will contain "Hello, World" and be null-terminated.

    Step 3: Return the Length of src

    - The function returns `13`, which is the length of `src`.

    Final Output:

    ft_strlcpy(Hello, World!): Hello, World
    Length of source string: 13

    
    Special Cases:

    If src is NULL:
        The function returns 0.

    If size is 0:
        No characters are copied, and the function returns the length of src.

    If size is greater than the length of src:
        The entire string is copied, and the destination string is null-terminated.

Key Takeaways:

    ft_strlcpy ensures that no more than size - 1 characters are copied, protecting against buffer overflow.
    The function always null-terminates the destination string.
    It returns the length of the source string, providing a way to check if the destination buffer was large enough to hold the source string.
    It is useful for safely copying strings in memory-constrained environments.
*/