#ifndef Systeme_H
#define Systeme_H
#include "user.h"
#include "fileOp.h"
//structure de donnee qui contient la liste de tous les utilisateurs du systeme
typedef struct Systeme{
 User U;
 char fileName[50];
 struct Systeme *next;
}*SystemPtr,Systeme;


SystemPtr makeSystem(User U);
/*SYSTEM initSystem(SYSTEM head);
SYSTEM ajouterAdmin(SYSTEM head);
SYSTEM searchAdmin(SYSTEM head,char username[],char password[]);*/
SystemPtr addUser(SystemPtr head);
SystemPtr searchUser(SystemPtr head,char username[],char password[]);
SystemPtr modifyUser(SystemPtr curr);
void printInfo(SystemPtr head);
SystemPtr readSys(char name[],SystemPtr head);
void addFileSys(char name[],SystemPtr head);
#endif // Systeme_H
