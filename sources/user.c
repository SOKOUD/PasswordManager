#include "user.h"

//fonction qui cree un utilisateur du systeme ayant un mot de passe
User makeUser(char name[],char password[]){
 User U;
 strcpy(U.name,name);
 strcpy(U.password,password);
 return U;
}

//fonction qui modifie les informations d'un utilisateur du systeme
User modifyInfo(User U){
 printf("Entrer le nouveau Nom d'Utilisateur : ");
 scanf("%s",U.name);
 printf("Entrer le mot de passe: ");
 scanf("%s",U.password);

 return U;
}


