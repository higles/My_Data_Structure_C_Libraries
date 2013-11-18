/***********************************
 ** Hash Table Implementation     **
 ** Hash.c                        **
 ** by HappyPantz Inc.            **
 ** written by Joe Higley         **
 ** 10/29/2013                    **
 ***********************************/

#include <string.h>
#include "Hash.h"

//initializes hash table main array to NULL
void initTable(HashEntry **table){
	int i;
	for(i=0; i < TABLE_SIZE; i++){
	table[i] = NULL;
printf("%d\n", i);
	}
}

//returns the key used to find the hash value
int  findKey(char *str){
    int key = 0;
    while (*str != '\0'){
        key += *str;
        str++;
        if (*str != '\0'){
            key += key/(*str);
            str++;
        }
    }
    return key;
}

//places an item in the hash table
void put(HashEntry** table, char* alias, char* cmd){
    int key = findKey(alias);
	int hash = (key % TABLE_SIZE);
	HashEntry *curr; //keeps track of place in bucket

    //empty bucket
    if (table[hash] == NULL || curr->key == key){
        table[hash] = malloc(sizeof(HashEntry));
        table[hash]->next = NULL;
        place(table[hash], key, alias, cmd);
    }

    else{
        curr = table[hash]; //curr = root of bucket

        //if alias == first bucket items alias, replace
        if (strcmp(curr->alias, alias) == 0){
            place(curr, key, alias, cmd);
        }

        else{
            while (curr->next != NULL){ //while the next place is not taken
                curr = curr->next;
                if (strcmp(curr->alias, alias) == 0){
                    place(curr, key, alias, cmd);
                    return;
                }
            }

            //new alias
            curr->next = malloc(sizeof(HashEntry));
            curr = curr->next;
            curr->next = NULL;
            place(curr, key, alias, cmd);
        }
    }
}

//enters info into entry
void place(HashEntry* curr, int key, char* alias, char* cmd){
    curr->key = key;
    curr->alias = strdup(alias);
    curr->command = strdup(cmd);
}

//prints the hash table (for debugging purposes)
void printHash(HashEntry** table){
	int i;
	HashEntry *listPtr;
	for (i=0; i < TABLE_SIZE; i++){
		if (table[i] != NULL){
			printf("%d: %s  :  %s\n", i, table[i]->alias, table[i]->command);
			listPtr = table[i]->next;
			while(listPtr != NULL){
                printf("   %s  :  %s\n", listPtr->alias, listPtr->command);
                listPtr = listPtr->next;
			}
            printf("\n");
		}
	}
}
