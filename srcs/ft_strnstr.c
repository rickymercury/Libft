/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:30:35 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/04 21:20:58 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/* int main(int argc, char **argv)
{
    if (argc == 4)
    {
        char *result_ft = ft_strnstr(argv[1], argv[2], atoi(argv[3]));

        if (result_ft != NULL)
            printf("ft_strnstr: %s\n", result_ft);
    }
    return (0);
} */

/* 
$ cc -Wall -Werror -Wextra ft_strnstr.c
$ ./a.out "Hello, World of 42" "World" 15
ft_strnstr: World of 42 
*/

/*  
    This is a recreation of the strnstr function in C. The purpose of strnstr is to find the first occurrence 
    of a substring (little) in a given string (big), but only up to a specified length (len).

    According to the manual: "The `ft_strnstr()` function locates the first occurrence of the string `little` 
    in the string `big`, not exceeding `len` characters. If `little` is found, the function returns a pointer 
    to the first character of the found substring in `big`. If `little` is not found, the function returns `NULL`."

    The `ft_strnstr` function is useful when you need to limit the search to a specific length and avoid unnecessary
    comparisons beyond that length.

    Function Parameters:
    
    - `const char *big` → A pointer to the main string in which to search.
    - `const char *little` → A pointer to the substring to find.
    - `size_t len` → The maximum number of characters to search in `big`.

    Understanding the Implementation:
    
    The function declares the following variables:
    
    - `size_t i` → A counter for iterating through `big`.
    - `size_t j` → A counter for iterating through `little`.

    How the function works:
    
    1. Check for an Empty Substring (`little`):
    
    - If `little` is an empty string (`""`), the function immediately returns a pointer to `big`, as an empty string is
      always considered to be found at the beginning of any string.
    
        if (!*little)
            return ((char *)big);

    2. Iterate Through the Main String (`big`):
    
    - The outer `while` loop starts at the beginning of `big` and runs while `i < len` and `big[i]` is not the null
      terminator (`\0`).
    
        while (big[i] != '\0' && i < len)

    3. Compare Substring with Part of `big`:
    
    - Inside the loop, another `while` loop compares each character of `little` with the corresponding characters in
      `big` starting from index `i`.
    - If a mismatch occurs or the entire `little` string is found, the loop stops.
    - The comparison stops if `i + j` exceeds `len` to ensure that the search is within the specified length.
    
        while (little[j] != '\0' && big[i + j] == little[j] && (i + j) < len)

    4. Check for a Match:
    
    - If the inner loop completes and all characters of `little` match the corresponding characters in `big`, the
      function returns a pointer to the first character of the matching substring in `big`.
    
        if (little[j] == '\0')
            return ((char *)(big + i));

    5. Move to the Next Character:
    
    - If no match is found at position `i`, the outer loop increments `i` and continues searching.
    
        i++;

    6. Return `NULL` If No Match:
    
    - If the function does not find any match by the time it has checked all possible substrings within `len`, it returns `NULL`.
    
        return (NULL);

    Special Cases:

    - If `little` is an empty string, the function returns a pointer to `big`.
    - If `big` does not contain `little` within the first `len` characters, the function returns `NULL`.
    - If `len` is smaller than the length of `little`, the function does not find any match and returns `NULL`.

    Example Usage:
    
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, char **argv)
    {
        if (argc == 4)
        {
            // Use atoi to convert string to integer
            size_t len = atoi(argv[3]);
    
            // Get result from ft_strnstr
            char *result = ft_strnstr(argv[1], argv[2], len);
    
            // Print the result
            if (result != NULL)
                printf("ft_strnstr: %s\n", result);
        }
        return 0;
    }

    Step-by-Step Execution of the Example:

    - Input:

        s1 = "Hello, World of 42"  
        s2 = "World"  
        len = 15  
    
    Step 2: Compare `s2` with substrings of `s1` (up to length 15)

        The function compares the first few characters of `s1` with `s2`:

        - First comparison: `"Hello, "` → Does not match `"World"`.
        - Second comparison: `" World"` → Matches the substring `"World"`.

    Step 3: Return the Pointer to the Match

        Once the match is found, the function returns the pointer to `"World"` in `s1`.

        Output:

        ft_strnstr: World of 42

    Special Cases:

    1. Empty `little`: If `little` is an empty string, the function returns the entire `big` string:
        
        ./program "Hello, World" "" 10

        Output:
        
        ft_strnstr: Hello, World

    2. No Match Found: If `little` is not found in `big`, the function returns `NULL`:

        ./your_program "Hello, World" "42" 10

        Output:

    3. Length Exceeded:
      
        If `len` is smaller than the length of `little`, no match will be found, and the function will return `NULL`:

        ./your_program "Hello, World" "World" 5

        Output:

    Key Takeaways:

    - `ft_strnstr` allows you to search for a substring within a string, with an optional length constraint to limit the search.
    - It returns a pointer to the first occurrence of the substring if found, or `NULL` if not.
    - The function handles edge cases, such as empty substrings and no matches, effectively.
    - It is memory-efficient, as it does not require dynamic memory allocation and only works with pointers and comparisons.

*/
