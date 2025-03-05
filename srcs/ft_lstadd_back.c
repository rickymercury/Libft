/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:28:03 by rmedeiro          #+#    #+#             */
/*   Updated: 2025/03/05 19:16:38 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*buffer;

	if (lst == NULL)
		return (NULL);
	buffer = lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	return (buffer);
} */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buffer;

	if (!lst || !new)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
}

/* int main()
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("1");
	t_list *node2 = ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");

	ft_lstadd_back(&list,node1);
	ft_lstadd_back(&list,node2);
	ft_lstadd_back(&list,node3);

	while (list != NULL) 
    {
        printf("%s -> ", (char *)list->content);
        list = list->next;
    }
    printf ("\n");
} */


/*
    This is a recreation of the ft_lstadd_back function in C. The purpose of ft_lstadd_back is to add a new node
    at the end of a linked list. This function is part of the linked list utilities and ensures safe handling of
    memory and pointer manipulation.

    According to the manual: "ft_lstadd_back() adds the node 'new' at the end of the list 'lst'. If 'lst' is NULL,
    it initializes the list with the new node. If 'new' is NULL, the function does nothing."

    Function Overview:

    The ft_lstadd_back function is designed to append a node to the end of a singly linked list. It properly
    handles edge cases such as an empty list and ensures that the list remains correctly linked after the new
    node is appended.

    Function Parameters:

    - t_list **lst: A pointer to a pointer to the first node of the list.
    - t_list *new: A pointer to the new node that will be added to the list.

    Implementation Breakdown:

    1. Check for NULL Pointers:

    The function first checks if either of the input parameters is NULL. If 'lst' or 'new' is NULL, the function
    simply returns without making any modifications. This prevents undefined behavior and protects against
    dereferencing invalid pointers.

    if (!lst || !new)
        return;

    2. Handle the Case of an Empty List:

    If the list is currently empty (i.e., *lst is NULL), the new node becomes the first node in the list.

    if (*lst == NULL)
    {
        *lst = new;
        return;
    }

    This is an important condition because, in a linked list, the first node is referenced by *lst. If *lst is NULL,
    then the list is empty, and we directly assign the new node as the first element.

    3. Traverse the List to Find the Last Node:

    If the list is not empty, the function traverses the list to find the last node (i.e., the node where `next == NULL`).
    It does this using a temporary pointer `buffer`:

    buffer = *lst;
    while (buffer->next != NULL)
        buffer = buffer->next;

    The loop continues moving `buffer` to the next node until it reaches the last node, where `buffer->next == NULL`.

    4. Attach the New Node to the Last Node:

    Once the last node is found, its `next` pointer is updated to point to the new node:

    buffer->next = new;

    This effectively appends the new node to the end of the list.

    Example of Usage:

    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        t_list *list = NULL;
        t_list *node1 = ft_lstnew("Node 1");
        t_list *node2 = ft_lstnew("Node 2");
        t_list *node3 = ft_lstnew("Node 3");

        ft_lstadd_back(&list, node1); // List: Node 1
        ft_lstadd_back(&list, node2); // List: Node 1 -> Node 2
        ft_lstadd_back(&list, node3); // List: Node 1 -> Node 2 -> Node 3

        // Print the list to verify
        t_list *temp = list;
        while (temp)
        {
            printf("%s\n", (char *)temp->content);
            temp = temp->next;
        }
        return 0;
    }

    Step-by-Step Execution:

    1. `list` is initialized to NULL (empty list).
    2. Three nodes are created using `ft_lstnew`, each containing a string.
    3. `ft_lstadd_back(&list, node1)` is called:
    
        - Since `list` is empty, `node1` becomes the first node.
        
    4. `ft_lstadd_back(&list, node2)` is called:
    
        - The function traverses the list to find `node1` (the last node).
        - `node2` is appended to `node1`.
        
    5. `ft_lstadd_back(&list, node3)` is called:
    
        - The function finds `node2` (now the last node) and appends `node3`.
    
    6. The loop prints the list: "Node 1", "Node 2", "Node 3".

    Key Takeaways:

    - `ft_lstadd_back` safely adds a node to the end of a linked list.
    - It correctly handles edge cases such as an empty list.
    - It efficiently traverses the list to find the last node before appending.
    - The function prevents NULL pointer dereferencing.

*/