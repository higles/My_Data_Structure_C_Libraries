/***********************************
 ** List Interface                **
 ** List.h                        **
 ** by HappyPantz Inc             **
 ** written by Joe Higley         **
 ** 10/29/2013                    **
 ***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *command;
    struct node *next;
}typedef node;

void initNode(node* nPtr);

/* Add node to end of list */
void put(node** head, char* cmd);

/* Add node to front of list */
void push(node** head, char* cmd);

/* Add node to middle of list */
void place(node** head, char* str, int n);

/* Deletes from front of list */
void pop(node** head);

/* Deletes from end of list */
void pull(node** head);

/* Deletes the n'th node in a list */
void delNode(node** head, int n);

/* Deletes a single instance of str from the middle of a list */
void delInstance(node** head, char* str);

/* Deletes all instances of str from the list */
void delAllInstances(node** head, char* str);

/* Deletes all nodes in the list */
void clearList(node**head);

/* Returns the first node's string */
char* getFirst(node** head);

/* Returns the last node's string */
char* getLast(node** head);

/* Returns the nth node's string */
char* getNode(node** head, int n);

/* Returns the place where the first instance of str occurrs */
int getPlace(node** head, char* str);

/* Print list in order */
void printList(node* head);

/* Print list in reverse order */
void printReverse(node* nPtr);
