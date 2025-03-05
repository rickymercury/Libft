/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:23:34 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:26:28 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isalpha(%c): %i\n", argv[1][0], ft_isalpha(argv[1][0]));
	return (0);
} */

/*
    This is a recreation of the `isalpha` function in C. The purpose of `isalpha` is to check whether a given character 
    is an alphabetic letter, meaning it is either an uppercase (A-Z) or a lowercase (a-z) letter.

    According to the manual: "The `isalpha` function checks whether the given character is an alphabetic letter. 
    It returns a nonzero value if `c` is a letter, and `0` otherwise."

    Function Parameters:

    - `int c` → The character to be checked, passed as an `int`. Although it is an `int`, it is typically a `char` 
                that has been promoted to `int` when passed as an argument.

    Understanding the Implementation:

    The function checks whether `c` falls within one of the following ASCII ranges:

    - `'a'` to `'z'` (ASCII values 97 to 122) → Ensures `c` is a lowercase letter.
    - `'A'` to `'Z'` (ASCII values 65 to 90)  → Ensures `c` is an uppercase letter.

    If `c` belongs to either of these ranges, the function returns `1`, indicating that `c` is an alphabetic character.
    Otherwise, it returns `0`.

    Handling Edge Cases:

    - If `c` is a digit (`0-9`), the function returns `0`.
    - If `c` is a special character (e.g., `@`, `#`, `!`), the function returns `0`.
    - If `c` is a whitespace character (e.g., space, tab, newline), the function returns `0`.
    - If `c` is a non-ASCII value (e.g., extended character set or Unicode characters), the function does not account for it.

    Example Usage:

    Suppose we have the following code:

        char ch1 = 'B';
        char ch2 = 'g';
        char ch3 = '7';
        char ch4 = '$';

        printf("%d\n", ft_isalpha(ch1)); // Output: 1 (because 'B' is a letter)
        printf("%d\n", ft_isalpha(ch2)); // Output: 1 (because 'g' is a letter)
        printf("%d\n", ft_isalpha(ch3)); // Output: 0 (because '7' is not a letter)
        printf("%d\n", ft_isalpha(ch4)); // Output: 0 (because '$' is not a letter)

    **Memory representation (ASCII values of input characters):**

    - `'B'` → ASCII `66` (inside the uppercase letter range)
    - `'g'` → ASCII `103` (inside the lowercase letter range)
    - `'7'` → ASCII `55` (outside the letter range)
    - `'$'` → ASCII `36` (outside the letter range)

    The function efficiently determines if a character is a letter and returns the appropriate result.
*/
