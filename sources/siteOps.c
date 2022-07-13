#include "siteOps.h"
/*fonction aui cree une connexion a un site avec :
  -le nom du site
  -le nom de l'utilisateur
  -le mot de passe du site
*/
Site makeSite(char name[],char username[],char pass[]){
 Site s;
 strcpy(s.name,name);
 strcpy(s.password,pass);
 strcpy(s.username,username);

 return s;
}
//fonction qui genere un mot de passe aleatoire d'une longueur donne
char *genererPass(int size){
 srand(time(0));
 char *pass =malloc(sizeof(char));//allocation dynamique de la chaine de caractere
 //a retourne
 int i=0;
 while(i<size){/*tant que le compteur est inferieure a la taille du mot de passe
la fonction rand() retourne un entier aleatoire
rand()%50 retourne un entier entre 0 et 49
(rand()%50)+64 retourne un entier entre 64 et 113
 (char)(rand()%50)+64 effectue une conversion de type d'entier a caractere
*/
  *(pass+i)=(char)(rand()%58)+65;
  i++;
 }
 return pass;
}
void printSite(Site s){//procedure pour afficher toutes les informations sur un site
  printf("Nom du Site : %s\n",s.name);
  printf("Nom d'Utilisateur : %s\n",s.username);
  printf("Mot de Passe : %s\n",s.password);
}


