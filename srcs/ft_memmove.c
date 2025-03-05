/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:54:46 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 19:06:47 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (src_ptr < dest_ptr)
	{
		dest_ptr += n;
		src_ptr += n;
		while (n > 0)
		{
            n--;
			*(--dest_ptr) = *(--src_ptr);
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dest);
}

/* int main()
{
    char str1[] = "Hello";         
    char str2[] = "World";         
    char str3[] = "Hello";         
    char str4[] = "World";         

    size_t len = 0;

    printf("Antes:\n");
    printf("str1 (original): %s\n", str1);
    printf("str3 (original): %s\n", str3);

    ft_memmove(str1, str2, len);
    printf("\nApós ft_memmove:\n");
    printf("str1 (modificada): %s\n", str1);

    memmove(str3, str4, len);
    printf("\nApós memmove:\n");
    printf("str3 (modificada): %s\n", str3);

    return (0);
} */


/*
    This is a recreation of the `memmove` function in C. The purpose of `memmove` is to copy 'n' bytes from a source memory block (`src`) 
    to a destination memory block (`dest`). The key difference between `memmove` and `memcpy` is that `memmove` handles the case where the memory regions 
    overlap, ensuring that the data is copied correctly regardless of the relative positions of the source and destination.
    `memmove` is designed to handle overlapping memory regions safely.

    According to the manual: "The `memmove` function copies `n` bytes from the memory area pointed to by `src` to the memory area pointed to by `dest`. 
    The memory areas may overlap: copying takes place as though the bytes in `src` are first copied to a temporary array, which does not overlap src or dest, and the  bytes  are
    then copied from the temporary array to dest (which does not overwrite the original data before it is copied)".

    Function Parameters:

     - `void *dest`      → A pointer to the destination memory block where the data will be copied to.
    - `const void *src` → A pointer to the source memory block from which the data will be copied.
    - `size_t n`        → The number of bytes to copy from `src` to `dest`.

    Understanding the Implementation:

    The function declares the following variables:

    - `unsigned char *dest_ptr = (unsigned char *)dest;` → Casts `dest` to `unsigned char *` 
      for byte-wise manipulation.
    - `const unsigned char *src_ptr = (const unsigned char *)src;` → Casts `src` to `const unsigned char *` 
      to ensure proper byte-wise access.

    Handling Overlapping Memory:

    - If `src` is **before** `dest` in memory (`src_ptr < dest_ptr`), copying happens **backward** 
      to prevent overwriting data before it is copied.
    - Otherwise, copying proceeds **forward** as usual.

    How the function works:

    Case 1: `src` is before `dest` (backward copy)
    
    - The function moves the pointers to the end of both blocks (`dest_ptr += n` and `src_ptr += n`).
    - It then copies bytes BACKWARD using:

        while (n > 0)
        {
            n--;
            *(--dest_ptr) = *(--src_ptr);
        }

    - This ensures that later bytes are copied before earlier ones, avoiding data corruption.

    Case 2: `src` is after `dest` (forward copy)

    - If there is no overlap issue, the function copies normally using:

        i = 0;
        while (i < n)
        {
            dest_ptr[i] = src_ptr[i];
            i++;
        }

    Handling Edge Cases:

    - If `n == 0`, the function returns immediately since there is nothing to copy.
    - If `src == dest`, no action is needed, and the function returns `dest` unchanged.
    - If `src` or `dest` is `NULL`, behavior is undefined (standard implementations do not check for `NULL`).

    Example Usage:

    Let's analyze a case where `ft_memmove` is used with overlapping memory:

        char str[] = "123456";
        ft_memmove(str + 2, str, 4);

    Step 1: Understanding the Arguments

    - `str + 2` is the destination (`dest`), meaning copying will start from `str[2]`.
    - `str` is the source (`src`), meaning we are copying data starting from `str[0]`.
    - The number `4` indicates that 4 bytes should be copied.
    - Since `src` (`str[0]`) is BEFORE `dest` (`str[2]`), and there is overlap, `ft_memmove` will copy BACKWARD.

    Step 2: Memory Before the Operation

        Index:    0    1    2    3    4    5    6
        Data:   ['1', '2', '3', '4', '5', '6', '\0']
                  ^    ^    ^    ^  
                src  src+1 src+2 src+3  

    - The characters `"1234"` (from indices `0` to `3`) need to be copied to indices `2` to `5`.

    Step 3: Copying Backward (Right to Left)

    - Instead of copying `str[0]` → `str[2]` immediately (which would overwrite `str[2]` before it can be copied),
      the function starts copying from the end (i.e., `src[3]` → `dest[3]`, then `src[2]` → `dest[2]`, etc.).

    - Step-by-step copying:

        - Copy `str[3] ('4')` to `str[5]`: `['1', '2', '3', '4', '5', '4', '\0']`
        - Copy `str[2] ('3')` to `str[4]`: `['1', '2', '3', '4', '3', '4', '\0']`
        - Copy `str[1] ('2')` to `str[3]`: `['1', '2', '3', '2', '3', '4', '\0']`
        - Copy `str[0] ('1')` to `str[2]`: `['1', '2', '1', '2', '3', '4', '\0']`

    Step 4: Memory After the Operation

        Index:    0    1    2    3    4    5    6
        Data:   ['1', '2', '1', '2', '3', '4', '\0']
                            ^    ^    ^    ^
                       dest  dest+1 dest+2 dest+3  

    Step 5: Output

        printf("%s\n", str); // Output: "121234"


    - Since there was **overlapping memory**, copying **backward** prevented data corruption.
    - Without `ft_memmove` (using `ft_memcpy` instead), the result would have been incorrect because `ft_memcpy` copies FOWARD without considering overlaps.

    `ft_memmove` ensures safe copying by handling overlap situations properly, making it a critical function when working with memory regions that might overlap.

    `ft_memmove` is a crucial function when dealing with overlapping memory blocks, ensuring data integrity during copying.
*/
