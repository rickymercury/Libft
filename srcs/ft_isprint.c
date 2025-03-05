/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:40:20 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 19:44:57 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		printf("ft_isprint('%c'): %i\n", argv[i][0], ft_isprint(argv[i][0]));
	}
	return (0);
} */


/*
    This function, `ft_isprint`, is a C implementation designed to check if a given character `c`
    is a printable character according to the ASCII standard. It returns `1` if the character is
    printable, and `0` if it is not.

    The ASCII printable characters range from the value 32 (space) to 126 (tilde `~`), inclusive.
    Any character outside this range, including control characters such as newline (`\n`), tab (`\t`),
    and other non-printable characters, will result in a return value of `0`.

    According to the ASCII standard:
    
    - Printable characters include all visible characters, such as letters (uppercase and lowercase),
      digits, punctuation marks, and symbols.
    - Non-printable characters include control characters such as carriage return, newline, and tab.

    Function Parameters:

    - `int c`   → The character to be checked. Although it is passed as an `int`, it is typically
                  represented as a `char` when working with single characters. This function checks if
                  the value of `c` is within the range of printable characters (32 to 126).

    The function uses the following logic:

    - If `c` is between 32 and 126 (inclusive), it is considered a printable character, and the function
      returns `1`.
    - If `c` is outside this range, it is not printable, and the function returns `0`.

    Example Usage:

    Suppose we have the following code:

        int result = ft_isprint('A');
        printf("%d\n", result); // Output: 1

    The function returns `1` because `'A'` (ASCII value 65) is within the range of printable characters.

    Another example:

        int result = ft_isprint('\n');
        printf("%d\n", result); // Output: 0

    The function returns `0` because the newline character (`\n`, ASCII value 10) is a non-printable character.

    Example Output:

    For the following code:

        printf("%d\n", ft_isprint('b')); // Output: 1
        printf("%d\n", ft_isprint(' ')); // Output: 1
        printf("%d\n", ft_isprint('\n')); // Output: 0
        printf("%d\n", ft_isprint('\t')); // Output: 0

    - The first two `printf` statements will print `1` because both `'b'` and the space character `' '` are printable.
    - The last two `printf` statements will print `0` because `\n` (newline) and `\t` (tab) are non-printable control characters.

    This function is commonly used for validating whether a character can be displayed on the screen, ensuring
    that only printable characters are processed or displayed in the context of strings and outputs.
*/
