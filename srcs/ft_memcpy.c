/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:59:11 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:40:20 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
    
	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}

/* int main()
{
    char str1[] = "Hello";         
    char str2[] = "World";         
    char str3[] = "Hello";         
    char str4[] = "World";         

    size_t len = 5;

    printf("Antes da cópia:\n");
    printf("str1 (original): %s\n", str1);
    printf("str3 (original): %s\n", str3);

    ft_memcpy(str1, str2, len);
    printf("\nApós ft_memcpy:\n");
    printf("str1 (modificada): %s\n", str1);

    memcpy(str3, str4, len);
    printf("\nApós memcpy:\n");
    printf("str3 (modificada): %s\n", str3);

    return (0);
} */


 /*
    This is a recreation of the `memcpy` function in C. The purpose of `memcpy` is to copy a block of memory from 
    a source (`src`) to a destination (`dest`) for a specified number of bytes (`n`).

    According to the manual: "The `memcpy` function copies `n` bytes from memory area `src` to memory area `dest`. 
    The memory areas must not overlap. Use `memmove` if overlapping is possible."
    This means that it takes `n` bytes from the source memory (`src`) and places them in the destination memory (`dest`),
    byte by byte.

    Function Parameters:

    - `void *dest`  → A pointer to the memory area (destination memory block) where the data (content) will be copied to.
    - `const void *src` → A pointer to the memory area (source memory block) from which data (content) will be copied.
    - `size_t n`    → The number of bytes to copy from `src` to `dest`. `size_t` ensures that the function can safely handle large sizes of memory.

    Understanding the Implementation:

    - The function first declares:
    
        - `unsigned char *dest_ptr` → A pointer to `dest`, cast to `unsigned char *` so that we can access each byte individually.
        - `unsigned char *src_ptr`  → A pointer to `src`, cast to `unsigned char *` so that we can access each byte individually.
        - `size_t i = 0;` → A counter to iterate through `n` bytes.

    - It then enters a loop that iterates `n` times:

        - Each byte from `src_ptr` is copied into `dest_ptr` at the corresponding position.
        - The loop continues until all `n` bytes have been copied.

    Handling Edge Cases:

    - If `n == 0`, the function does nothing and simply returns `dest`.
    - If `dest` and `src` overlap, behavior is **undefined**. The function does not account for this scenario.
    - If `src` or `dest` is `NULL`, behavior is also undefined unless `n == 0` (since no memory access occurs).

    **Important:** If `src` and `dest` may overlap, `memmove` should be used instead, as it safely handles memory overlaps.

    Example Usage:

    Suppose we have the following code:

        char src[] = "Hello, World!";
        char dest[20];

        ft_memcpy(dest, src, 6);
        dest[6] = '\0';  // Manually null-terminating the string

        printf("%s\n", dest); // Output: "Hello,"

    **Memory representation before and after `ft_memcpy`:**

    Before copying:

        src:  [H] [e] [l] [l] [o] [,] [ ] [W] [o] [r] [l] [d] [!]
        dest: [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?] [?]

    After copying:

        dest: [H] [e] [l] [l] [o] [,] [?] [?] [?] [?] [?] [?] [?]

    The function efficiently copies `n` bytes from `src` to `dest`, assuming no memory overlap occurs.
*/
