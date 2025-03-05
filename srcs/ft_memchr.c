/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:53:28 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:51:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/* 
int main()
{
	size_t n = 2;
	int c = 'e';
	const char str_memchr[10]= "Hello";
	
	printf("ft_memchr: %p\n", ft_memchr(str_memchr, c, n));
	printf("memchr: %p\n", memchr(str_memchr, c, n));
}
*/


/*
    This is a recreation of the `memchr` function in C. The purpose of `memchr` is to locate the first occurrence 
    of a specific byte (`c`) in a given memory block (`s`). It searches up to `n` bytes and returns a pointer 
    to the first occurrence of `c` or `NULL` if the byte is not found.
    The search stops as soon as the byte is found, or after `n` bytes have been scanned.

    According to the manual: "The `memchr` function scans the first `n` bytes of the memory area pointed to by `s` for the first occurrence 
    of the byte `c` (interpreted as an unsigned char). The function returns a pointer to the matching byte or NULL 
    if the character does not occur in the given memory range."

    Function Parameters:

    - `const void *s`  → A pointer to the memory block to be searched.
    - `int c`          → The byte value to search for, passed as an `int` but treated as an `unsigned char`. 
                         Although it's an `int`, it is cast to `unsigned char` before comparison.
    - `size_t n`       → The number of bytes to scan from `s`.

    Understanding the Implementation:

    The function declares the following variables:

    - `unsigned char *ptr = (unsigned char *)s;` → A pointer to `s`, cast to `unsigned char *` 
       so we can access individual bytes.
    - `size_t i = 0;` → A counter to keep track of our position in the memory block.

    Handling Edge Cases:

    - If `n` is `0`, the function immediately returns `NULL` since there’s no memory to search.
    - If `s` is `NULL`, behavior is undefined (standard implementations of `memchr` do not check for `NULL`).
    - The function **does not stop** at `\0` (null-terminator), since it treats `s` as a raw memory block, not a string.

    How the function works:

    The function loops through the memory block, checking each byte:

        while (i < n)
        {
            if (ptr[i] == (unsigned char)c)
                return ((void *)(ptr + i));
            i++;
        }

    - `ptr[i] == (unsigned char)c` → Checks if the current byte matches `c`.
    - If a match is found, it returns a pointer to that byte.
    - If the loop completes without finding `c`, it returns `NULL`.

    Example Usage:

    Suppose we have the following code:

        char str[] = "Hello, World!";
        char *result = ft_memchr(str, 'W', strlen(str));

    **Memory representation (`str` before `ft_memchr` search):**
    
        48 65 6C 6C 6F 2C 20 57 6F 72 6C 64 21   (ASCII for "Hello, World!")

    `ft_memchr` searches for `'W'` (ASCII `0x57`).
      
    - It starts at index `0` and scans each byte until it finds `0x57` at index `7`.  
    - The function returns a pointer to `str[7]`, which holds `'W'`.  
    - If `'W'` was NOT found, it would return `NULL`.  

    Example Output: 

        printf("%s\n", result); // Output: "World!"

    The function efficiently locates a byte in a memory block, returning a pointer to its first occurrence or `NULL` if not found.
*/
