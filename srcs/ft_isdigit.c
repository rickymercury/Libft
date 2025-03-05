/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:30:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:32:03 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isdigit(%c): %i\n", argv[1][0], ft_isdigit(argv[1][0]));
	return (0);
} */

/*
    This is a recreation of the `isdigit` function in C. The purpose of `isdigit` is to check whether a given character 
    is a numeric digit (0-9).

    According to the manual: "The `isdigit` function tests for a decimal digit character. In the standard ASCII character set, 
    this includes the digits '0' to '9'."

    Function Parameters:

    - `int c` → The character to be checked, passed as an `int`. Although it's an `int`, it is typically a `char` 
                that has been promoted to `int` when passed as an argument.

    Understanding the Implementation:

    The function checks whether `c` falls within the ASCII range:

    - `'0'` to `'9'` (ASCII values 48 to 57) → Ensures `c` is a numeric digit.

    If `c` belongs to this range, the function returns `1`, indicating that `c` is a digit.
    Otherwise, it returns `0`.

    Handling Edge Cases:

    - If `c` is a letter (e.g., `'A'`, `'z'`), the function returns `0`.
    - If `c` is a special character (e.g., `@`, `#`, `!`), the function returns `0`.
    - If `c` is a whitespace character (e.g., space, tab, newline), the function returns `0`.
    - If `c` is a non-ASCII value (e.g., extended character set or Unicode characters), the function does not account for it.

    Example Usage:

    Suppose we have the following code:

        char ch1 = '5';
        char ch2 = 'A';
        char ch3 = ' ';
        char ch4 = '9';

        printf("%d\n", ft_isdigit(ch1)); // Output: 1 (because '5' is a digit)
        printf("%d\n", ft_isdigit(ch2)); // Output: 0 (because 'A' is not a digit)
        printf("%d\n", ft_isdigit(ch3)); // Output: 0 (because space is not a digit)
        printf("%d\n", ft_isdigit(ch4)); // Output: 1 (because '9' is a digit)

    **Memory representation (ASCII values of input characters):**

    - `'5'` → ASCII `53` (inside the digit range)
    - `'A'` → ASCII `65` (outside the digit range)
    - `' '` → ASCII `32` (outside the digit range)
    - `'9'` → ASCII `57` (inside the digit range)

    The function efficiently determines whether a given character is a digit and returns the appropriate result.
*/
