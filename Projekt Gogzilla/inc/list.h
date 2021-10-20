#ifndef LIST_H
#define LIST_H

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <wchar.h>

// typedef enum
// {
//     INT,
//     CHAR,
//     WCHAR,
//     STRING,
//     BOOL,

// } t_type;

// typedef struct s_node
// {
//     t_type type;
//     void *data;
//     struct s_list *next;

// } t_node;

typedef struct s_node
{
    wchar_t data;
    struct s_node *next;

} t_node;

t_node *createNode();
t_node *allocateMemoryList();
void initNode(t_node **head_ref);

void printList(t_node **head_ref);

void push(t_node **head_ref, wchar_t new_data);

void pop(t_node **head_ref);

void pop_back(t_node **head_ref);

void append(t_node **head_ref, wchar_t new_data);

void deleteNodeWithKey(t_node **head_ref, wchar_t data);

void deleteNodeAtPosition(t_node **head_ref, int position);

void deleteList(t_node **head_ref);

int listSize(t_node *head);

bool search(t_node *head, wchar_t x, int *index);

#endif
