/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:08:08 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 21:52:59 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

/* int main()
{
    ft_putchar_fd('H', 1);
    ft_putchar_fd('e',1);
    ft_putchar_fd('l',1);
    ft_putchar_fd('l',1);
    ft_putchar_fd('o',1);
    ft_putchar_fd('!',1);
    ft_putchar_fd('\n',1);
} */


/*
    This function, `ft_putchar_fd`, is a C implementation designed to write a single character `c`
    to a specified file descriptor `fd`. It ensures that the character is written only if the file descriptor
    is valid (non-negative). This function is typically used when you need to output a single character to a
    specific destination, such as a file or the standard output (stdout).

    The file descriptor `fd` represents a target for output. In most cases:
    
    - `fd = 1` refers to the standard output (stdout), typically used to print to the console.
    - `fd = 2` refers to the standard error (stderr), often used for error messages.
    - `fd = 0` refers to the standard input (stdin), typically used for input operations (though writing to stdin doesn't
       have much practical use).
    - Other values of `fd` represent specific files or devices opened by the program.

    Variables used in `ft_putchar_fd` function:

    - `char c`: This is the character to be written to the file descriptor. It is passed as a parameter and will be written
       exactly as it is, with no modification.
    - `int fd`: This is the file descriptor where the character should be written. If the `fd` is valid (greater than or equal
       to 0), the function proceeds to write the character; otherwise, it does nothing.

    Step-by-step explanation of how the function works:

    1. The function first checks if the file descriptor `fd` is valid by ensuring that it is greater than or equal to 0.
    
       - A file descriptor is considered valid if it points to an open file, standard output, or standard error. Invalid or closed
         file descriptors would have negative values.

    2. If the file descriptor is valid, the function proceeds to use the `write` system call to output the character `c` to the specified
       file descriptor `fd`.
       
       - `write(fd, &c, 1)` writes the character `c` to the output specified by `fd`. The `&c` is the address of `c`, and `1` specifies that
          only one byte (the character) should be written.

    3. If the file descriptor is invalid (negative value), the function simply does nothing. There is no error handling in this case, so the
       function will silently return without performing any action.

    Special Case: File Descriptor `fd = 0` (stdin)

    - The file descriptor `fd = 0` corresponds to **standard input (stdin)**, which is typically used for reading data into a program.
    - In the context of `ft_putchar_fd`, writing to `stdin` does not have a practical effect, since the input stream is designed for reading, not writing.
    - Therefore, calling `ft_putchar_fd('A', 0)` won't cause an error, but it won't produce any visible output either. The behavior would be a no-op (no operation).

    Example Usage:

    Suppose we have the following code:

        ft_putchar_fd('A', 1); // Writes 'A' to the standard output (stdout)

    In this case, the character `'A'` will be written to the standard output (console), as `fd = 1` corresponds to stdout.

    Another example:

        ft_putchar_fd('E', 2); // Writes 'E' to the standard error (stderr)

    In this case, the character `'E'` will be written to the standard error stream (stderr), typically used for error messages.

    Example Output:

    For the following code:

        ft_putchar_fd('b', 1); // Output: b (printed to the console)
        ft_putchar_fd('c', 2); // Output: c (printed to the standard error)
        ft_putchar_fd('d', 0); // No output (written to stdin, which doesn't display anything)

    - The first call to `ft_putchar_fd` writes `'b'` to the standard output (console).
    - The second call writes `'c'` to the standard error stream (stderr).
    - The third call writes `'d'` to the standard input stream (`stdin`), but since `stdin` is not used for output, there will be no visible effect.

    This function is useful for custom output mechanisms when working with files or different streams, providing a low-level way of outputting characters to specified destinations.
*/

