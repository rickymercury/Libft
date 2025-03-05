/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:38:34 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:21:59 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isalnum(%c): %i\n", argv[1][0], ft_isalnum(argv[1][0]));
	return (0);
} */

/*
    This is a recreation of the `isalnum` function in C. The purpose of `isalnum` is to check whether a given character 
    is an alphanumeric character, meaning it is either a letter (A-Z, a-z) or a digit (0-9). 

    According to the manual: "The `isalnum` function tests for any character for which `isalpha` or `isdigit` is true. 
    In the standard ASCII character set, this includes uppercase and lowercase letters, as well as digits."

    Function Parameters:

    - `int c` → The character to be checked, passed as an `int`. Even though it's an `int`, it is usually a `char` 
                that has been promoted to `int` when passed as a function argument.

    Understanding the Implementation:

    The function checks whether `c` falls within any of the following ASCII ranges:

    - `'a'` to `'z'` (ASCII values 97 to 122) → This ensures that `c` is a lowercase letter.
    - `'A'` to `'Z'` (ASCII values 65 to 90)  → This ensures that `c` is an uppercase letter.
    - `'0'` to `'9'` (ASCII values 48 to 57)  → This ensures that `c` is a numeric digit.

    If `c` falls into any of these three categories, the function returns `1`, indicating that `c` is alphanumeric.
    Otherwise, it returns `0`.

    Handling Edge Cases:

    - If `c` is a special character (e.g., `@`, `#`, `!`), the function returns `0`.
    - If `c` is a whitespace character (e.g., space, tab, newline), the function returns `0`.
    - If `c` is a non-ASCII value (e.g., characters from extended character sets), the behavior depends on how the function is used.
    - The function does NOT check for accented letters or Unicode characters.

    Example Usage:

    Suppose we have the following code:

        char ch1 = 'A';
        char ch2 = '5';
        char ch3 = '%';

        printf("%d\n", ft_isalnum(ch1)); // Output: 1 (because 'A' is a letter)
        printf("%d\n", ft_isalnum(ch2)); // Output: 1 (because '5' is a digit)
        printf("%d\n", ft_isalnum(ch3)); // Output: 0 (because '%' is not alphanumeric)

    **Memory representation (ASCII values of input characters):**

    - `'A'` → ASCII `65` (inside the range of letters)
    - `'5'` → ASCII `53` (inside the range of digits)
    - `'%'` → ASCII `37` (outside the range of letters and digits)

    The function efficiently determines if a character belongs to the alphanumeric set and returns the appropriate result.
*/
