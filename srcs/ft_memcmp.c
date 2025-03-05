/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:14:53 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:47:41 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t  			    i;
	unsigned char		*ptr1;
	unsigned char	    *ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
		{
			return (ptr1[i] - ptr2[i]);
		}
		i++;
	}
	return (0);
}

/* 
int main()
{
	char str_memcmp1[] = "Hello World";
	char str_memcmp2[] = "HelloWorld";

	int res_mine = ft_memcmp(str_memcmp1, str_memcmp2, 10);
	int res_orig = memcmp(str_memcmp1, str_memcmp2, 10);

	printf("ft_memcmp: %d\n", res_mine);
	printf("memcmp: %d\n", res_orig);

	return 0;
} 
*/


/*
    This is a recreation of the `memcmp` function in C. The purpose of `memcmp` is to compare two memory blocks 
    (`s1` and `s2`) byte by byte for the first `n` bytes and determine if they are identical or different.

    According to the manual: "The `memcmp` function compares the first `n` bytes (each interpreted as unsigned char) of the memory
    areas `s1` and `s2`. It returns an integer less than, equal to, or greater than zero if the first `n` bytes of `s1` are found, 
    respectively, to be less than, to match, or to be greater than the first `n` bytes of `s2`."
    For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes that differ in
    s1 and s2.
    If n is zero, the return value is zero.

    In simpler terms, this function:
    
    - Compares two memory regions byte by byte.
    - Stops at the first differing byte or after checking `n` bytes.
    - Returns:
    
        - `0` if both memory areas are identical.
        - A POSITIVE VALUE if `s1` is greater than `s2`.
        - A NEGATIVE VALUE if `s1` is less than `s2`.

    Function Parameters:

    - `const void *s1` → A pointer to the first memory block to compare.
    - `const void *s2` → A pointer to the second memory block to compare.
    - `size_t n`       → The number of bytes to compare.

    Understanding the Implementation:

    - The function first declares:
    
        - `unsigned char *ptr1` → A pointer to `s1`, cast to `unsigned char *` for accessing individual bytes safely.
        - `unsigned char *ptr2` → A pointer to `s2`, cast to `unsigned char *` for acessing individual bytes safely.
        - `size_t i = 0;` → A counter to iterate through `n` bytes.

    - It then enters a loop that iterates `n` times:

        - If `ptr1[i]` is different from `ptr2[i]`, the function returns `ptr1[i] - ptr2[i]`, which gives:
        
            - A NEGATIVE value if `ptr1[i]` is smaller than `ptr2[i]`.
            - ZERO if both bytes are equal.
            - A POSITIVE value if `ptr1[i]` is greater than `ptr2[i]`.
            
        - If all `n` bytes are equal, the function returns `0`.

    Handling Edge Cases:

    - If `n == 0`, the function returns `0` immediately, since there is nothing to compare.
    - If `s1` or `s2` is `NULL`, behavior is undefined (standard implementations do not check for `NULL`).
    - The function does NOT stop at the first null byte (`\0`), as it treats memory as a raw block, not a string.

    Example Usage:

    1 - Suppose we have the following code:

        char str1[] = "Hello, World!";
        char str2[] = "Hello, world!";

        int result = ft_memcmp(str1, str2, 13);

        if (result < 0)
            printf("str1 is less than str2\n");
        else if (result > 0)
            printf("str1 is greater than str2\n");
        else
            printf("str1 and str2 are equal\n");

    **Memory representation of `str1` and `str2`:**

        str1: [H] [e] [l] [l] [o] [,] [ ] [W] [o] [r] [l] [d] [!]
        str2: [H] [e] [l] [l] [o] [,] [ ] [w] [o] [r] [l] [d] [!]

    - The function compares each byte until it finds `'W'` (ASCII `87`) in `str1` and `'w'` (ASCII `119`) in `str2`.
    - Since `87 - 119 = -32`, `ft_memcmp` returns a negative value, meaning `str1` is "less than" `str2`.

    2 - Suppose we have the following code:

        char str1[] = "hello";
        char str2[] = "hellz";

        int result = ft_memcmp(str1, str2, 5);

    **Memory comparison:**
    
    str1:  h  e  l  l  o  
            │  │  │  │  └── 'o' (111)  
            │  │  │  │      ≠  
            │  │  │  │      'z' (122)  
    str2:  h  e  l  l  z  

    Since `'o'` (111 in ASCII) is less than `'z'` (122),  
    `ft_memcmp` returns a negative value.

    The function efficiently determines whether two memory blocks are identical or which one is greater if they differ.
*/
