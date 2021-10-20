#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int x;
    int y;
    struct node *next;
};

/* create new node */
struct node *new_node(int x, int y, struct node *next);

/* delete last node */
void delete_last(struct node *head);

/* check if node exists */
bool node_exists(struct node *head, int x, int y);

#endif /* LINKED_LIST_H */
