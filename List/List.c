/***********************************
 ** List Implementation           **
 ** List.c                        **
 ** by HappyPantz Inc             **
 ** written by Joe Higley         **
 ** 10/29/2013                    **
 ***********************************/

#include "List.h"

void initNode(node* nPtr){
    nPtr->command = NULL;
    nPtr->next = NULL;
}

/* Add node to end of list */
void put(node** head, char* cmd){

    if((*head) == NULL){ //empty list
        *head = malloc(sizeof(node));
        (*head)->command = strdup(cmd);
        (*head)->next = NULL;
    }

    else{
        node *curr = *head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = malloc(sizeof(node));
        curr = curr->next;
        curr->command = strdup(cmd);
        curr->next = NULL;
    }
}

/* Add node to front of list */
void push(node** head, char* cmd){
    node *temp = malloc(sizeof(node));
    temp->command = strdup(cmd);
    temp->next = *head;
    *head = temp;
}

/* Add node to middle of list */
void place(node** head, char* str, int n){

    if((*head) == NULL){ // empty list
        printf("List is empty, Placing at beginning\n");
        put(head, str);
        return;
    }

    else{//place in the n'th spot
        node *curr, *prev;
        curr = *head;
        int i;

        for(i=1; i < n; i++){
            if(curr->next == NULL){ //node does not exist
                printf("Place %d does not exist yet.\n"
                       "Placing at end of list.\n", n);
                put(head, str);
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        //adding node
        node *temp = malloc(sizeof(node));
        prev->next = temp;
        temp->command = strdup(str);
        temp->next = curr;
    }
}

/* Deletes from front of list */
void pop(node** head){
    node *temp = *head;
    if(temp != NULL){ // not an empty list
        *head = temp->next;
        temp->next = NULL;
        free(temp);
    }
}

/* Deletes from end of list */
void pull(node** head){

    if((*head) == NULL){ //empty list
        return;
    }

    if((*head)->next == NULL){ //one item in list
        *head = NULL;
        return;
    }

    node *temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next); // delete the node
    temp->next = NULL;
    return;
}

/* Deletes the n'th node in a list */
void delNode(node** head, int n){

    if((*head) == NULL){ //empty list
        printf("List is empty\n");
        return;
    }

    int i;
    node *prev;
    node *curr = *head;
    for(i=1; i < n; i++){ //find the n'th node
        prev = curr;
        curr = curr->next;

        if (curr == NULL){ //n'th node doesn't exist
            printf("The n'th node does not exist");
            return;
        }
    }
    //delete node
    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
}

/* Deletes a single instance of str from the middle of a list */
void delInstance(node** head, char* str){

    if((*head) == NULL){ //empty list
        printf("List is empty\n");
        return;
    }

    if(!strcmp((*head)->command, str)){ //head of list is deleted
        node *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    else{ //check the rest of the list
        node *prev, *curr;
        prev = *head;
        curr = (*head)->next;

        while(curr != NULL){ //search through the list
            /* when a match is found, delete it */
            if(!strcmp(curr->command, str)){
                prev->next = curr->next; //unlink node
                curr->next = NULL;
                free(curr); //delete node
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        /* No instance of str found */
        printf("\nNo instance of \"%s\" was found\n", str);
    }
}

/* Deletes all instances of str from the list */
void delAllInstances(node** head, char* str){
    int count = 0;

    if((*head) == NULL){ //empty list
        printf("List is empty\n");
        return;
    }

    while(!strcmp((*head)->command, str)){ //head of list is deleted
        node *temp = *head;
        *head = temp->next;
        free(temp);
        count++;
    }

    /* Check the rest of the list */
    node *prev, *curr;
    prev = *head;
    curr = (*head)->next;

    while(curr != NULL){ //traverse the list
        /* Find every match and delete it */
        while(curr != NULL && !strcmp(curr->command, str)){
            prev->next = curr->next; //isolate node
            curr->next = NULL;
            free(curr); //delete node
            curr = prev->next; //traverse
            count++;
        }
        if(curr != NULL){ //traverse
            prev = curr;
            curr = curr->next;
        }
    }
    /* Print how many instances were deleted */
    printf("\nDeleted %d instances of \"%s\"\n", count, str);

}

/* Deletes all nodes in the list */
void clearList(node**head){

    if((*head) == NULL){ //empty list
        printf("List is already empty\n");
        return;
    }
    else{
        node *temp;
        /* Traverse list and delete each node */
        while((*head) != NULL){
            temp = *head;
            *head = temp->next; //isolate node
            temp->next = NULL;
            free(temp); //delete node
        }
        /* head should now be equal to NULL */
    }
}

/* Returns the first node's string */
char* getFirst(node** head){
    if((*head) == NULL){ //empty list
        printf("List is empty");
        return NULL;
    }
    else{
        return (*head)->command;
    }
}

/* Returns the last node's string */
char* getLast(node** head){
    if((*head) == NULL){ //empty list
        printf("List is empty");
        return NULL;
    }
    else{
        node *curr = *head;
        /* Traverse list */
        while(curr->next != NULL){
            curr = curr->next;
        }
        return curr->command;
    }
}

/* Returns the nth node's string */
char* getNode(node** head, int n){
    if((*head) == NULL){ //empty list
        printf("List is empty");
        return NULL;
    }
    else{
        int i;
        node *curr = *head;
        /* Traverse list */
        for(i=1; i < n; i++){
            if(curr == NULL){ //nth node does not exist
                printf("List item #%3 does not exist\n", n);
                return NULL;
            }
            else{
                curr = curr->next;
            }
        }
        /* Reached desired node */
        return curr->command;
    }
}

/* Returns the place where the first instance of str occurrs */
int getPlace(node** head, char* str){
    if((*head) == NULL){ //empty list
        printf("List is empty");
        return 0;
    }

    else{
        int i;
        node *curr = *head;
        /* Traverse the list */
        for(i=1; curr != NULL; i++){
            /* If curr is an instance of str, return i */
            if(!strcmp(curr->command, str)){
                return i;
            }
            curr = curr->next;
        }
        /* No instances of str found */
        printf("No instances of \"%s\" were found", str);
        return 0;
    }
}

/* Print list in order */
void printList(node* head){
    node *temp = head;
    while(temp != NULL){
        printf("%s\n", temp->command);
        temp = temp->next;
    }
}

/* Print list in reverse order */
void printReverse(node* nPtr){
    node *temp = nPtr;
    /* Recursively print the list backwards */
    if(temp != NULL){
        printReverse(temp->next);
        printf("%s\n", temp->command);
    }
}
