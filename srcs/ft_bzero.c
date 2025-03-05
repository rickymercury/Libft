/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:37:14 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 19:29:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*array;

	i = 0;
	array = (unsigned char *)s;
	while (i < n)
	{
		array[i] = 0;
		i++;
	}
}

/* 
int main()
{
	char str1[5] = "Hello";
	char str2[5] = "Hello";
	size_t len = 5;
    
	printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
	ft_bzero(str1, len);
	printf("str1: %s\n", str1);
    
	memset(str2, 0, len);
	printf("str2: %s\n", str2);

    return (0);
} 
*/


/*
    This is a recreation of the `bzero` function in C. The purpose of `bzero` is to set a block of memory to zero.
    According to the manual: "The `bzero` function erases the data in the `n` bytes of memory starting at the location pointed to by `s`,
    by writing zeroes (`\0`) to that area."  

    In simpler terms, this function writes `n` zero bytes to the memory area pointed to by `s`, effectively clearing 
    the contents of that memory region. This is useful for initializing or resetting memory before use.

    Function Parameters:

    - `void *s`   → A pointer to the memory block that will be set to zero.
    - `size_t n`  → The number of bytes to set to zero.

    Understanding the Implementation:

    The function declares the following variables:

    - `unsigned char *array = (unsigned char *)s;` → This casts `s` to `unsigned char *` so we can manipulate each byte.
    - `size_t i = 0;` → A counter to iterate over the memory block.

    How the function works:

    The function runs a loop from `i = 0` to `i < n`, setting each byte in `array` to `0`:

    - `array[i] = 0;` → Sets the current byte to zero.
    - `i++;` → Moves to the next byte.
    - The loop continues until all `n` bytes are set to zero.

    1. Memory Iteration: The function uses a `while` loop to iterate through the memory block.
    
    2. Setting Bytes to Zero: On each iteration, the function sets `array[i] = 0`, effectively writing `0` to the byte at index `i`.

    3. Loop Continuation: The loop continues until all `n` bytes are set to zero.

    4. No Return: The function does not return a value because it modifies the memory in place.

    Edge Cases Handled:

    - If `n == 0`, the function does nothing and the memory block remains unchanged.
    - If `s == NULL`, behavior is undefined, as `bzero` does not check for `NULL` pointers.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>

        int main(void)
        {
            char str[10] = "Hello";
            ft_bzero(str + 3, 4);
            printf("After ft_bzero: '%s'\n", str);
            return 0;
        }

    Step 1: Memory Before `ft_bzero`

    - Initially, the memory block looks like this: 

        str:  ['H', 'e', 'l', 'l', 'o', '\0', ...]
                ^    ^    ^    ^    ^
              str[0] str[1] str[2] str[3] str[4] ...

    Step 2: Function Execution (`ft_bzero(str + 3, 4)`)

    - The function starts at `str[3]` and sets the next `4` bytes to zero:
    
        - `str[3] = 0`
        - `str[4] = 0`
        - `str[5] = 0`
        - `str[6] = 0`

    Step 3: Memory After `ft_bzero` Execution

    The memory block now looks like this:

        str:  ['H', 'e', 'l', '\0', '\0', '\0', '\0', ...]
                ^    ^    ^    ^    ^    ^    ^
              str[0] str[1] str[2] str[3] str[4] str[5] str[6]

    Step 4: Output

    The program will print:

    After ft_bzero: 'Hel'

    The function has zeroed out the memory starting from `str[3]`, replacing the characters `'l'`, `'o'`, and any 
    subsequent characters with `\0` (null terminators).

    - `ft_bzero` is a useful function when you need to clear or reset a portion of memory to zero.
    - It is commonly used to clear memory buffers or structures, especially when the content is no longer needed, or to 
      ensure security by erasing sensitive data.
  
  Alternative Approach Using `memset'
      
    Instead of manually looping through each byte, we can simplify `bzero` using `memset`:

        void	ft_bzero(void *s, size_t n)
        {
            ft_memset(s, 0, n);
        }

    Since `memset` already sets a block of memory to a specific value, passing `0` achieves the same effect as `bzero`.  

    Key Differences Between `bzero` and `memset` 
     
    - `bzero(s, n)` is equivalent to `memset(s, 0, n)`, but `bzero` is deprecated in some modern systems.
    - `memset` is more flexible because it allows setting memory to any value (`memset(s, 'A', n)`, for example).

*/
