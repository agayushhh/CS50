// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1950;
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index;
    index = hash(word);
    for(node *ptr = table[index]; ptr!=NULL;ptr = ptr->next)
    {
        if(strcmp)
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int i=0;
    int sum = 0;
    while(word[i] != '\0')
    {
        sum = sum + toupper(word[i]);
        i++;

    }
    return sum - 'A';

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *src = fopen(dictionary, "r");
    if(src == NULL)
    {
        printf("Could not open dictionary");
        return false;
    }
    char dword[LENGTH + 1];
    int index;
    while(fscanf(src,"%s",dword)!= EOF)
    {
       fscanf(src,"%s",dword);
       node *new_node = malloc(sizeof(node));
       if(new_node == NULL)
       {
        return false;
       }
       strcpy(new_node->word,dword);
       index = hash(new_node->word);
       new_node->next = table[index];
       table[index] = new_node;
       count++;
     }
    fclose(src);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
