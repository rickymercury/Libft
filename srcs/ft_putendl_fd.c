/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:54:07 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/02 22:02:16 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/* int	main()
{
	ft_putendl_fd("hello", 1);
	return (0);
} */


/*
    This function, `ft_putendl_fd`, is a C implementation designed to write a string `s` followed by a newline
    character (`\n`) to a specified file descriptor `fd`. It is commonly used to print strings to different
    output streams, such as the standard output (stdout), standard error (stderr), or a file.

    The file descriptor `fd` represents the destination where the string and the newline should be written.
    In most cases:
	
    - `fd = 1` refers to the standard output (stdout), typically used to print to the console.
    - `fd = 2` refers to the standard error (stderr), often used for error messages.
    - Other values of `fd` represent specific files or devices opened by the program.

    Variables used in `ft_putendl_fd` function:

    - `char *s`: This is the string that should be written to the file descriptor. It is passed as a parameter and
      should be a null-terminated string. The function will write each character of the string individually until it
      encounters the null terminator (`\0`).
    - `int fd`: This is the file descriptor to which the string should be written. If the `fd` is valid (greater than
      or equal to 0), the function will proceed to write the string and a newline character to it.

    Step-by-step explanation of how the function works:

    1. The function begins by initializing a variable `i` to 0. This variable will be used as the index to iterate through
       the string `s`.

    2. The function enters a `while` loop that continues as long as the current character in the string (`s[i]`) is not
       the null terminator (`\0`). This loop iterates through each character of the string and writes it to the specified
       file descriptor using the `write` system call.
	   
       - `write(fd, &s[i], 1)` writes the character `s[i]` to the file descriptor `fd`. The `&s[i]` is the address of
         the character `s[i]`, and `1` specifies that only one byte (the character) should be written.

    3. After all characters of the string have been written, the function writes a newline character (`\n`) to the
       file descriptor using `write(fd, "\n", 1)`. This ensures that the string is followed by a newline.

    4. The function does not return any value. It performs its task of writing the string followed by a newline to the
       specified output stream and then terminates.

    Special Cases:

    - If the string `s` is `NULL`, this function will not work as intended and could lead to undefined behavior.
      It is recommended to ensure that the string passed to `ft_putendl_fd` is not `NULL`.

    Example Usage:

    Suppose we have the following code:

        ft_putendl_fd("Hello, World!", 1);

    In this case, the string `"Hello, World!"` will be written to the standard output (console), followed by a newline.

    This function is useful for printing strings with a trailing newline, such as messages, logs, or errors, to different
    output streams (console, files, etc.).
*/
