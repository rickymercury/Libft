/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:49:01 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/04 20:27:20 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
    if (n == 0)
		return (0);
	while (ptr1[i] != '\0' && ptr1[i] == ptr2[i] && i < n - 1)
        i++;
	return (ptr1[i] - ptr2[i]);
}

/* int main(void)
{	
	char s1_strncmp[] = "Hello\r";
	char s2_strncmp[] = "Hello\t";
    
	printf("ft_strncmp: %d\n", ft_strncmp(s1_strncmp, s2_strncmp, 7));
	printf("strncmp: %d\n", strncmp(s1_strncmp, s2_strncmp, 7));

    return (0);
} */


/* This is a recreation of the ft_strncmp function in C. The purpose of ft_strncmp is to compare 
   at most n characters of two strings (s1 and s2). The function determines the lexicographical 
   order of the strings based on their ASCII values.

    According to the manual: "The `ft_strncmp()` function compares at most `n` bytes of `s1` and `s2`. 
    It returns an integer less than, equal to, or greater than zero if `s1` is found to be less than, 
    to match, or be greater than `s2`, respectively."

    Function Purpose:

    The `ft_strncmp` function compares two strings up to `n` characters, returning the difference 
    between the first differing characters. If the strings are identical up to `n` characters, 
    the function returns `0`. The comparison is done using unsigned characters to avoid negative 
    values interfering with the results.

    Function Parameters:

    - `const char *s1` → A pointer to the first string to be compared.
    - `const char *s2` → A pointer to the second string to be compared.
    - `size_t n` → The maximum number of characters to compare between `s1` and `s2`.

    Understanding the Implementation:

    The function declares the following variables:

    - `size_t i` → A counter to iterate through the characters of `s1` and `s2`.
    - `unsigned char *ptr1` → A pointer to `s1` cast to an unsigned char pointer to ensure the comparison 
       is done using unsigned characters.
    - `unsigned char *ptr2` → A pointer to `s2` cast to an unsigned char pointer for the same reason.

    How the function works:

    1. Edge Case: If `n` is 0, return 0

    - If the maximum comparison length (`n`) is zero, the function immediately returns `0`, as no 
      characters should be compared.

        if (n == 0)
            return (0);

    2. Iterate Through the Strings

    - A `while` loop iterates through `s1` and `s2` character by character.
    - The loop stops if one of the following conditions is met:
    
        - Either `ptr1[i]` or `ptr2[i]` reaches `'\0'` (end of string).
        - The counter `i` reaches `n - 1`, ensuring no more than `n` characters are compared.
    
    - The condition `ptr1[i] == ptr2[i]` ensures that the loop continues only as long as the characters match.
    - The condition `ptr1[i] != '\0'` ensures the loop does not run past the end of the strings.

        while (ptr1[i] != '\0' && ptr1[i] == ptr2[i] && i < n - 1)
            i++;

    3. Return the Difference

    - After the loop ends, the function returns the difference between the characters at position `i` in `s1` 
      and `s2`. If the characters match, it will return `0`. If the characters differ, it returns their ASCII 
      difference, allowing the lexicographical ordering to be determined.

        return (ptr1[i] - ptr2[i]);

    Handling Edge Cases:

    - If `n` is `0`, the function does not compare anything and immediately returns `0`.
    - If `s1` and `s2` are identical up to `n` characters, the function returns `0`.
    - If `s1` is a prefix of `s2` (or vice versa), the function stops at `n` characters.
    - The function compares unsigned characters, avoiding issues with negative values in signed chars.

    Example Usage:

    #include <stdio.h>

    int main(void)
    {
        char *str1 = "Hello, World!";
        char *str2 = "Hello, There!";
        size_t n = 7;

        int result = ft_strncmp(str1, str2, n);

        if (result == 0)
            printf("The strings are equal up to %zu characters.\n", n);
        else if (result > 0)
            printf("\"%s\" is greater than \"%s\" up to %zu characters.\n", str1, str2, n);
        else
            printf("\"%s\" is less than \"%s\" up to %zu characters.\n", str1, str2, n);

        return 0;
    }

    Step-by-Step Execution of the Example:

    - Input:

        str1 = "Hello, World!"
        str2 = "Hello, There!"
        n = 7

    - Step 1: Compare the first 7 characters:

        H == H
        e == e
        l == l
        l == l
        o == o
        , == ,
      ' ' == ' '

    - Since all 7 characters match, `ft_strncmp` returns `0`, meaning the strings are equal up to `n` characters.

    Special Cases:

    1. If `n = 0`, the function returns `0` immediately.
    2. If `s1` and `s2` are the same up to `n` characters, the function returns `0`.
    3. If `s1` is lexicographically greater than `s2`, it returns a positive value.
    4. If `s1` is lexicographically smaller than `s2`, it returns a negative value.
    5. If `s1` or `s2` ends before `n` characters, the function correctly returns the ASCII difference.

    Key Takeaways:

    - `ft_strncmp` provides a controlled way to compare strings up to a given length.
    - It prevents buffer overflows by stopping at `n` characters.
    - It correctly handles lexicographical ordering based on ASCII values.
    - It ensures characters are treated as unsigned to prevent negative values affecting the results.

*/