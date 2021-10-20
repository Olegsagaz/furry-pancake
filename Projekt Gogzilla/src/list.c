#include "list.h"

t_node *createNode()
{
    t_node *new_node = NULL;
    return new_node;
}

t_node *allocateMemoryList()
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    return new_node;
}

void initNode(t_node **head_ref)
{
    t_node *new_node = allocateMemoryList();
    new_node->data = (wchar_t)malloc(sizeof(wchar_t));
    new_node->next = NULL;
    (*head_ref) = new_node;
}

void printList(t_node **head_ref)
{
    while ((*head_ref) != NULL)
    {
        printf("%lc", (*head_ref)->data);
        (*head_ref) = (*head_ref)->next;
    }
}

void push(t_node **head_ref, wchar_t new_data)
{
    /* 1. allocate node */
    t_node *new_node = allocateMemoryList();

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

void pop(t_node **head_ref)
{
    t_node *temp = (*head_ref);
    if (temp == NULL)
    {
        return;
    }
    else
    {
        temp = temp->next;
    }
    free(*(head_ref));
    (*head_ref) = temp;
}

void pop_back(t_node **head_ref)
{
    if (*head_ref != NULL)
    {

        //1. if head in not null and next of head
        //   is null, release the head
        if ((*head_ref)->next == NULL)
        {
            *head_ref = NULL;
        }
        else
        {

            //2. Else, traverse to the second last
            //   element of the list
            t_node *temp = *head_ref;
            while (temp->next->next != NULL)
                temp = temp->next;

            //3. Change the next of the second
            //   last node to null and delete the
            //   last node
            t_node *lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
        }
    }
}

void append(t_node **head_ref, wchar_t new_data)
{
    /* 1. allocate node */
    t_node *new_node = allocateMemoryList();

    t_node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

void deleteNodeWithKey(t_node **head_ref, wchar_t data)
{
    // Store head node
    t_node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == data)
    {
        *head_ref = temp->next; // Changed head
        free(temp);             // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void deleteNodeAtPosition(t_node **head_ref, int position)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    t_node *temp = *head_ref;

    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next; // Change head
        free(temp);             // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    t_node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next); // Free memory

    temp->next = next; // Unlink the deleted node from list
}

void deleteList(t_node **head_ref)
{

    /* deref head_ref to get the real head */
    t_node *current = *head_ref;
    t_node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}

int listSize(t_node *head)
{
    int count = 0;          // Initialize count
    t_node *current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool search(t_node *head, wchar_t x, int *index)
{
    int temp_index = 0;
    t_node *current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
        {
            *index = temp_index;
            return true;
        }
        current = current->next;
        index++;
    }
    *index = -1;
    return false;
}
