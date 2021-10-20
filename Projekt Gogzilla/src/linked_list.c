#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/* create new node */
struct node *new_node(int x, int y, struct node *next)
{
    struct node *new = malloc(sizeof *new);
    if (!new) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new->x = x;
    new->y = y;
    new->next = next;
    return new;
}
/* delete last node */
void delete_last(struct node *head)
{
    if (head == NULL) {
        fprintf(stderr, "Error: linked list underflow\n");
        exit(EXIT_FAILURE);
    }
    struct node **cursor = &head;
    while ((*cursor)->next != NULL)
        cursor = &(*cursor)->next;
    *cursor = NULL;
    free(*cursor);
}

/* check if node exists */
bool node_exists(struct node *head, int x, int y)
{
    struct node *cursor = head;
    while (cursor != NULL) {
        if (cursor->x == x && cursor->y == y)
            return true;
        cursor = cursor->next;
    }
    return false;
}
