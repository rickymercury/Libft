/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:45:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 21:07:04 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int num)
{
	int			len;
	long int	n;

	n = num;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*res;
	long int	num;

	num = n;
	size = count_digits(n);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	res[size--] = '\0';
	while (size >= 0 && num > 0)
	{
		res[size] = (num % 10) + '0';
		size--;
		num = num / 10;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	   return (0);
	printf("str: %s\n", ft_itoa(atoi(argv[1])));
	return (0);
}



/*
    This function, `ft_itoa`, is a C implementation designed to convert a given integer `n` to its string representation. 
    It handles both positive and negative integers, as well as the special case of zero (`0`).
    The function allocates memory dynamically to store the resulting string, ensuring it can hold the integer's digits and
    a potential sign (`'-'`) for negative numbers.

    The `ft_itoa` function works by first determining the number of digits in the integer, then allocating memory for the string
    accordingly. It then converts the integer to a string by extracting its digits, starting from the least significant digit
    to the most significant digit, and stores them in the allocated memory.

    Variables used in `count_digits` function:

    - `int len`: This variable holds the length of the number (i.e., how many digits the number contains).
    - `long int n`: This variable is a copy of the input `num`, but cast to a `long int` to ensure that the number can be handled correctly,
       even for negative values that might not fit into a regular `int` variable.

    Variables used in `ft_itoa` function:

    - `int size`: This stores the total number of digits (including a possible sign) needed to represent the number as a string.
    - `char *res`: This is a pointer to the dynamically allocated memory, which will hold the string representation of the integer.
    - `long int num`: This is a copy of the input integer `n`, cast to `long int` to ensure it can handle large values and negative numbers.

    Step-by-step explanation of how the functions work:

    1. Counting the number of digits (`count_digits` function):
    
       - The function begins by initializing the `len` variable to zero.
       - If the number is `0`, it directly returns `1` since the string "0" only requires one digit.
       - If the number is negative, it changes the number to positive (making it its absolute value) and increments `len` to account for the
         `'-'` sign that will appear in the string representation.
       - Then, the function enters a loop where it repeatedly divides the number by `10` to extract each digit, incrementing `len` for every
         division. The loop stops when the number becomes zero.
       - Finally, the function returns `len`, which is the total number of digits in the number (including the sign for negative numbers).

    2. Converting the number to a string (`ft_itoa` function):
    
       - The `num` variable is initialized with the input integer `n` (cast to `long int`).
       - The `size` variable is set by calling `count_digits(n)`, which returns the total number of digits required to represent the integer in
         a string.
       - Memory is dynamically allocated for `res` with `malloc`. The allocated size is `size + 1` to account for the null terminator (`'\0'`).
       - If the memory allocation fails, the function returns `NULL`.
       - If the number is zero (`num == 0`), the function directly sets the first character of `res` to `'0'` and returns it.
       - If the number is negative, the function assigns a `'-'` to the first character of `res` and changes `num` to its absolute value.
       - The `while` loop then converts the number to a string. Starting from the least significant digit, the function uses the modulo operator
         (`num % 10`) to extract the last digit, converts it to its character representation by adding `'0'`, and places it in the string at the
         correct position.
       - After each digit is extracted, `num` is divided by 10 to remove the last digit, and `size` is decremented to move the position of the next
         digit.
       - The loop continues until all digits are placed in the string.
       - Finally, a null terminator (`'\0'`) is placed at the end of the string to mark the end of the character sequence.

    Example Usage:

    Suppose we have the following code:

        char *str = ft_itoa(-2147483648);
        printf("%s\n", str); // Output: -2147483648

    Step-by-step breakdown:
    
    - `count_digits(-2147483648)` will return `11` because there are 10 digits (`2147483648`) plus the sign (`-`), making a total of 11 digits.
    - Memory is allocated for the string with a size of 12 (`11 + 1` for the null terminator).
    - The string is built by extracting the digits starting from the least significant one:
      - First, it extracts the last digit (`8`), then the next one (`6`), and so on.
    - The negative sign is added at the beginning.
    - The final result is the string `"-2147483648"`.

    This function is commonly used when you need to convert integers to strings, such as when working with formatted outputs, 
    generating string representations of numbers, or creating custom logging or debugging functionality.
*/
