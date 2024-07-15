p// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 1950;
int count = 0;

// Hash table
node *table[N];

// Hashes word to a number using djb2 algorithm
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        c = toupper(c); // Ensure the character is uppercase
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *src = fopen(dictionary, "r");
    if (src == NULL)
    {
        printf("Could not open dictionary\n");
        return false;
    }

    // Initialize hash table to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char dword[LENGTH + 1];
    while (fscanf(src, "%s", dword) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(src);
            return false;
        }

        strcpy(new_node->word, dword);
        int index = hash(new_node->word);
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
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    return true;
}
