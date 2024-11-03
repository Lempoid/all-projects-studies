/*
A simple straight forward authentication system
Done as a proof of concept.
Best performance wasn't taken into consideration (That's why array and not dictionary was used).

There is a chance I will use a file instead of a dictionary.
*/

#define _XOPEN_SOURCE /* See feature_test_macros(7) */
#include <unistd.h>
#include <stdlib.h> /*FILE*/
#include <stdio.h>  /*printf fprintf*/
#include <crypt.h>  /*crypt*/
#include <string.h> /*strcpy*/
#include <unistd.h> /*lseek*/

#include "authentication.h"

#define FILE_PATH "/home/lempo/git/system_programming/src/secret.txt"
#define USER_READ_WRITE_BUFFER_SIZE 256
#define SALT "$1$ab023"
#define LINE_BUFFER 4096

int AddUser(char *user_name, char *password)
{
    FILE *file = fopen(FILE_PATH, "a+");
    char *encrypted_password;

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
    char buffer[LINE_BUFFER];
    char orignal_line[LINE_BUFFER];
    char *name_to_check;
    FILE *file = fopen(FILE_PATH, "r");
    FILE *new_file = fopen("/home/lempo/git/system_programming/src/new_secret.txt", "w");

    if (NULL == file)
    {
        perror("Can't open authentication file.\n");
        return 0;
    }
    if (NULL == new_file)
    {
        perror("Can't open authentication file.\n");
        fclose(file);
        return 0;
    }

    if (NULL == user_name)
    {
        perror("Wrong username input");
        fclose(file);
        fclose(new_file);

        return 0;
    }

    while (NULL != fgets(buffer, LINE_BUFFER, file))
    {
        strcpy(orignal_line, buffer);
        name_to_check = strtok(buffer, ":");
        if (0 == strcmp(user_name, name_to_check))
        {
            fprintf(new_file, "%s", orignal_line);
        }
    }

    fclose(file);
    fclose(new_file);
    remove(FILE_PATH);
    rename("/home/lempo/git/system_programming/src/new_secret.txt", "/home/lempo/git/system_programming/src/secret.txt");

    return 1;
}

int Authenticate(char *user_name, char *password)
{
    char buffer[LINE_BUFFER];
    FILE *file = fopen(FILE_PATH, "r");
    char *encrypted_password;
    char *user_in_file;
    char *pass_in_file;

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

    while (NULL != fgets(buffer, LINE_BUFFER, file))
    {
        buffer[strcspn(buffer, "\n")] = 0;
        user_in_file = strtok(buffer, ":");

        pass_in_file = strtok(NULL, ":");

        if (0 == strcmp(user_in_file, user_name) && 0 == strcmp(encrypted_password, pass_in_file))
        {
            printf("You are approved\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}