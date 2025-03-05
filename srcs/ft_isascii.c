/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:25:49 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 18:30:07 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_isascii(%c): %i\n", argv[1][0], ft_isascii(argv[1][0]));
	printf("ft_isascii(200): %i\n", ft_isascii(200));
	return (0);
} */


/*
    This is a recreation of the `isascii` function in C. The purpose of `isascii` is to check whether a given integer 
    corresponds to a valid ASCII character. The ASCII character set consists of 128 characters, ranging from 0 to 127.

    According to the manual: "The `isascii` function tests whether `c` is a 7-bit unsigned char value that fits into the 
    ASCII character set (values between 0 and 127)."

    Function Parameters:

    - `int c` → The value to be checked. Although it's an `int`, it is typically a `char` promoted to `int` when passed as an argument.

    Understanding the Implementation:

    The function checks whether `c` falls within the ASCII range:

    - `0` to `127` → Valid ASCII characters.

    If `c` is within this range, the function returns `1`, indicating that `c` is an ASCII character.
    Otherwise, it returns `0`.

    Handling Edge Cases:

    - If `c` is negative (e.g., `-5`), the function returns `0` because negative values are not valid ASCII characters.
    - If `c` is greater than `127` (e.g., `200`), the function returns `0` because it falls outside the ASCII range.
    - The function does **not** check for extended ASCII values (128-255) used in some character encodings like ISO-8859-1.
    - The function accepts integers beyond the `char` range, but only values within `0-127` return `1`.

    Example Usage:

    Suppose we have the following code:

        printf("%d\n", ft_isascii(65));   // Output: 1 (because 65 is 'A' in ASCII)
        printf("%d\n", ft_isascii(10));   // Output: 1 (because 10 is newline '\n' in ASCII)
        printf("%d\n", ft_isascii(200));  // Output: 0 (because 200 is outside ASCII range)
        printf("%d\n", ft_isascii(-1));   // Output: 0 (negative values are not ASCII)

    **Memory representation (ASCII values of input characters):**

    - `65` → Represents `'A'` in ASCII (valid).
    - `10` → Represents newline (`\n`) in ASCII (valid).
    - `200` → Not an ASCII character (invalid).
    - `-1` → Not an ASCII character (invalid).

    The function efficiently determines whether a given value falls within the standard ASCII range.
*/
