#ifndef user_H
#define user_H
#include "userList.h"

//structure de donnee qui represente un utilisateur
typedef struct User{
 ListPtr l;
 char name[MAX];
 char password[MAX];
}User;

User makeUser(char name[],char password[]);
User modifyInfo(User U);


#endif
