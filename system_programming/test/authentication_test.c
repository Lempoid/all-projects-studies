#include <stdio.h> /*printf*/
#include "authentication.h"
#include <security/pam_appl.h>
#include <security/pam_misc.h>
#define USER_PASSWORD "1234"
#define USER_NAME "Alex"

static struct pam_conv conv =
    {
        misc_conv,
        NULL};

int main(int argc, char *argv[])
{

    /*PAM*/
    pam_handle_t *pamh = NULL;
    int retval;
    const char *user = "nobody";
    if (2 == argc)
    {
        user = argv[1];
    }
    if (2 < argc)
    {
        fprintf(stderr, "Usage: check_user [username]\n");
        return 1;
    }
    
    retval = pam_start("check_user", user, &conv, &pamh);
    if (PAM_SUCCESS == retval)
    {
        retval = pam_authenticate(pamh, 0); /* is user really user? */
    }

    if (PAM_SUCCESS == retval)
    {
        retval = pam_acct_mgmt(pamh, 0); /* permitted access? */
    }

    /* This is where we have been authorized or not. */
    if (PAM_SUCCESS == retval)
    {
        fprintf(stdout, "Authenticated\n");
    }
    else
    {
        fprintf(stdout, "Not Authenticated\n");
    }

    if (PAM_SUCCESS != pam_end(pamh, retval))
    { /* close Linux-PAM */
        pamh = NULL;
        fprintf(stderr, "check_user: failed to release authenticator\n");
        return 1;
    }

    /*NOT PAM*/
    /*
     char *user_password = USER_PASSWORD;
     char *user_name = USER_NAME;

     printf("Adding user");
     AddUser(user_name, user_password);
     printf("Adding user");
     AddUser(user_name, user_password);

     DeleteUser(user_name);

     Authenticate(user_name, "1234");

     */
    return 0;
}
