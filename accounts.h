#ifndef accounts_H
#define accounts_H
#include "Systeme.h"

void systemMenu();
void userMenu(char name[]);
void adminMenu();
SystemPtr connectionAccount(SystemPtr Sys);
#endif // accounts_H
