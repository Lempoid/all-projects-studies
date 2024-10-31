#include <stdio.h> /*printf*/
#include "authentication.h"

#define USER_PASSWORD "1234"
#define USER_NAME "Alex"

int main()
{

    char *user_password = USER_PASSWORD;
    char *user_name = USER_NAME;

    printf("Adding user");
    AddUser(user_name, user_password);
    printf("Adding user");
    AddUser(user_name, user_password);

    /*

    int DeleteUser(struct AuthManager *auth_manager, char *user_name);

    int Authenticate(struct AuthManager *auth_manager, char *user_name, char *password);
    */
    return 0;
}
