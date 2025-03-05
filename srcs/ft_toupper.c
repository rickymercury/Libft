/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:17:39 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/05 16:27:05 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("ft_toupper(%c): %c\n", argv[1][0], ft_toupper(argv[1][0]));
	return (0);
} */

/* 
    This is a recreation of the ft_toupper function in C. The purpose of ft_toupper is to convert a lowercase letter to its corresponding
    uppercase letter. If the input character is not a lowercase letter, the function returns it unchanged.

    According to the manual: "ft_toupper() converts a given character c to its uppercase equivalent if it is a lowercase letter. If c is
    already in uppercase or is not an alphabetic character, it returns c unchanged."

    The ft_toupper function processes the input character and, if it is a lowercase letter, subtracts 32 from its ASCII value to convert it
    to uppercase. The function then returns the converted character.

    Function Parameters

    int c  // The character to be converted.

    Implementation Breakdown:

    The function follows these steps:

        Check if the Character is Lowercase:
        
            The function checks if the input character c is between 'a' and 'z' (inclusive). These are the ASCII values for lowercase English letters.

            if (c >= 'a' && c <= 'z')

        Convert to Uppercase:

            If the character c is a lowercase letter, the function subtracts 32 from its ASCII value to convert it to the corresponding uppercase letter.
        In the ASCII table, the difference between lowercase and uppercase letters is 32.

            c -= 32;

        Return the Character:

        The function returns the character, either converted to uppercase or unchanged if it was not a lowercase letter.

            return (c);

    Example Usage:

    #include <stdio.h>

    int main(int argc, char **argv)
    {
        if (argc == 2)
        {
            printf("Converted Character: %c\n", ft_toupper(argv[1][0]));
        }
        return (0);
    }

    Step-by-Step Execution

        Receiving Input:
    
        The program starts by checking if the number of command-line arguments is 2 (the program name and a single character).
            
            Input: ./program a
    
        Calling the ft_toupper Function:
    
        The function ft_toupper is called with the input character a:

            result = ft_toupper(argv[1][0]);

        Checking if the Character is Lowercase:

        Inside the ft_toupper function, the first check verifies whether c is a lowercase letter:

            if (c >= 'a' && c <= 'z')

        Since 'a' is a lowercase letter, the function proceeds to the next step.

        Converting to Uppercase:

        The function subtracts 32 from the ASCII value of 'a' to convert it to 'A':

            c -= 32;

        Returning the Character:
    
        The function returns 'A'.

        
    Key Takeaways:

    ft_toupper converts a lowercase letter to its uppercase equivalent.
    If the character is already uppercase or not a letter, it remains unchanged.
    The function uses the ASCII value difference between lowercase and uppercase letters to perform the conversion.
    This function is useful when processing text data that needs to be normalized to uppercase.


*/