/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:07:48 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/03 20:53:46 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int main()
{
	char *dest = "Hello";
	char *src = "World";
	printf("dst string original: %s\n", dest);
	printf("src string original; %s\n", src);
	dest = ft_strdup(src);
	printf("dst string final: %s\n", dest);
	free(dest);
} */


/*
    This is a recreation of the `strdup` function in C. The purpose of `strdup` is to create a new dynamically 
    allocated copy of a given string `s` and return a pointer to it.

    According to the manual: "The strdup() function returns a pointer to a new string which is a duplicate of the 
    string s. Memory for the new string is obtained with malloc(3), and can be freed with free(3)."

    Function Parameters:

    - `const char *s` → A pointer to the string that will be duplicated.

    Understanding the Implementation:

    The function declares the following variables:

    - `char *dest` → A pointer that will store the address of the newly allocated memory for the duplicate string.
    - `int i = 0;` → A counter to iterate over the characters of `s`.

    How the function works:

    1. Allocate Memory
      
       - The function calculates the length of `s` using `ft_strlen(s)` and adds `1` for the null terminator (`\0`).
       - It then uses `malloc` to allocate enough memory to store the duplicate string.  

        dest = malloc((ft_strlen(s) + 1) * sizeof(char));

       - `malloc` returns a pointer to the allocated memory, or `NULL` if the allocation fails.

    2. Check Memory Allocation
    
       - If `malloc` fails (i.e., returns `NULL`), the function immediately returns `NULL` to prevent a segmentation fault.  

        if (!dest)
            return (NULL);

    3. Copy the String
    
       - The function iterates through `s`, copying each character into `dest` until it reaches the null terminator (`\0`).  

        while (s[i] != '\0')
        {
            dest[i] = s[i];
            i++;
        }

    4. Null-Terminate the New String
    
       - The last character of `dest` is set to `\0` to ensure it is a valid C string.  

        dest[i] = '\0';

    5. Return the Duplicated String
    
       - Finally, the function returns the pointer to `dest`, which now contains a copy of `s`.  

        return (dest);


    Handling Edge Cases:

    - If `s == NULL`, the function **does not** check for it, which means passing `NULL` to this function 
      will result in **undefined behavior** (it will try to call `ft_strlen(NULL)`, causing a segmentation fault).
    - If `malloc` fails due to insufficient memory, the function correctly handles this by returning `NULL`.
    - The function ensures that `dest` is a **valid null-terminated string**.

    Example Usage:

    Suppose we have the following code:

        #include <stdio.h>

        int main(void)
        {
            char *original = "Hello, 42!";
            char *copy = ft_strdup(original);

            if (copy)
            {
                printf("Original: %s\n", original);
                printf("Copy: %s\n", copy);
                free(copy);
            }
            return 0;
        }

    Step 1: Understanding the Arguments

    - `original = "Hello, 42!"` (a string stored in read-only memory).
    - `copy = ft_strdup(original)` → This function will create a new string with the same content.

    Step 2: Memory Allocation and Duplication

    - `ft_strlen(original) + 1` → The function calculates the memory needed: 
     
      `"Hello, 42!"` has 11 characters + 1 (`\0`), so `malloc(12)` bytes.
      
    - Copies character by character into `copy`.

    Step 3: Final Memory Representation

        Address:   [0x100]  [0x101]  [0x102]  [0x103]  [0x104]  [0x105]  [0x106]  [0x107]  [0x108]  [0x109]  [0x10A]  [0x10B]
        Original:   'H'      'e'      'l'      'l'      'o'      ','      ' '      '4'      '2'      '!'      '\0'  
        Copy:       'H'      'e'      'l'      'l'      'o'      ','      ' '      '4'      '2'      '!'      '\0'  

    Step 4: Output

        Original: Hello, 42!
        Copy: Hello, 42!

    Key Takeaway:  

    - `ft_strdup` is useful when you need a **new** copy of a string that you can modify independently.
    - Since it uses `malloc`, the returned string must be **freed** after use to prevent memory leaks.
*/
