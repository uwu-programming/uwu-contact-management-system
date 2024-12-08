// include the UI header file
#include "uwuUI.h"
#include "uwuUserLogin.h"
#include "uwuUtility.h"

// main
int main(int argc, char *argv[]){
    // read available users
    readUsersFromFile(USERS_CSV);

    // run the UI uwu
    int status = createGTKAPP(argc, argv);

    return status; // return the status after running createGTKAPP
}