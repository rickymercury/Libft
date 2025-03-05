/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:04:40 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 22:47:25 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

/* int main()
{
    ft_putnbr_fd(-56789, 1);
    printf("\n");
    ft_putnbr_fd(1234, 1);
    printf("\n");
    ft_putnbr_fd(0, 1);
    printf("\n");
    ft_putnbr_fd(-2147483648, 1);
    printf("\n");
    ft_putnbr_fd(2147483647, 1);
    printf("\n");
} */


/*
    This function, `ft_putnbr_fd`, is a C implementation that prints an integer `n` to a specified
    file descriptor `fd`. The function handles both positive and negative integers, as well as the
    special case of the minimum representable integer in a 32-bit signed integer type (`-2147483648`),
    ensuring correct output for all possible integer values.

    File Descriptor (fd):
    
    - The file descriptor `fd` represents the destination where the integer should be printed.
    - Commonly, `fd = 1` is used to print to the standard output (stdout), and `fd = 2` for standard error (stderr).
    - Other values of `fd` may correspond to specific files or devices opened by the program.

    Step-by-step explanation of how the function works:

    1. Handling the special case for the smallest negative integer:
    
       - The function starts by checking if the integer `n` is equal to `-2147483648`, the smallest possible
         value for a signed 32-bit integer. This value cannot be directly converted to a positive integer because
         of integer overflow.
       - If `n` is equal to `-2147483648`, it directly calls `ft_putstr_fd` to print the string `"-2147483648"`.
         This is the only way to safely print this value, since it cannot be converted to its positive counterpart.

    2. Handling negative numbers:
    
       - If `n` is negative but not `-2147483648`, the function proceeds to print the negative sign (`'-'`).
       - It then converts the number to positive by multiplying it by `-1` and recursively calls `ft_putnbr_fd` to
         print the positive counterpart of the number.

    3. Handling positive numbers greater than or equal to 10:
    
       - If `n` is a positive integer greater than or equal to 10, the function performs a recursive process.
       - The function first calls itself with `n / 10`, which reduces the number by one digit. This prints all the digits
         except for the last one.
       - It then calls itself with `n % 10` to print the last digit of the number.

    4. Handling single-digit numbers (0 to 9):
    
       - If `n` is a single-digit number (less than 10), the function prints the character corresponding to the digit
         by adding `'0'` to the integer value (`n + '0'`).

    5. File descriptor writing:
    
       - Each character or string is printed to the specified file descriptor (`fd`) using auxiliary functions such as
         `ft_putchar_fd` (to print individual characters) and `ft_putstr_fd` (to print a string).

    Example Output:

    For the following code:

        ft_putnbr_fd(0, 1);   // Output: 0 (printed to the console)
        ft_putnbr_fd(-2147483648, 1);  // Output: -2147483648 (printed to the console)
        ft_putnbr_fd(12345, 2);  // Output: 12345 (printed to stderr)

    - The first example prints the number `0` to the console.
    - The second example handles the special case of the minimum 32-bit integer value, printing `-2147483648`.
    - The third example prints `12345` to the standard error (stderr).

    Explanation of Recursive Process:

    The recursive nature of `ft_putnbr_fd` ensures that the number is printed in the correct order, even when the
    function breaks the number down into individual digits. Let's take the number `234` as an example to illustrate this:

    1. Initial Call:
    
       - `ft_putnbr_fd(234, fd)` is called first. Since `234 >= 10`, the function calls `ft_putnbr_fd(23, fd)` (this is `n / 10`).
       - This action divides the number into its most significant digits (23), and the function continues to call itself recursively to break it down further.

    2. Recursive Call (First level):
    
       - `ft_putnbr_fd(23, fd)` is called. Since `23 >= 10`, the function calls `ft_putnbr_fd(2, fd)` (this is `n / 10` again).

    3. Recursive Call (Second level):
    
       - `ft_putnbr_fd(2, fd)` is called. Since `2 < 10`, it prints the character `2` (by calling `ft_putchar_fd(2 + '0', fd)`).
       - This ends the deepest recursion because the number is now small enough to be directly printed.

    4. Backtracking and Printing the Remaining Digits:
    
       - After printing `2`, the recursion begins to backtrack. The function prints the remaining digits:
         - The function then prints `3` and `4` by making recursive calls for `234 % 10` (which gives `4`), and `234 / 10` (which gives `3`).
       - The final printed number will be `234`.

    Order of Recursion and Printing:
    
    - The key to understanding the recursion is that the function first calls itself with `n / 10`, which breaks the number down from left to right.
    - The function then prints each digit as it backtracks from the recursion, ensuring that the digits are printed in the correct order.

    Return from Recursion:
    
    - The recursion doesn’t return anything explicitly. Instead, it prints digits at each level and then backtracks to the previous level.
    - Each level of recursion prints its respective digit once the base case (`n < 10`) is reached. The function ultimately returns from the deepest
      level of recursion once all digits have been printed.
    - This "return" from recursion simply means that the function has finished its task for a given level and proceeds to print the next digit.

    Note on Efficiency:
    
    - The function uses recursion to process the digits, which makes it simple and easy to understand but could result in a stack overflow for very
      large integers (though this is highly unlikely for typical use cases, since integer values are limited by the system's memory and the maximum
      depth of the recursion).

    This function is useful for printing integers to different output streams, ensuring correct formatting for both
    negative and positive numbers, as well as handling special cases like `-2147483648`.
*/
