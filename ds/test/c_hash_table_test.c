#include <assert.h>  /*assert*/
#include <stdio.h>   /*printf*/
#include <stdlib.h>  /*strdup*/
#include <string.h>  /*strcmp*/
#include "c_hash_table.h"

#define HASH_SIZE 1000
#define MAX_WORD_LENGTH 100

/*Main is taken from Chananya after mine didn't work and no time to dwell on it more.*/

/*hash function for strings based on the djb2 algorithm (invented by Daniel Bernstein)*/
size_t hash_function(void* key)
{
    size_t hash;

    int c;

    char *str = (char*)key;

    /*initial hash value*/
    hash = 5381;

    /*for each character in the string, it multiplies the current hash by 33
      and adds the ASCII value of that character to update the hash.*/
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  /*essentially hash * 33 + c */

    return hash;
}

int compare_function(const void* key, void* data)
{
    return strcmp((const char*)key, (const char*)data);
}

/*duplicates the string to create a separate copy 
  that can be modified without affecting the original string.*/
char* duplicate_string(const char* original) 
{
    char* copy = malloc(strlen(original) + 1); 

    assert(NULL!= copy);

    strcpy(copy, original);

    return copy; 
}

/*this can be an action_func used with HashForEach in case we want to iterate 
  through the hash table and print all of the words.*/
int print_word(void* data, void* param)
{
    (void)param;
    printf("%s\n", (char*)data);

    return 0;
}

int main()
{
    /*buffer to store each word*/
    char word[MAX_WORD_LENGTH];

    /*creates a hash table with HASH_SIZE buckets, hash_function, and compare_function.*/
    hash_t *dictionary = HashCreate(HASH_SIZE, hash_function, compare_function);

    /*loads the Linux dictionary*/
    FILE *fp = fopen("/usr/share/dict/words", "r");

    if (!dictionary) 
    {
        fprintf(stderr, "Failed to create hash table\n");

        return 1;
    }

    if (!fp) 
    {
        fprintf(stderr, "Failed to open dictionary file\n");

        HashDestroy(dictionary);

        return 1;
    }

    /*reads one line at a time from the file fp into the word buffer, up to 100 characters (MAX_WORD_LENGTH)*/
    while (fgets(word, sizeof(word), fp)) 
    {
        char* word_copy = duplicate_string(word);

        /*removes the newline character that might have been appended to the string by the fgets function
          and replaces it with the null terminator.*/
        word[strcspn(word, "\n")] = 0; 

        /*error handling if insertion fails*/
        if (!HashInsert(word_copy, dictionary, word_copy)) 
        {
            fprintf(stderr, "Failed to insert word: %s\n", word);

            free(word_copy);
        }
    }

    fclose(fp);

    /*prints the number of words loaded into the hash table*/
    printf("Dictionary size: %lu\n", HashSize(dictionary));

    /*simple spell checker*/
    printf("Enter a word to check (or '-1' to exit):\n");

    /*reads user input for the spell checker*/
    while (fgets(word, sizeof(word), stdin)) 
    {
        word[strcspn(word, "\n")] = 0; 
        
        /*exits loop if 'quit' is entered*/
        if (strcmp(word, "-1") == 0) 
        {
            break;
        }

        if (HashFind(dictionary, compare_function, hash_function, word)) 
        {
            printf("'%s' is in the dictionary.\n", word);
        }

        else 
        {
            printf("'%s' is not in the dictionary.\n", word);
        }
          

        printf("Enter another word (or '-1' to exit):\n");
    }

    /*destroys the hash table and frees all allocated memory*/
    HashDestroy(dictionary);
    return 0;
}
