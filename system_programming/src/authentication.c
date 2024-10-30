/*
A simple straight forward authentication system
Done as a proof of concept.
Best performance wasn't taken into consideration (That's why array and not dictionary was used).

There is a chance I will use a file instead of a dictionary.
*/
#include <stdlib.h> /*FILE*/
#include <stdio.h>  /*printf fprintf*/
#include <crypt.h>  /*crypt*/
#include <string.h> /*strcpy*/
#include <unistd.h> /*lseek*/

#include "authentication.h"

#define FILE_PATH "/home/lempo/git/system_programming/src/secret.txt"
#define USER_READ_WRITE_BUFFER_SIZE 256
#define SALT "$1$ab023"

int AddUser(char *user_name, char *password)
{
    FILE *file = fopen(FILE_PATH, "a+");
    char *encrypted_password;
    char buffer[USER_READ_WRITE_BUFFER_SIZE];

    if (NULL == file)
    {
        perror("Can't open authentication file.\n");
        return 0;
    }

    if (NULL == user_name || NULL == password)
    {
        perror("Wrong username or password input");
        fclose(file);

        return 0;
    }

    encrypted_password = crypt(password, SALT);
    if (NULL == encrypted_password)
    {
        perror("Failed to encrypt password");
        fclose(file);

        return 0;
    }

    fprintf(file, "%s:%s\n", user_name, encrypted_password);

    fclose(file);

    return 1;
}

int DeleteUser(char *user_name)
{
    char buffer[USER_READ_WRITE_BUFFER_SIZE];
    FILE *file = fopen(FILE_PATH, "a+");
    if (NULL == file)
    {
        perror("Can't open authentication file.\n");
        return NULL;
    }

    while (EOF != file)
    {
        fgets(buffer, sizeof(user_name), file);
        if (strtok(buffer)))
    }

    return 1;
}

int Authenticate(char *user_name, char *password)
{

    return 0;
}