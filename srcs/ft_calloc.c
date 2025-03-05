/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:16:09 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 19:23:14 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buffer;

    if (nmemb == 0 || size == 0)
    {
        return (malloc(0));
    }
	if (nmemb != 0 && size > (size_t)(-1) / nmemb)
    {
		return (NULL);
    }
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, nmemb * size);
	return (buffer);
}

/* int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);

	size_t nmemb = atoi(argv[1]);
	size_t size = atoi(argv[2]);

	char *res_ft_calloc = ft_calloc(nmemb, size);
	char *res_memset = calloc(nmemb, size);

	printf("ft_calloc: %p \n", res_ft_calloc);
	printf("calloc: %p", res_memset);

	free(res_ft_calloc);
	free(res_memset);

	return 0;
} */


/*
    This is a recreation of the `calloc` function in C. The purpose of `calloc` is to allocate memory for an array of
    'nmemb' elements, eahc of 'size' bytes, and initialize the entire memory block to zero.
        
    According to the manual: "The `calloc` function allocates memory for an array of `nmemb` elements of `size` bytes
    each, and returns a pointer to the allocated memory. The memory is set to zero."

    In simpler terms, `calloc` allocates memory for an array and ensures that all bytes in that memory block are set to
    zero.
    This is commonly used to prevent using uninitialized memory, which could lead to undefined behavior or bugs.

    Function Parameters:

    - `size_t nmemb` → The number of elements to allocate.
    - `size_t size`  → The size of each element in bytes.

    Understanding the Implementation:

    The function declares the following variables:

    - `void *buffer;` → A pointer to the allocated memory block.
    
    Step-by-step Breakdown of the Function:

    1. Edge Case Check for Zero Allocation:
    
        The function first checks if either `nmemb == 0` or `size == 0`. If this is the case, it allocates 0 bytes 
        using `malloc(0)`. The behavior of `malloc(0)` is platform-dependent, but it typically returns a non-NULL pointer 
        to a valid memory region with zero size, or `NULL` if the system cannot allocate zero bytes.

        if (nmemb == 0 || size == 0)
        {
            return (malloc(0));
        }

    2. Check for Integer Overflow:

        The next check ensures there is no overflow when calculating the total memory size (`nmemb * size`). If the result 
        of `nmemb * size` exceeds the maximum value of `size_t`, which would cause an overflow and lead to incorrect memory allocation,
        the function returns `NULL`.

        if (nmemb != 0 && size > (size_t)(-1) / nmemb)
        {
            return (NULL);
        }

    3. Memory Allocation:

        After passing the above checks, the function proceeds to allocate the requested memory using `malloc(nmemb * size)`. 
        If memory allocation fails (i.e., `malloc` returns `NULL`), it returns `NULL` to signal failure.

        buffer = malloc(nmemb * size);
        if (!buffer)
            return (NULL);

    4. Zero Initialization:

        Once the memory has been successfully allocated, the function uses `ft_bzero` to fill the entire memory block with zeros. 
        `ft_bzero` is a custom function that works like `memset` but specifically sets all bytes to zero.

        ft_bzero(buffer, nmemb * size);

    5. Return the Allocated Memory:

        Finally, the function returns the pointer to the allocated and zero-initialized memory block.

        return (buffer);

    Edge Cases Handled:

    - If either `nmemb == 0` or `size == 0`, the function returns `malloc(0)`.
    - If `nmemb * size` exceeds the maximum allowed value for `size_t`, it returns `NULL`.
    - If memory allocation fails, it returns `NULL`.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>
        #include <stdlib.h>

        int main(void)
        {
            size_t nmemb = 5;
            size_t size = sizeof(int);
            int *arr = ft_calloc(nmemb, size);

            if (arr)
            {
                for (size_t i = 0; i < nmemb; i++)
                {
                    printf("arr[%zu] = %d\n", i, arr[i]);
                }
                free(arr);
            }
            return 0;
        }

    Step 1: Memory Allocation

    - The function allocates space for an array of `5` integers (each of size `sizeof(int)`).

    Step 2: Memory After Allocation (Initialized to Zero)

    The memory allocated looks like this:

        arr:  [0, 0, 0, 0, 0]
               ^  ^  ^  ^  ^
               arr[0] arr[1] arr[2] arr[3] arr[4]

    Each element is initialized to zero.

    Step 3: Output

    The program will print:

        arr[0] = 0
        arr[1] = 0
        arr[2] = 0
        arr[3] = 0
        arr[4] = 0

    - `ft_calloc` is essential for allocating and initializing memory to zero, commonly used for initializing arrays 
      or buffers before use.
    - The function safely handles edge cases like zero-sized allocations and overflow during multiplication.

     Key Differences Between `malloc` and `calloc`:
    
    - `malloc` only allocates memory but does NOT INITIALIZE it. The memory may contain garbage values.
    - `calloc`, on the other hand, ALLOCATES AND INITIALIZES the memory to zero, making it safer to use right after
       allocation.

*/




































/************************************* EXAMPLE **************************************************************************

    Suppose we want to allocate memory for 5 integers, each of size `sizeof(int)`:

        int *arr = ft_calloc(5, sizeof(int));

    This will allocate memory for 5 integers and initialize all of them to `0`.

    **Memory before `ft_calloc`:**  

    Uninitialized memory (could contain random values).

    **Memory after `ft_calloc`:**  
    
    00 00 00 00 00   (All integers are zeroed out)


**************************************************************************************************************************/

/************************************************ MANUAL ******************************************************
CALLOC(3) (simplified)

NAME
    calloc -- memory allocation
SYNOPSIS
    void *calloc(size_t count, size_t size);
DESCRIPTION
    The calloc() function allocates memory.
    The allocated memory is aligned such that it can be used for any data type.
    The calloc() function contigously allocates enough space for count objects that are size bytes of memory
    each and returns a pointer to the allocated memory.
    The allocated memory is filled with bytes of value zero.
RETURN VALUES
    If successful, calloc() returns a pointer to allocated memory. If there is an error, they return a NULL
    pointer and set errno to ENOMEM.
***************************************************************************************************************/
