/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:45:17 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/05 15:26:06 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int get_end(const char *s1, const char *set)
{
    ssize_t len;

    len = ft_strlen(s1) - 1;
    while (len >= 0)
    {
        if (!is_in_set(set, s1[len]))
            return (len + 1);
        len--;
    }
    return (0);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in_set(set, s1[i]))
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t  start;
    size_t  end;
    size_t  i;
	char 	*str;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
        return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* int main(int argc, char **argv)
{
	// ft_strtrim: Remove os separadores fornecidos de uma str
	// no seu inicio e final.
	if (argc == 3)
	{
		printf("ft_strtrim: %s\n", ft_strtrim(argv[1], argv[2]));
	}
	return (0);
} */

/* 
$ cc -Wall -Werror -Wextra ft_strtrim.c 
$ ./a.out "\\Hello World\\" "\\"
$ ft_strtrim: Hello World 
*/

/* 
    This is a recreation of the ft_strtrim function in C. The purpose of ft_strtrim is to create a new string by
    trimming characters from the beginning and end of an input string (s1) that belong to a given set of characters
    (set). The function ensures safe handling of memory allocation and returns a new string with the trimmed result.

    Function Overview:

    According to the manual: "ft_strtrim() trims the characters from the beginning and end of the string s1, which are
    present in the set set. It returns a newly allocated string that contains the trimmed version of s1. If memory allocation
    fails or invalid arguments are provided, it returns NULL."

    The ft_strtrim function processes the input string and allocates memory for a new string, which contains only the characters
    from the middle of the original string (after removing those in set from both ends). The original string remains unchanged.

    Function Parameters:

    const char *s1: A pointer to the input string that will be processed.
    const char *set: A pointer to a set of characters that should be removed from both ends of s1.

    Implementation Breakdown:

    The function works in the following steps:

        Check for NULL Pointers:
        
            If either s1 or set is NULL, the function immediately returns NULL to prevent undefined behavior and to handle edge
            cases safely.

            if (!s1 || !set)
                return (NULL);

        Calculate the Start Index (start):

            The get_start function scans through the string s1 from the beginning, searching for the first character that does not belong
            to the set. This index marks the start of the trimmed string.

            start = get_start(s1, set);

        Calculate the End Index (end):

            The get_end function scans through the string s1 from the end, searching for the first character that does not belong to the set.
            This index marks the end of the trimmed string.

            end = get_end(s1, set);

        Handle Edge Cases:

            If start is greater than or equal to end, it indicates that either the string is empty or the entire string consists of characters
            from the set. In such cases, an empty string is returned.

            if (start >= end)
                return (ft_strdup(""));

        Memory Allocation for the Trimmed String:

            The function allocates memory dynamically to store the trimmed string. The size of the allocated memory is end - start + 1 to account
            for the null terminator.

            str = (char *)malloc(sizeof(char) * (end - start + 1));
            if (!str)
                return (NULL);

        Copy the Trimmed Characters:

            The function then copies the characters from s1 between start and end into the newly allocated string str.

            i = 0;
            while (start < end)
            {
                str[i] = s1[start];
                i++;
                start++;
            }

        Null-Terminate the New String:

            After copying the characters, the function ensures the new string is null-terminated.

            str[i] = '\0';

        Return the New String:

            Finally, the function returns the newly allocated string, which contains the trimmed result.

            return (str);

        Handling Edge Cases:

            NULL Input: If either s1 or set is NULL, the function returns NULL to prevent undefined behavior.
            Memory Allocation Failure: If malloc fails, the function returns NULL.
            Empty String: If s1 is empty or consists entirely of characters from set, the function returns an empty string.
            No Trim Needed: If no characters from set are found at the beginning or end of s1, the function will return a copy of s1 without modification.

    Example:

    #include <stdio.h>

    int main(int argc, char **argv)
    {
        char *result;

        if (argc == 3)
        {
            result = ft_strtrim(argv[1], argv[2]);
            if (!result)
            {
            printf("Error: memory allocation failed\n");
            return (1);
        }
        printf("Trimmed String: %s\n", result);
        free(result);
    }
    return (0);
    }

    Detailed Step-by-Step Execution:

    1. Receiving Input

    The program starts by checking if the number of command-line arguments is 3. 
    The first argument (argv[0]) is the program name, the second (argv[1]) is the string to be processed, and the third (argv[2])
    is the set of characters that define what should be removed from the beginning and end of the string.

    Input:  ./program "  hello, world!  " " "

    Here, the argument argv[1] is " hello, world! " (a string with spaces at the beginning and end), and argv[2] is " " (a space character,
    meaning spaces should be removed).

    2. Calling the ft_strtrim Function

    The function ft_strtrim is called with parameters argv[1] (the string " hello, world! ") and argv[2] (the set of characters to be trimmed,
    in this case, just the space " "):

    result = ft_strtrim(argv[1], argv[2]);

    3. Checking for Null Pointers

    Inside the ft_strtrim function, the first thing that happens is the check to see if any of the provided parameters are NULL.

    If either of the parameters is NULL, the function returns NULL immediately to avoid undefined behavior. In this case, both parameters
    are valid, so the function continues.

    4. Calculating the Start Index (First Valid Character)

    The function then calls the get_start function to find the first index in the string s1 that is not in the set set (which, in this case, is
    the space character " "):

    start = get_start(s1, set);

    The get_start function iterates over s1 from the beginning and returns the index of the first character that does not belong to the set set. 
    The function is_in_set is used to check if each character in the string is in the set.

    In our case, the string starts with two spaces, so the function will skip over them and stop when it encounters the first non-space character 
    ("h" at index 2). Thus, the value of start will be 2.

    5. Calculating the End Index (Last Valid Character)

    Next, the function calls get_end to find the index of the last valid character (the last character of s1 that is not in the set set):

    end = get_end(s1, set);

    The get_end function iterates over s1 from the end towards the beginning, looking for the first character that is not in the set set.

    In this case, the string ends with a space, so the function will skip over it and stop when it encounters the first non-space character
    ("!" at index 15). The value of end will be 16 (index 15 + 1 to account for the valid character).
    
    6. Handling Edge Case for Empty String

    After calculating start and end, the function checks whether the resulting string after trimming will be empty (i.e., if the entire string
    consists only of characters from the set or if start is greater than or equal to end):

    if (start >= end)
        return (ft_strdup(""));

    If start >= end, this means the entire string was made up of characters from set or that the start of the string is greater than or equal to the
    end (in case of an empty string), and the function returns a new empty string.

    In this example, start is 2 and end is 16, so the resulting string won't be empty, and the function continues.
    
    7. Allocating Memory for the New String

    The function then allocates memory to store the resulting string. The amount of memory allocated is the size of the substring from start to end, or
    end - start + 1.

    The value of end - start + 1 is 16 - 2 + 1 = 15. So, 15 bytes of memory are allocated to store the new string. If memory allocation fails, the function
    returns NULL.
    
    8. Copying Valid Characters to the New String

    Now, the function begins copying the valid characters from the original string s1 to the new string str. It iterates through s1 from index start to end - 1
    and copies the characters into the new string.

    In this example, the function starts copying the string from index 2 ("h") up to index 15 ("!"). The characters copied are:

    "h"
    "e"
    "l"
    "l"
    "o"
    ","
    " "
    "w"
    "o"
    "r"
    "l"
    "d"
    "!"

    After copying the valid characters, the function adds the null terminator \0 at the end of the string:

    str[i] = '\0';

    Now, the final string in str is "hello, world!".
    
    9. Returning the New String

    Finally, the function returns the new string with the valid characters:

    return (str);

    This results in the following output: Trimmed String: hello, world!

    10. Freeing the Allocated Memory

    Finally, after using the resulting string, the allocated memory is freed to avoid memory leaks: free(result);

    
    Key Takeaways:

    ft_strtrim trims the specified characters from the start and end of a string, returning a new string.
    It handles edge cases such as NULL inputs, memory allocation failure, and fully trimmed strings.
    Memory is dynamically allocated, so the user must free the result string when done.
    The function is efficient and avoids modifying the original string, making it safe for various string manipulation scenarios.
    
*/