/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:18:38 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/01 16:35:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("ft_atoi: %d\n", ft_atoi(argv[1]));
		printf("atoi: %d\n", atoi(argv[1]));
	}
	return (0);
} */

/* int main()
{
	char atoi_number1[] = "	-4839281 wds";
	char atoi_number2[] = " +4839wds281";

	printf("ft_atoi: %d\n", ft_atoi(atoi_number1));
	printf("original: %d\n\n", atoi(atoi_number1));

	printf("ft_atoi: %d\n", ft_atoi(atoi_number2));
	printf("original: %d\n\n", atoi(atoi_number2));

	return (0);
} */


/*
 	This is a recreation of the atoi function in C. We take a string of characters that are
	supposed to be a number converted into an int.
	According to the man, "The atoi function converts the initial portion of the string point to
	by str to int representation."

	The const char *str parameter means that the function receives a pointer to a string (char *str),
	but the const keyword ensures that the function cannot modify the contents of the string.
	It prevents accidental modification, cause the function should only read str, not modify it.
	Declaring it as const ensures that ft_atoi does not alter the input string.
	Without const, passing a string literal to ft_atoi could cause undefined behavior if the function
	tried to modify it.

    We start off by creating three variables.
	The first is what will hold our result that is to be returned.
	Sign will be what we use to turn the int negative in the event that its a negative number
	that is put in the string. We have it as a long so we can multiply our result by it in the
	We next have an int i, which will be the counter for our string. 
	We will set all of them to 0 except for our sign which we set at 1 to use based on the
	appearance of a negative symbol in our string.

	1- The first thing we want our function to do is make sure to skip over any kind of spacing that
	   could be found at the beginning of the string.
	   The while loop ignores leading whitespace characters in the string.
       
	   - 32 is the ASCII code for a space ' '.
       - The values 9 to 13 correspond to control characters:

            9 → Tab (\t)
            10 → Newline (\n)
            11 → Vertical Tab (\v)
            12 → Form Feed (\f)
            13 → Carriage Return (\r)

	2 - Once past the extra spacing, if it exists, we are checking to see if there is a negative symbol
	    at the beginning of the number we will be converting.
	    If we see a negative symbol or a positive symbol we adjust accordingly. 
	    If it's negative we set our sign equal to -1 to multiply to our result when we return it.

	3 - Therefore, we convert our string of characters from char to int so long as they are numbers. 
	    If the character we are currently on is a number, we converted it to its ascii numerical value. 
	    For the first character result is always set currently at 0. We multiply 10 immediately by our result
	    to set up the digit placement where it should be. We then subtract the numerical value of the 
	    character 0 on the ascii table from our currently character number. This sets it to its ascii numerical
	    value (str[i] - '0' extracts the numerical value from the ASCII character).
		We then start our loop over and continue until we hit a character that is not a number.

		The result is updated by:

        	- Multiplying by 10 to shift the number to the left.
    		- Adding the new digit to the end.

	4- At last we return the result value multiplied by the sign value to return the number based on whether
	   it was negative or not.
	   Multiplies by sign to ensure the number has the correct sign.
	   Returns the converted integer.


	======= Exemple for the number 421337 =======

	result = 0 * 10 + (52 - 48) = 4
	result = 4 * 10 + (50 - 48) = 42
	result = 42 * 10 + (49 - 48) = 421
	result = 421 * 10 + (51 - 48) = 4213
	result = 4213 * 10 + (51 - 48) = 42133
	result = 42133 * 10 + (55 - 48) = 421337

 */