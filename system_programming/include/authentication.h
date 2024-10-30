#ifndef __AUTHENTICATION_H__
#define __AUTHENTICATION_H__


/******************************************************************************
 * Add a user to the system.
 * Return 1 for success or 0 for failure.
 * *auth_manager: stores data about authentication system.'
 * *user_name: name the user chooses for himself.
 * *password: password the user chooses.
 * Time Complexity: O(n)
 */

int AddUser(char *user_name, char *password);

/******************************************************************************
 * Delete a user from the system.
 * Return 1 for success or 0 for failure.
 * *auth_manager: stores data about authentication system.'
 * *user_name: name the user chooses for himself.
 * Time Complexity: O(n)
 */

int DeleteUser(char *user_name);
/******************************************************************************
 * Check that a user is in the system.
 * Return 1 for success or 0 for failure.
 * *auth_manager: stores data about authentication system.'
 * *user_name: name the user chooses for himself.
 * *password: password the user chooses.
 * Time Complexity: O(n)
 */

int Authenticate(char *user_name, char *password);

#endif /*__AUTHENTICATION_H__*/