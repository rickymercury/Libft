/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:23:04 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 19:15:31 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* 
int main()
{
	char str[10];

	size_t len = 13;
	ft_memset(str, 'A', len);
	printf("ft_memset: %s\n", str);
}
*/


/*
    This is a recreation of the `memset` function in C. The purpose of `memset` is to fill the first `n` bytes 
    of the memory area pointed to by `s` with the specified byte value `c`.

    According to the manual: "The `memset` function fills the first `n` bytes of the memory area pointed to by `s`
    with the constant byte `c`."

    Function Parameters:

    - `void *s`  → A pointer to the memory block that will be filled.
    - `int c`    → The byte value to fill the memory with, passed as an `int` but cast to `unsigned char`.
    - `size_t n` → The number of bytes to fill.

    Understanding the Implementation:

    The function declares the following variables:

    - `unsigned char *array = (unsigned char *)s;` → Casts `s` to `unsigned char *` to allow byte-wise manipulation.
       It ensures that `c` is treated as a single byte and avoids potential issues when `c` is negative (since `char` can be signed).
       
       Since `s` is a `void *`, it is a generic pointer, meaning it can point to ANY data type. However, `void *` CANNOT 
       be dereferenced directly, which is why we CAST it to `unsigned char *`. This allows us to access and modify the memory 
       byte by byte (individually).
       
    - `size_t i = 0;` → A counter to keep track of the position in the memory block.

    How the function works:

    - The function iterates from `i = 0` to `i < n`, setting each byte of the memory block to `(unsigned char)c`.
    - It modifies the memory directly, ensuring that all `n` bytes are replaced with the given value.
    - The function returns `s`, allowing for chaining operations if needed.

        while (i < n)
        {
            array[i] = (unsigned char)c;
            i++;
        }

    - `array[i] = (unsigned char)c;` → Sets the current byte to `c` (converted to `unsigned char` to ensure correct behavior).
    - `i++;` → Moves to the next byte.
    - The loop continues until all `n` bytes are set.

    Finally, the function returns the original pointer `s`, allowing for chaining operations.


    Handling Edge Cases:

    - If `n == 0`, the function does nothing and returns `s`.
    - If `s` is `NULL`, behavior is undefined (standard implementations do not check for `NULL`).
    - The function does **not** stop at `\0` (null-terminator) since it treats `s` as a raw memory block.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>
        #include <string.h>

        int main(void)
        {
            char str[10] = "HelloWorld";
            ft_memset(str, '*', 5);
            printf("%s\n", str);
            return 0;
        }

    Step 1: Understanding the Arguments

    - `str` is an array: `['H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
    - `c` is `'*'` (ASCII `42`), so we will replace bytes with `'*'`.
    - `n` is `5`, meaning we replace the first **5** characters.

    Step 2: Memory Before `ft_memset` Execution

        Index:    0    1    2    3    4    5    6    7    8    9
        Data:   ['H', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']
                  ^    ^    ^    ^    ^    
                  s    s+1  s+2  s+3  s+4  (first 5 bytes to be replaced)

    Step 3: Filling Memory with `'*'`

    - The function sets:

        - `str[0] = '*'` → `['*', 'e', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[1] = '*'` → `['*', '*', 'l', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[2] = '*'` → `['*', '*', '*', 'l', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[3] = '*'` → `['*', '*', '*', '*', 'o', 'W', 'o', 'r', 'l', 'd']`
        - `str[4] = '*'` → `['*', '*', '*', '*', '*', 'W', 'o', 'r', 'l', 'd']`

    Step 4: Memory After `ft_memset` Execution

        Index:    0    1    2    3    4    5    6    7    8    9
        Data:   ['*', '*', '*', '*', '*', 'W', 'o', 'r', 'l', 'd']
                  ^    ^    ^    ^    ^
                (first 5 bytes replaced with '*')

    Step 5: Output

      printf("%s\n", str); // Output: "*****World"

    Key Takeaway:  

    - `ft_memset` is useful for initializing memory regions with a specific byte.
    - It is commonly used for clearing buffers, setting default values, or erasing sensitive data.
*/
