/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:10:23 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/05 16:16:22 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	printf("ft_tolower(%c): %c\n", argv[1][0], ft_tolower(argv[1][0]));
	return (0);
} */

/* 
    This is a recreation of the `ft_tolower` function in C. The purpose of `ft_tolower` is to convert an uppercase letter to its 
    corresponding lowercase letter. If the input character is not an uppercase letter, the function returns it unchanged.

    Function Overview:

    According to the manual: "ft_tolower() converts a given character `c` to its lowercase equivalent if it is an uppercase letter. 
    If `c` is already in lowercase or not an alphabetic character, it returns `c` unchanged."

    The `ft_tolower` function processes the input character and, if it is an uppercase letter, adds 32 to its ASCII value to convert it 
    to lowercase. The function returns the converted character.

    Function Parameters:

    int c: The character to be converted.

    Implementation Breakdown:

    The function works in the following steps:

        1. Check if the Character is Uppercase:
        
            The function checks if the input character `c` is between `'A'` and `'Z'` (inclusive). These are the ASCII values for 
            uppercase English letters.

            if (c >= 'A' && c <= 'Z')

        2. Convert to Lowercase:
        
            If the character `c` is an uppercase letter, the function adds 32 to its ASCII value to convert it to the corresponding 
            lowercase letter. In the ASCII table, the difference between uppercase and lowercase letters is 32.

            c += 32;

        3. Return the Character:

            The function returns the character, either converted to lowercase or unchanged if it was not an uppercase letter.

            return (c);

    Example:

    #include <stdio.h>

    int main(int argc, char **argv)
    {
        if (argc == 2)
        {
            printf("Converted Character: %c\n", ft_tolower(argv[1][0]));
        }
        return (0);
    }

Detailed Step-by-Step Execution:

    Receiving Input:

        The program starts by checking if the number of command-line arguments is 2 (the program name and a single character).
        
            Input: ./program A

    Calling the ft_tolower Function:

        The function ft_tolower is called with the input character A:
        
            result = ft_tolower(argv[1][0])

    Checking if the Character is Uppercase:

        Inside the ft_tolower function, the first thing that happens is the check to see if the input character c is an uppercase letter:
        
            if (c >= 'A' && c <= 'Z')

        Since A is an uppercase letter, the function continues.

    Converting to Lowercase:

        The function then adds 32 to the ASCII value of A to convert it to lowercase:
        
            c += 32 changes A to a.

    Returning the Character:

        The function returns the converted character, which is now a.

Key Takeaways:

    ft_tolower converts an uppercase letter to its lowercase equivalent.
    If the character is already lowercase or not a letter, it remains unchanged.
    The function uses the ASCII value difference between uppercase and lowercase letters to perform the conversion.
    Memory usage is minimal as only a single character is processed.
*/