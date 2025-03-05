/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:47:56 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/03 20:19:33 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* int	main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (argv[1] != NULL)
            ft_putstr_fd(argv[1], 1);
    }
    write (1, "\n", 1);

    return (0);
} */


/*
    This function, `ft_putstr_fd`, is a C implementation that writes a string `s` to a specified
    file descriptor `fd`. The function iterates through the string and prints each character 
    one by one using the `write` system call.

    Function Parameters:

    - `char *s`  → A pointer to the string that will be printed.
    - `int fd`   → The file descriptor where the string should be written.
    
      - `fd = 1` → Standard output (stdout).
      - `fd = 2` → Standard error (stderr).
      - Any other value corresponds to a specific file or device opened by the program.

    Understanding the Implementation:

    The function declares the following variables:

    - `int i = 0;` → A counter used as an index to iterate through the string.

    Step-by-step explanation of how the function works:

    1. Loop through the string:
    
       - The function starts with `i = 0` and iterates through the string `s` using a `while` loop.
       - The loop continues as long as `s[i]` is not `'\0'` (the null terminator that marks the end of a string).

    2. Write each character to the file descriptor:
    
       - For every character in `s`, the function calls `write(fd, &s[i], 1);`.
       - `write` is a system call that sends `1` byte (the character `s[i]`) to the given file descriptor `fd`.

    3. Increment `i` to move to the next character:
    
       - After writing each character, `i++` moves to the next character in the string.

    4. Loop continues until reaching the null terminator:
    
       - Once `s[i] == '\0'`, the loop stops, ensuring that only valid characters are written.

    Example Usage:

    Suppose we have the following code:

    #include <unistd.h>

    int main(void)
    {
        ft_putstr_fd("Hello, World!", 1);
        return (0);
    }

    Step 1: Understanding the Arguments

    - `s = "Hello, World!"` → The string to be printed.
    - `fd = 1` → The standard output (console).

    Step 2: Loop Execution and Character-by-Character Writing

    - The function prints each character separately:

        - `write(1, "H", 1);` → Prints `H`
        - `write(1, "e", 1);` → Prints `e`
        - `write(1, "l", 1);` → Prints `l`
        - `write(1, "l", 1);` → Prints `l`
        - `write(1, "o", 1);` → Prints `o`
        - `write(1, ",", 1);` → Prints `,`
        - `write(1, " ", 1);` → Prints a space
        - `write(1, "W", 1);` → Prints `W`
        - `write(1, "o", 1);` → Prints `o`
        - `write(1, "r", 1);` → Prints `r`
        - `write(1, "l", 1);` → Prints `l`
        - `write(1, "d", 1);` → Prints `d`
        - `write(1, "!", 1);` → Prints `!`

    Step 3: Output on the Console**
    
    Hello, World!

    Handling Edge Cases:

    - If `s` is `NULL`, the function may cause undefined behavior. Standard implementations should check for `NULL`
      before dereferencing `s`, but this implementation does not include such a check.
    - If `fd` is invalid (e.g., a closed file descriptor), `write` will fail, but the function does not handle errors explicitly.
    - The function does not add a newline (`'\n'`), so the output remains on the same line unless the string contains `'\n'`.

*/


