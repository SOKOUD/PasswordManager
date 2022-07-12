#ifndef user_H
#define user_H
#include "userList.h"

//structure de donnee qui represente un utilisateur
typedef struct User{
 ListPtr l;
 char name[20];
 char password[20];
}User;

User makeUser(char name[],char password[]);
User modifyInfo(User U);


#endif
