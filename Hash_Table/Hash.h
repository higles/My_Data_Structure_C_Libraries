/***********************************
 ** Hash Table Interface          **
 ** Hash.h                        **
 ** by HappyPantz Inc.            **
 ** written by Joe Higley         **
 ** 10/29/2013                    **
 ***********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HashEntry{
	int key;
	char *alias;
	char *command;
	struct HashEntry *next;
}typedef HashEntry;

const int TABLE_SIZE = 5;

//initializes hash table main array to NULL
void initTable(HashEntry **table);

//returns the key used to find the hash value
int  findKey(char *str);

//places an item in the hash table
void put(HashEntry **table, char* alias, char* cmd);

//enters info into entry
void place(HashEntry* curr, int key, char* alias, char* cmd);

//prints the hash table (for debugging purposes)
void printHash(HashEntry **table);
